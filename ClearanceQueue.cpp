#include "ClearanceQueue.h"

void ClearanceQueue::enqueueContainer(string id) {

    containers.push(id);

    cout << "Container Added To Queue\n";
}

void ClearanceQueue::dequeueContainer() {

    if(containers.empty()) {

        cout << "Queue Empty\n";

        return;
    }

    cout << "Processing Container: "
         << containers.front() << endl;

    containers.pop();
}

bool ClearanceQueue::containerExists(string id) {

    queue<string> temp = containers;

    while(!temp.empty()) {

        if(temp.front() == id) {

            return true;
        }

        temp.pop();
    }

    return false;
}