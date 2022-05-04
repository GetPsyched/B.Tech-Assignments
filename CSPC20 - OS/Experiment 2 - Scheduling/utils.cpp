// A utility file to get inputs of processes for
// the various scheduling algorithms in this course

using std::cout, std::cin, std::endl, std::setw;

class Process {
public:
    int id;
    int arrival_time;

    int burst_time, rem_burst_time;
    int start_time, end_time;

    int turn_time, wait_time;

    double priority;

    Process() {}

    Process(int id, int arrival_time, int burst_time) {
        this->id = id;
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;

        this->wait_time = 0;
        this->turn_time = -1;
        this->start_time = -1;
        this->end_time = -1;

        this->rem_burst_time = burst_time;
    }
};


bool
compare_arr_time(Process *p1, Process *p2) {
    if (p1->arrival_time != p2->arrival_time)
        return p1->arrival_time < p2->arrival_time;
    return p1->burst_time < p2->burst_time;
}

// O(n) function to check if a process already exists in a processes array
bool
process_exists(
    int pid,
    Process **processes,
    int n
) {
    for (int i = 0; i < n; i++)
        if (pid == processes[i]->id)
            return true;
    return false;
}

// Input and return a processes array
Process
**get_processes(int *n, const char *algorithm = "") {
    cout << "Enter the number of processes you would like to input --> ";
    cin >> *n;

    int pid, arrival_time, burst_time;
    Process **processes = new Process*[*n];
    for (int i = 0; i < *n; i++) {
        cout << "\nProcess #" << i + 1 << ":\n";

        cout << "Enter the id --> "; cin >> pid;
        if (process_exists(pid, processes, i)) {
            cout << "A process with this id already exists! Exiting...\n";
            exit(1);
        }
        cout << "Enter the arrival time --> "; cin >> arrival_time;
        cout << "Enter the burst time --> "; cin >> burst_time;

        processes[i] = new Process(pid, arrival_time, burst_time);
        if (algorithm == "priority") {
            cout << "Enter the priority --> ";
            cin >> processes[i]->priority;
        }
    }
    return processes;
}

void
put_processes(Process **processes, int n) {
    int tot_turn_time = 0, tot_wait_time = 0;

    cout << "\nOutput:\n";
    cout << setw(12) << "ID";
    cout << setw(12) << "Arrival";
    cout << setw(12) << "Burst";
    cout << setw(12) << "Wait";
    cout << setw(12) << "Start";
    cout << setw(12) << "End";
    cout << setw(12) << "Turn-around";
    cout << endl;
    for (int i = 0; i < n; i++) {
        tot_turn_time += processes[i]->turn_time;
        tot_wait_time += processes[i]->wait_time;

        cout << setw(12) << processes[i]->id;
        cout << setw(12) << processes[i]->arrival_time;
        cout << setw(12) << processes[i]->burst_time;
        cout << setw(12) << processes[i]->wait_time;
        cout << setw(12) << processes[i]->start_time;
        cout << setw(12) << processes[i]->end_time;
        cout << setw(12) << processes[i]->turn_time;
        cout << endl;
    }
    printf("\nThroughput --> %.2f", (float)n / (float)tot_turn_time);
    printf("\nAverage turn-around time --> %.2f", (float)tot_turn_time / (float)n);
    printf("\nAverage wait time --> %.2f\n", (float)tot_wait_time / (float)n);
}
