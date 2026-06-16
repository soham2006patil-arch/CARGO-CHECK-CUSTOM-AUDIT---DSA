
#include "WorkloadBalancer.h"

void WorkloadBalancer::addOfficer(string name) {
    officers.push({0, name});
}

void WorkloadBalancer::assignContainer(string container) {
    if(officers.empty()) {
        cout << "No Officers Available\n";
        return;
    }

    Officer officer = officers.top();
    officers.pop();

    cout << container << " assigned to " << officer.name << endl;

    officer.workload++;

    officers.push(officer);
}
