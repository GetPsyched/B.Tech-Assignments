/*  FCFS scheduling algorithm
 *
 *  Definition:
 *
 *  First Come, First Served (FCFS) also known as First In, First Out(FIFO)
 *  is the CPU scheduling algorithm in which the CPU is allocated to the
 *  processes in the order they are queued in the ready queue.
 *
 *  FCFS follows non-preemptive scheduling which mean once the CPU is allocated
 *  to a process it does not leave the CPU until the process will not get
 *  terminated or may get halted due to some I/O interrupt.
 *
 *  Points:
 *
 *  - Jobs are executed on first come, first serve basis.
 *  - It is a non-preemptive scheduling algorithm.
 *  - Its implementation is based on FIFO queue.
 *  - Poor in performance as average wait time is high.
 */

void
FCFS() {
    int n;
    Process **processes = get_processes(&n);

    // Sort the array of processes wrt. their arrival times
    std::sort(processes, processes + n, compare_arr_time);

    int now = processes[0]->arrival_time;
    for (int i = 0; i < n; i++) {
        // If the process has not arrived yet, skip to that time
        if (processes[i]->arrival_time > now)
            now = processes[i]->arrival_time;

        processes[i]->wait_time = now - processes[i]->arrival_time;
        processes[i]->start_time = now;
        processes[i]->end_time = now + processes[i]->burst_time;

        // Two ways of getting turn around time
        processes[i]->turn_time = processes[i]->end_time - processes[i]->arrival_time;
        processes[i]->turn_time = processes[i]->wait_time + processes[i]->burst_time;

        now = processes[i]->end_time;
    }

    put_processes(processes, n);
}
