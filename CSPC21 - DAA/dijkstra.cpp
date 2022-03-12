#include <iostream>
#include <climits>

class Dijkstra {
    int size, **arr, *dist;
    bool *visited;

public:
    Dijkstra(int source) {
        // Inputting the size
        std::cout << "Input size --> "; std::cin >> size;

        // Initialising the variables
        arr = new int *[size];
        dist = new int [size];
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

    void dijkstra() {
        int min;
        for(int i=0; i < size - 1; i++) {
            min = extractMin();
            visited[min] = true;

            for(int j=0; j < size; j++)
                if(!visited[j] && arr[min][j] > 0 && dist[j] > dist[min] + arr[min][j])
                    dist[j] = dist[min] + arr[min][j];
        }
    }

    void print() {
        for(int i=0; i < size; i++)
            std::cout << std::endl << i << " --> " << dist[i];
        std::cout << std::endl;
    }
};

int main() {
    Dijkstra dij(0);
    dij.dijkstra();
    dij.print();
}
