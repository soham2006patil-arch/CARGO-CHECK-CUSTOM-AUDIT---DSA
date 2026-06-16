#ifndef CLEARANCEQUEUE_H
#define CLEARANCEQUEUE_H

#include <queue>
#include <iostream>

using namespace std;

class ClearanceQueue {

private:
    queue<string> containers;

public:

    void enqueueContainer(string id);

    void dequeueContainer();

    bool containerExists(string id);
};

#endif