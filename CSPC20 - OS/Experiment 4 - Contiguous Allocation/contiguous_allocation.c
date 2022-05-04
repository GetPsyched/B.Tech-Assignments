#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int size;
    int occupied;
    int free;
} memory_block;

int
best_fit(memory_block *blocks, int n, int pcb_size) {
    int best_size = INT_MAX, block = -1;
    for (int i = 0; i < n; i++)
        if (blocks[i].free >= pcb_size && blocks[i].free < best_size) {
            best_size = blocks[i].free;
            block = i + 1;
        }
    return block;
}

int
worst_fit(memory_block *blocks, int n, int pcb_size) {
    int worst_size = INT_MIN, block = -1;
    for (int i = 0; i < n; i++)
        if (blocks[i].free >= pcb_size && blocks[i].free > worst_size) {
            worst_size = blocks[i].free;
            block = i + 1;
        }
    return block;
}

int
first_fit(memory_block *blocks, int n, int pcb_size) {
    for (int i = 0; i < n; i++)
        if (blocks[i].free >= pcb_size)
            return i + 1;
    return -1;
}

void
main() {
    int n;
    printf("Enter the number of blocks in memory --> ");
    scanf(" %d", &n);

    memory_block *blocks = malloc(n * sizeof(memory_block));
    for (int i = 0; i < n; i++) {
        printf("Enter the size of block #%d --> ", i + 1);
        scanf("%d", &blocks[i].size);

        printf("Enter the amount occupied of block #%d --> ", i + 1);
        scanf("%d", &blocks[i].occupied);

        if (blocks[i].size < blocks[i].occupied) {
            printf("Number of bytes occupied cannot be higher than the size of the block!\nExiting...\n");
            exit(1);
        }

        blocks[i].free = blocks[i].size - blocks[i].occupied;
    }

    char add_more;
    do {
        int pcb_size, block;
        printf("Enter the size of the PCB --> ");
        scanf("%d", &pcb_size);

        int choice;
        printf("\n1. Best fit\n2. First fit\n3. Worst fit\nEnter your choice --> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: block = best_fit(blocks, n, pcb_size); break;
            case 2: block = worst_fit(blocks, n, pcb_size); break;
            case 3: block = first_fit(blocks, n, pcb_size); break;
            default: printf("Invalid choice!");
        }

        if (block == -1)
            printf("This PCB cannot be added to any memory block as not enough space is available due to external fragmentation");
        else {
            printf("PCB inserted to block #%d", block);
            blocks[block - 1]. free -= pcb_size;
            blocks[block - 1]. occupied += pcb_size;
        }

        printf("\nDo you wish to add another PCB? (y/n) --> ");
        scanf("%c", &add_more);
    } while (add_more == 'y');
    printf("\n");
}
