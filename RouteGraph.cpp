
#include "RouteGraph.h"

void RouteGraph::addRoute(string from, string to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void RouteGraph::displayRoutes() {
    for(auto node : graph) {
        cout << node.first << " -> ";

        for(auto edge : node.second) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }

        cout << endl;
    }
}

map<string, vector<pair<string, int>>>& RouteGraph::getAdjList() {
    return graph;
}
