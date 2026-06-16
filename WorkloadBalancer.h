
#ifndef WORKLOADBALANCER_H
#define WORKLOADBALANCER_H

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Officer {
    int workload;
    string name;

    bool operator>(const Officer& other) const {
        return workload > other.workload;
    }
};

class WorkloadBalancer {
private:
    priority_queue<Officer, vector<Officer>, greater<Officer>> officers;

public:
    void addOfficer(string name);
    void assignContainer(string container);
};

#endif
