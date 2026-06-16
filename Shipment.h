#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>

using namespace std;

struct Shipment {

    string shipmentID;

    string containerID;

    string formID;

    string companyName;

    string customsCode;

    string sourcePort;

    string destinationPort;

    int taxAmount;
};

#endif