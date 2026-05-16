#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "disaster.h"
#include "stack.h"
#include "tree.h"
#include "graph.h"
#include "queue.h"
void login() {

    char username[50];

    char password[50];

    printf("\n========== LOGIN SYSTEM ==========\n");

    printf("\nEnter Username: ");

    scanf("%s", username);

    printf("Enter Password: ");

    scanf("%s", password);

    if(strcmp(username, "admin") == 0 &&
       strcmp(password, "1234") == 0) {

        printf("\nLogin Successful!\n");
    }

    else {

        printf("\nInvalid Username Or Password\n");

        exit(0);
    }
}
int main() {

    login();

    system("color 0B");

    int choice;

    while(1) {
        
        printf("\n========================================");

        printf("\n   DISASTER MANAGEMENT SYSTEM");

        printf("\n   Data Structures Using C Project");

        printf("\n========================================\n");

        printf("\n1. Add Disaster Report");

        printf("\n2. Display Reports");

        printf("\n3. Search Disaster");

        printf("\n4. Delete Disaster");

        printf("\n5. Update Disaster");

        printf("\n6. Emergency Requests");

        printf("\n7. Rescue Team Hierarchy");

        printf("\n8. Rescue Route Optimization");

        printf("\n9. Resource Distribution Queue");

        printf("\n10. Exit");

        printf("\n\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                addDisaster();

                break;

            case 2:

                displayDisasters();

                break;

            case 3:

                searchDisaster();

                break;

            case 4:

                deleteDisaster();

                break;

            case 5:

                updateDisaster();

                break;

            case 6:

                stackMenu();

                break;

            case 7:

                teamMenu();

                break;

            case 8:

                shortestPath();

                break;

            case 9:

                queueMenu();

                break;

            case 10:

                exit(0);

            default:

                printf("\nInvalid Choice\n");
}
    }

    return 0;
}