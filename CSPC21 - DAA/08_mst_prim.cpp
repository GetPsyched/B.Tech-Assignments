#include <iostream>
#include <climits>

class Prim {
    int size, index = 0, **arr, *dist, *parent, *order;
    bool *visited;

public:
    Prim(int source) {
        // Inputting the size
        std::cout << "Input size --> "; std::cin >> size;

        // Initialising the variables
        arr = new int *[size];
        dist = new int[size];
        parent = new int[size];
        order = new int[size];
        visited = new bool [size];

        for(int i=0; i < size; i++) {
            arr[i] = new int[size];
            dist[i] = INT_MAX;
            visited[i] = false;

            // Inputting the graph (2D array)
            std::cout << "Input row " << i << " --> ";
            for(int j=0; j < size; j++)
                std::cin >> arr[i][j];
        }
        dist[source] = 0;
        parent[source] = -1;
    }

    int extractMin() {
        int min = INT_MAX, min_index;
        for(int i=0; i < size; i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        return min_index;
    }

    void prim() {
        int min;
        for(int i=0; i < size - 1; i++) {
            min = extractMin();
            visited[min] = true;

            for(int j=0; j < size; j++)
                if(!visited[j] && arr[min][j] > 0 && dist[j] > arr[min][j]) {
                    dist[j] = arr[min][j];
                    parent[j] = min;
                    order[index++] = j;
                }
        }
    }

    void print() {
        int sum = 0;
        std::cout << "\nEdges in order that they were selected:\nEdge \tWeight";
        for(int i=0; i < size - 1; i++) {
            std::cout << std::endl << parent[order[i]] << " - " << order[i] << "\t" << arr[order[i]][parent[order[i]]];
            sum += arr[order[i]][parent[order[i]]];
        }
        std::cout << std::endl << "Total weight of the MST --> " << sum << std::endl;
    }
};

int main() {
    Prim prim(0);
    prim.prim();
    prim.print();
}
