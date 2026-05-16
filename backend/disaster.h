#ifndef DISASTER_H
#define DISASTER_H

struct Disaster {

    int id;

    char type[50];

    char location[50];

    int severity;

    struct Disaster *next;
};

void addDisaster();

void displayDisasters();

void searchDisaster(); 

void deleteDisaster();

void updateDisaster();

#endif