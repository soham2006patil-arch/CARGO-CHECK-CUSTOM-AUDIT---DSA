#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "RouteGraph.h"

class PathFinder {

private:

    RouteGraph &graph;

public:

    PathFinder(RouteGraph &g);

    void shortestPath(
        string source,
        string destination
    );
};

#endif