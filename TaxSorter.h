#ifndef TAXSORTER_H
#define TAXSORTER_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "Shipment.h"

using namespace std;

class TaxSorter {

private:
    vector<Shipment> shipments;

public:
    void addShipment(string id, string company, int tax);

    void sortShipments();

    void displayShipments();
};

#endif