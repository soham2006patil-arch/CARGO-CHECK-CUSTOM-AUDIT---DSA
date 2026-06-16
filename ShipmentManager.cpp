#include "ShipmentManager.h"

#include <fstream>

ShipmentManager::ShipmentManager() {

    loadShipments();
}

void ShipmentManager::loadShipments() {

    ifstream file("shipments.txt");

    Shipment s;

    while(file >> s.shipmentID
               >> s.containerID
               >> s.formID
               >> s.companyName
               >> s.customsCode
               >> s.sourcePort
               >> s.destinationPort
               >> s.taxAmount) {

        shipments.push_back(s);
    }

    file.close();
}

void ShipmentManager::saveShipments() {

    ofstream file("shipments.txt");

    for(auto s : shipments) {

        file << s.shipmentID << " "
             << s.containerID << " "
             << s.formID << " "
             << s.companyName << " "
             << s.customsCode << " "
             << s.sourcePort << " "
             << s.destinationPort << " "
             << s.taxAmount << endl;
    }

    file.close();
}

void ShipmentManager::addShipment() {

    Shipment s;

    cout << "Enter Shipment ID: ";
    cin >> s.shipmentID;

    cout << "Enter Container ID: ";
    cin >> s.containerID;

    cout << "Enter Form ID: ";
    cin >> s.formID;

    cout << "Enter Company Name: ";
    cin >> s.companyName;

    cout << "Enter Customs Code: ";
    cin >> s.customsCode;

    cout << "Enter Source Port: ";
    cin >> s.sourcePort;

    cout << "Enter Destination Port: ";
    cin >> s.destinationPort;

    cout << "Enter Tax Amount: ";
    cin >> s.taxAmount;

    shipments.push_back(s);

    saveShipments();

    cout << "\nShipment Added Successfully\n";
}

void ShipmentManager::displayShipments() {

    if(shipments.empty()) {

        cout << "\nNo Shipments Available\n";

        return;
    }

    cout << "\n========== Shipment Records ==========\n";

    for(auto s : shipments) {

        cout << "\nShipment ID: "
             << s.shipmentID << endl;

        cout << "Container ID: "
             << s.containerID << endl;

        cout << "Form ID: "
             << s.formID << endl;

        cout << "Company Name: "
             << s.companyName << endl;

        cout << "Customs Code: "
             << s.customsCode << endl;

        cout << "Source Port: "
             << s.sourcePort << endl;

        cout << "Destination Port: "
             << s.destinationPort << endl;

        cout << "Tax Amount: "
             << s.taxAmount << endl;

        cout << "----------------------------------\n";
    }
}

void ShipmentManager::manifestChange(
    ManifestLog &manifest
) {

    string id;

    cout << "\nEnter Shipment ID To Modify: ";

    cin >> id;

    for(auto &s : shipments) {

        if(s.shipmentID == id) {

            manifest.addChange(s);

            cout << "\nEnter New Container ID: ";
            cin >> s.containerID;

            cout << "Enter New Form ID: ";
            cin >> s.formID;

            cout << "Enter New Company Name: ";
            cin >> s.companyName;

            cout << "Enter New Customs Code: ";
            cin >> s.customsCode;

            cout << "Enter New Source Port: ";
            cin >> s.sourcePort;

            cout << "Enter New Destination Port: ";
            cin >> s.destinationPort;

            cout << "Enter New Tax Amount: ";
            cin >> s.taxAmount;

            saveShipments();

            cout << "\nManifest Updated Successfully\n";

            return;
        }
    }

    cout << "\nShipment Not Found\n";
}

void ShipmentManager::restoreShipment(
    Shipment oldShipment
) {

    for(auto &s : shipments) {

        if(s.shipmentID ==
           oldShipment.shipmentID) {

            s = oldShipment;

            saveShipments();

            cout << "\nManifest Rolled Back Successfully\n";

            return;
        }
    }
}

void ShipmentManager::removeShipment(string id) {

    for(int i = 0; i < shipments.size(); i++) {

        if(shipments[i].shipmentID == id) {

            shipments.erase(shipments.begin() + i);

            saveShipments();

            cout << "\nShipment Removed Successfully\n";

            return;
        }
    }

    cout << "\nShipment Not Found\n";
}

void ShipmentManager::removeByContainer(
    string containerID
) {

    bool found = false;

    for(auto it = shipments.begin();
        it != shipments.end();) {

        if(it->containerID == containerID) {

            cout << "\nShipment Cleared Successfully\n";

            cout << "Removing Shipment: "
                 << it->shipmentID
                 << endl;

            it = shipments.erase(it);

            found = true;
        }
        else {

            ++it;
        }
    }

    if(found) {

        saveShipments();

        cout << "\nshipments.txt Updated\n";
    }
    else {

        cout << "\nContainer Not Found In Shipments\n";
    }
}

vector<Shipment>& ShipmentManager::getShipments() {

    return shipments;
}