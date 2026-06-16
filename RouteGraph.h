
#ifndef ROUTEGRAPH_H
#define ROUTEGRAPH_H

#include <map>
#include <vector>
#include <iostream>
using namespace std;

class RouteGraph {
public:
    map<string, vector<pair<string, int>>> graph;
    map<string, vector<pair<string,int>>>&
getAdjList();

    void addRoute(string from, string to, int weight);
    void displayRoutes();
};

#endif
