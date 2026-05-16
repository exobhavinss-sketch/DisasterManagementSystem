#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Team {

    int id;

    char name[50];

    struct Team *left;

    struct Team *right;
};

struct Team* createTeam(int id, char name[]) {

    struct Team *newNode;

    newNode = (struct Team*)malloc(sizeof(struct Team));

    newNode->id = id;

    strcpy(newNode->name, name);

    newNode->left = NULL;

    newNode->right = NULL;

    return newNode;
}

void displayHierarchy(struct Team *root) {

    if(root == NULL) {

        return;
    }

    printf("\nTeam ID: %d", root->id);

    printf("\nTeam Name: %s\n", root->name);

    displayHierarchy(root->left);

    displayHierarchy(root->right);
}

void teamMenu() {

    struct Team *root;

    root = createTeam(1, "NationalTeam");

    root->left = createTeam(2, "StateTeam");

    root->right = createTeam(3, "DistrictTeam");

    printf("\n===== RESCUE TEAM HIERARCHY =====\n");

    displayHierarchy(root);
}