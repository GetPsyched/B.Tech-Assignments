/*  SJF scheduling algorithm
 *
 *  Points:
 *
 *  - This is a non-preemptive, pre-emptive scheduling algorithm.
 *  - Best approach to minimize waiting time.
 *  - Easy to implement in Batch systems where required CPU time is known in advance.
 *  - Impossible to implement in interactive systems where required CPU time is not known.
 *  - The processer should know in advance how much time process will take.
 *
 *  Non pre-emptive approach:
 *      A newly arriving job will be appended to the end of the queue even
 *      if its burst time is lesser than one/many of the other jobs.
 *
 *  Pre-emptive approach:
 *      A newly arriving job will be inserted into the queue behind
 *      any job that takes lesser time than it and in front of any
 *      job that takes more time than it.
 */

using std::max, std::min, std::priority_queue, std::sort, std::vector;

struct compare_sjf_process {
    bool operator() (Process *p1, Process *p2) {
        return p1->burst_time > p2->burst_time;
    }
};

struct compare_srtf_process {
    bool operator() (Process *p1, Process *p2) {
        return p1->rem_burst_time > p2->rem_burst_time;
    }
};

void
SJF() {
    int n;
    Process **processes = get_processes(&n);
    Process *temp_p[n];

    // Sort the array of processes wrt. their arrival and burst times
    sort(processes, processes + n, compare_arr_time);

    // Implementing a priority queue to self sort on the basis of burst times
    // NOTE: This priority queue will store all the processes but those who have not yet arrived
    priority_queue<Process*, vector<Process*>, compare_sjf_process> pq;

    // Pushing the first process into the priority queue since it has no wait time
    pq.push(processes[0]);
    temp_p[0] = processes[0];

    int i = 1, j = 1, now = processes[0]->arrival_time;
    while (!pq.empty()) {
        Process* curr_process = pq.top();
        pq.pop();

        curr_process->start_time = now;
        curr_process->wait_time = now - curr_process->arrival_time;
        now += curr_process->burst_time;  // Skip to when the process has finished execution
        curr_process->turn_time = now - curr_process->arrival_time;
        curr_process->end_time = now;
        temp_p[i++] = curr_process;

        // Pushing any other process into the priority queue
        // that has arrived while this process was executing
        for (; j < n && processes[j]->arrival_time <= now; j++)
            pq.push(processes[j]);

        // Placeholder check for when no process has arrived and the CPU has to wait
        if (pq.empty() && j < n) {
            now = processes[j]->arrival_time;
            pq.push(processes[j]);
        }
    }

    put_processes(temp_p, n);
}

void
SRTF() {
    int n;
    Process **processes = get_processes(&n);
    Process *temp_p[n];

    // Sort the array of processes wrt. their arrival and burst times
    sort(processes, processes + n, compare_arr_time);

    // Implementing a priority queue to self sort on the basis of burst times
    // NOTE: This priority queue will store all the processes but those who have not yet arrived
    priority_queue<Process*, vector<Process*>, compare_srtf_process> pq;

    // Pushing the first process into the priority queue since it has no wait time
    pq.push(processes[0]);
    temp_p[0] = processes[0];

    int i = 1, j = 1, now = processes[0]->arrival_time;
    while (!pq.empty()) {
        Process *curr_process = pq.top();
        pq.pop();

        if (curr_process->start_time == -1) {
            curr_process->start_time = now;
            curr_process->wait_time = now - curr_process->arrival_time;
        } else {
            curr_process->wait_time += now - curr_process->end_time;
        }

        now += min(1, curr_process->rem_burst_time);
        curr_process->rem_burst_time = max(0, curr_process->rem_burst_time - 1);
        if (curr_process->rem_burst_time > 0)
            pq.push(curr_process);
        curr_process->end_time = now;
        curr_process->turn_time = now - curr_process->arrival_time;

        if (temp_p[i - 1] != curr_process)
            temp_p[i++] = curr_process;

        // Pushing any other process into the priority queue
        // that has arrived while this process was executing
        for (; j < n && processes[j]->arrival_time <= now; j++)
            pq.push(processes[j]);

        // Placeholder check for when no process has arrived and the CPU has to wait
        if (pq.empty() && j < n) {
            now = processes[j]->arrival_time;
            pq.push(processes[j]);
        }
    }

    put_processes(temp_p, n);
}
