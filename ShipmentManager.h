#ifndef SHIPMENTMANAGER_H
#define SHIPMENTMANAGER_H

#include <vector>
#include <iostream>

#include "Shipment.h"
#include "ManifestLog.h"

using namespace std;

class ShipmentManager {

private:

    vector<Shipment> shipments;

public:

    ShipmentManager();

    void loadShipments();

    void saveShipments();

    void addShipment();

    void displayShipments();

    void manifestChange(ManifestLog &manifest);

    void removeShipment(string id);

    void restoreShipment(Shipment oldShipment);

    void removeByContainer(string containerID);

    vector<Shipment>& getShipments();
};

#endif