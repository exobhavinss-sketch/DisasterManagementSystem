#include <stdio.h>
#include <string.h>
#include "queue.h"

#define MAX 100

struct Victim {

    int id;

    char name[50];
};

struct Victim queue[MAX];

int front = -1;

int rear = -1;

void enqueue() {

    if(rear == MAX - 1) {

        printf("\nQueue Overflow\n");

        return;
    }

    if(front == -1) {

        front = 0;
    }

    rear++;

    printf("\nEnter Victim ID: ");

    scanf("%d", &queue[rear].id);

    printf("Enter Victim Name: ");

    scanf("%s", queue[rear].name);

    printf("\nVictim Added To Queue Successfully!\n");
}

void dequeue() {

    if(front == -1 || front > rear) {

        printf("\nQueue Underflow\n");

        return;
    }

    printf("\nResource Distributed To: %s\n",
           queue[front].name);

    front++;
}

void displayQueue() {

    if(front == -1 || front > rear) {

        printf("\nQueue Is Empty\n");

        return;
    }

    int i;

    for(i = front; i <= rear; i++) {

        printf("\n------------------");

        printf("\nID: %d", queue[i].id);

        printf("\nVictim: %s", queue[i].name);

        printf("\n------------------\n");
    }
}

void queueMenu() {

    int choice;

    while(1) {

        printf("\n===== RESOURCE DISTRIBUTION QUEUE =====");

        printf("\n1. Add Victim");

        printf("\n2. Distribute Resource");

        printf("\n3. Display Queue");

        printf("\n4. Back");

        printf("\n\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                enqueue();

                break;

            case 2:

                dequeue();

                break;

            case 3:

                displayQueue();

                break;

            case 4:

                return;

            default:

                printf("\nInvalid Choice\n");
        }
    }
}