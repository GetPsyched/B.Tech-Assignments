/*  Round-Robin scheduling algorithm
 *
 *  Definition:
 *
 *  The name of this algorithm comes from the round-robin principle,
 *  where each person gets an equal share of something in turns.
 *  It is the oldest, simplest scheduling algorithm, which is mostly
 *  used for multitasking.
 *
 *  In Round-robin scheduling, each ready task runs turn by turn only
 *  in a cyclic queue for a limited time slice. This algorithm also
 *  offers starvation free execution of processes.
 *
 *  Points:
 *
 *  - It is a preemptive scheduling algorithm.
 *  - Each process is provided a fix time to execute, it is called a quantum.
 *  - Once a process has executed during the time quantum, it is preempted
 *    and the next process executes for another time quantum
 *  - Context switching is used to save states of preempted processes.
 */

using std::cout, std::cin, std::queue, std::sort;

void
RR() {
    int n;
    Process **processes = get_processes(&n);

    int time_q;
    cout << "Enter the time quantum --> "; cin >> time_q;

    sort(processes, processes + n, compare_arr_time);

    queue<Process*> q;
    q.push(processes[0]);

    int i = 1, now = processes[0]->arrival_time;
    while(!q.empty()) {
        Process *curr_process = q.front();
        q.pop();

        if (curr_process->start_time == -1) {
            curr_process->start_time = now;
            curr_process->wait_time = 0;
        } else {
            curr_process->wait_time += now - curr_process->end_time;
        }

        // Process execution block
        if (curr_process->rem_burst_time - time_q >= 0) {
            now += time_q;
            curr_process->rem_burst_time -= time_q;
        } else {
            now += curr_process->rem_burst_time;
            curr_process->rem_burst_time = 0;
        }
        // Execution completed
        curr_process->end_time = now;
        curr_process->turn_time = now - curr_process->arrival_time;

        // Pushing any other process into the priority queue
        // that has arrived while this process was executing
        for (; i < n && processes[i]->arrival_time <= now; i++)
            q.push(processes[i]);

        // Append the current process to the end of the queue
        // to execute it in the next round
        if (curr_process->rem_burst_time > 0)
            q.push(curr_process);

        // Placeholder check for when no process has arrived and the CPU has to wait
        if (q.empty() && i < n) {
            now = processes[i]->arrival_time;
            q.push(processes[i]);
        }
    }

    put_processes(processes, n);
}
