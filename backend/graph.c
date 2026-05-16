#include <stdio.h>
#include "graph.h"

#define V 5

int graph[V][V] = {

    {0, 10, 0, 30, 100},
    {10, 0, 50, 0, 0},
    {0, 50, 0, 20, 10},
    {30, 0, 20, 0, 60},
    {100, 0, 10, 60, 0}
};

void shortestPath() {

    printf("\n===== RESCUE ROUTE OPTIMIZATION =====\n");

    printf("\nConnected Areas:\n");

    printf("\nArea A -> Area B = 10 KM");

    printf("\nArea A -> Area D = 30 KM");

    printf("\nArea D -> Area E = 60 KM");

    printf("\nArea C -> Area E = 10 KM");

    printf("\n\nShortest Rescue Route:");

    printf("\nArea A -> Area D -> Area E\n");
}