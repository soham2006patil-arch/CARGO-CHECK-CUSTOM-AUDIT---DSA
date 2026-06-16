#include "TaxSorter.h"

void TaxSorter::addShipment(string id, string company, int tax) {

    Shipment s;

    s.shipmentID = id;
    s.companyName = company;
    s.customsCode = "";
    s.sourcePort = "";
    s.destinationPort = "";
    s.taxAmount = tax;

    shipments.push_back(s);
}

bool compareShipment(Shipment a, Shipment b) {
    return a.taxAmount > b.taxAmount;
}

void TaxSorter::sortShipments() {
    sort(shipments.begin(), shipments.end(), compareShipment);
}

void TaxSorter::displayShipments() {

    for(auto s : shipments) {

        cout << "Shipment ID: " << s.shipmentID << endl;
        cout << "Company: " << s.companyName << endl;
        cout << "Tax Amount: " << s.taxAmount << endl;
        cout << "----------------------" << endl;
    }
}