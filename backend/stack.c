#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX 100

struct Request {

    int id;

    char name[50];
};

struct Request stack[MAX];

int top = -1;

void pushRequest() {

    if(top == MAX - 1) {

        printf("\nStack Overflow\n");

        return;
    }

    top++;

    printf("\nEnter Request ID: ");

    scanf("%d", &stack[top].id);

    printf("Enter Victim Name: ");

    scanf("%s", stack[top].name);

    printf("\nEmergency Request Added Successfully!\n");
}

void popRequest() {

    if(top == -1) {

        printf("\nNo Pending Requests\n");

        return;
    }

    printf("\nResolved Request: %s\n", stack[top].name);

    top--;
}

void displayRequests() {

    if(top == -1) {

        printf("\nNo Requests Available\n");

        return;
    }

    int i;

    for(i = top; i >= 0; i--) {

        printf("\n------------------");

        printf("\nID: %d", stack[i].id);

        printf("\nVictim: %s", stack[i].name);

        printf("\n------------------\n");
    }
}

void stackMenu() {

    int choice;

    while(1) {

        printf("\n===== EMERGENCY REQUEST SYSTEM =====");

        printf("\n1. Add Request");

        printf("\n2. Resolve Latest Request");

        printf("\n3. Display Requests");

        printf("\n4. Back");

        printf("\n\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                pushRequest();

                break;

            case 2:

                popRequest();

                break;

            case 3:

                displayRequests();

                break;

            case 4:

                return;

            default:

                printf("\nInvalid Choice\n");
        }
    }
}