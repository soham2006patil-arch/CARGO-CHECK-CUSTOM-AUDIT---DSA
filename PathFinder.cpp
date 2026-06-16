#include "PathFinder.h"

#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

PathFinder::PathFinder(RouteGraph &g)
    : graph(g) {}

void PathFinder::shortestPath(
    string source,
    string destination
) {

    map<string, int> distance;

    map<string, string> parent;

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > pq;

    for(auto node : graph.getAdjList()) {

        distance[node.first] = INT_MAX;
    }

    distance[source] = 0;

    pq.push({0, source});

    while(!pq.empty()) {

        string current = pq.top().second;

        int dist = pq.top().first;

        pq.pop();

        for(auto neighbor :
            graph.getAdjList().at(current)) {

            string nextNode = neighbor.first;

            int weight = neighbor.second;

            if(dist + weight <
               distance[nextNode]) {

                distance[nextNode] =
                dist + weight;

                parent[nextNode] =
                current;

                pq.push({
                    distance[nextNode],
                    nextNode
                });
            }
        }
    }

    if(distance[destination] == INT_MAX) {

        cout << "\nNo Path Found\n";

        return;
    }

    vector<string> path;

    string current = destination;

    while(current != source) {

        path.push_back(current);

        current = parent[current];
    }

    path.push_back(source);

    reverse(path.begin(), path.end());

    cout << "\nShortest Path:\n";

    for(int i = 0; i < path.size(); i++) {

        cout << path[i];

        if(i != path.size() - 1) {

            cout << " -> ";
        }
    }

    cout << "\n\nShortest Distance: "
         << distance[destination]
         << endl;
}