#include <iostream>
#include <zookeeper/zookeeper.h>
#include "leader.h"

// konstruktor
Leader::Leader(string nodes, string edges) : graph(nodes, edges) {
    std::cout << "Initialized leader\n";
}

void Leader::start_eb_cluster(zhandle_t *zh) {
    char start_msg[] = "start";
    int r = zoo_set(zh, "/eb", start_msg, sizeof(start_msg), -1);
    if (r != ZOK) {
        cout << "ERROR (" << r << "): couldn't set /eb to start\n";
        exit(1);
    }
}

void Leader::start_mod_cluster(zhandle_t *zh) {
    char start_msg[] = "start";
    int r = zoo_set(zh, "/mod", start_msg, sizeof(start_msg), -1);
    if (r != ZOK) {
        cout << "ERROR (" << r << "): couldn't set /mod to start\n";
        exit(1);
    }
}

void Leader::find_central_edge() {
    /*
    * this function gets the most central edge (edge with
    * highest value of edge betweenness) in a graph by communicating
    * with the edge betweenness cluster
    */
    return;
}

void Leader::calculate_modularity() {
    /*
    * this function gets value of modularity for a graph
    * by communicating with the modularity cluster
    */
    return;
}

