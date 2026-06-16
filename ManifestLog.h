#ifndef MANIFESTLOG_H
#define MANIFESTLOG_H

#include <stack>
#include <iostream>

#include "Shipment.h"

using namespace std;

class ManifestLog {

private:

    stack<Shipment> changes;

public:

    void addChange(Shipment oldShipment);

    bool hasChanges();

    Shipment rollbackChange();
};

#endif