/* For the Priority scheduling algorithm,
 *
 *  We prefer to compute the CPU burst rather than manually entering it.
 *  Priority may be assigned on the basis of their CPU burst or some other parameter.
 *  Priority (pre-emption) and priority (non pre-emption) nature of priority scheduling is performed.
 */

struct compare_priority_process {
    bool operator() (Process *p1, Process *p2) {
        return p1->priority > p2->priority;
    }
};

void
Priority() {
    int n;
    Process **processes = get_processes(&n, "priority");
    Process *temp_p[n];

    // Sort the array of processes wrt. their arrival and burst times
    sort(processes, processes + n, compare_arr_time);

    // Implementing a priority queue to self sort on the basis of burst times
    // NOTE: This priority queue will store all the processes but those who have not yet arrived
    priority_queue<Process*, vector<Process*>, compare_priority_process> pq;

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
PriorityPreEmptive() {
    int n;
    Process **processes = get_processes(&n, "priority");
    Process *temp_p[n];

    // Sort the array of processes wrt. their arrival and burst times
    sort(processes, processes + n, compare_arr_time);

    // Implementing a priority queue to self sort on the basis of burst times
    // NOTE: This priority queue will store all the processes but those who have not yet arrived
    priority_queue<Process*, vector<Process*>, compare_priority_process> pq;

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
