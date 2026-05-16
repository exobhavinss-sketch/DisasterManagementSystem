#include <stdio.h>
#include <stdlib.h>
#include "disaster.h"

FILE *fp;

struct Disaster *head = NULL;

void addDisaster() {

    struct Disaster *newNode;

    newNode = (struct Disaster*)malloc(sizeof(struct Disaster));

    printf("\nEnter Disaster ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Disaster Type: ");
    scanf("%s", newNode->type);

    printf("Enter Location: ");
    scanf("%s", newNode->location);

    printf("Enter Severity Level: ");
    scanf("%d", &newNode->severity);

    newNode->next = NULL;

    if(head == NULL) {

        head = newNode;
    }

    else {

        struct Disaster *temp = head;

        while(temp->next != NULL) {

            temp = temp->next;
        }

        temp->next = newNode;
    }

    fp = fopen("../data/reports.txt", "a");

    fprintf(fp,
            "ID: %d | Type: %s | Location: %s | Severity: %d\n",
            newNode->id,
            newNode->type,
            newNode->location,
            newNode->severity);

    fclose(fp);

    printf("\nDisaster Report Added Successfully!\n");
}

void displayDisasters() {

    struct Disaster *temp = head;

    if(head == NULL) {

        printf("\nNo Reports Available\n");

        return;
    }

    while(temp != NULL) {

        printf("\n---------------------");

        printf("\nID: %d", temp->id);

        printf("\nType: %s", temp->type);

        printf("\nLocation: %s", temp->location);

        printf("\nSeverity: %d", temp->severity);

        printf("\n---------------------\n");

        temp = temp->next;
    }
}

void searchDisaster() {

    int id;

    int found = 0;

    struct Disaster *temp = head;

    printf("\nEnter Disaster ID To Search: ");

    scanf("%d", &id);

    while(temp != NULL) {

        if(temp->id == id) {

            printf("\n===== DISASTER FOUND =====");

            printf("\nID: %d", temp->id);

            printf("\nType: %s", temp->type);

            printf("\nLocation: %s", temp->location);

            printf("\nSeverity: %d\n", temp->severity);

            found = 1;

            break;
        }

        temp = temp->next;
    }

    if(found == 0) {

        printf("\nDisaster Report Not Found\n");
    }
}

void deleteDisaster() {

    int id;

    int found = 0;

    struct Disaster *temp = head;

    struct Disaster *prev = NULL;

    printf("\nEnter Disaster ID To Delete: ");

    scanf("%d", &id);

    while(temp != NULL) {

        if(temp->id == id) {

            found = 1;

            if(prev == NULL) {

                head = temp->next;
            }

            else {

                prev->next = temp->next;
            }

            free(temp);

            printf("\nDisaster Report Deleted Successfully!\n");

            break;
        }

        prev = temp;

        temp = temp->next;
    }

    if(found == 0) {

        printf("\nDisaster Report Not Found\n");
    }
}
void updateDisaster() {

    int id;

    int found = 0;

    struct Disaster *temp = head;

    printf("\nEnter Disaster ID To Update: ");

    scanf("%d", &id);

    while(temp != NULL) {

        if(temp->id == id) {

            found = 1;

            printf("\nEnter New Disaster Type: ");

            scanf("%s", temp->type);

            printf("Enter New Location: ");

            scanf("%s", temp->location);

            printf("Enter New Severity: ");

            scanf("%d", &temp->severity);

            printf("\nDisaster Report Updated Successfully!\n");

            break;
        }

        temp = temp->next;
    }

    if(found == 0) {

        printf("\nDisaster Report Not Found\n");
    }
}