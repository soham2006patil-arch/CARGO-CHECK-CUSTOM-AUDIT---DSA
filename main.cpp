#include <iostream>
#include "TaxDirectory.h"
#include "ManifestLog.h"
#include "ClearanceQueue.h"
#include "FormValidator.h"
#include "TaxSorter.h"
#include "RouteGraph.h"
#include "PathFinder.h"
#include "WorkloadBalancer.h"
#include "ShipmentManager.h"

using namespace std;

int main() {

    TaxDirectory taxDir;
    ManifestLog manifest;
    ClearanceQueue clearance;
    FormValidator validator;
    TaxSorter sorter;
    RouteGraph graph;
    PathFinder pathFinder(graph);
    WorkloadBalancer balancer;
    ShipmentManager shipmentManager;

    // LOAD ALL SHIPMENTS INTO TRIE

    vector<Shipment>& allShipments =
    shipmentManager.getShipments();

    for(auto s : allShipments) {

        taxDir.insertCode(
            s.customsCode,
            s.companyName
        );
    }

    int choice;

    // VALID FORMS

    validator.addValidForm("FORM1001");
    validator.addValidForm("FORM1002");
    validator.addValidForm("FORM1003");
    validator.addValidForm("FORM1004");
    validator.addValidForm("FORM1005");

    validator.addValidForm("CUS2026001");
    validator.addValidForm("CUS2026002");
    validator.addValidForm("CUS2026003");

    validator.addValidForm("INDPORT001");
    validator.addValidForm("INDPORT002");
    validator.addValidForm("INTLFORM777");

    // ROUTES

    graph.addRoute("Mumbai", "Dubai", 5);
    graph.addRoute("Mumbai", "Singapore", 8);
    graph.addRoute("Mumbai", "London", 10);

    graph.addRoute("Dubai", "Singapore", 2);
    graph.addRoute("Dubai", "London", 7);
    graph.addRoute("Dubai", "Berlin", 6);

    graph.addRoute("Singapore", "Shanghai", 4);
    graph.addRoute("Singapore", "Tokyo", 5);
    graph.addRoute("Singapore", "Sydney", 7);

    graph.addRoute("Shanghai", "Tokyo", 3);
    graph.addRoute("Shanghai", "Seoul", 2);
    graph.addRoute("Shanghai", "HongKong", 2);

    graph.addRoute("Tokyo", "Sydney", 6);
    graph.addRoute("Tokyo", "LosAngeles", 9);

    graph.addRoute("London", "Berlin", 2);
    graph.addRoute("London", "Paris", 2);
    graph.addRoute("London", "NewYork", 8);

    graph.addRoute("Berlin", "Paris", 1);
    graph.addRoute("Berlin", "Moscow", 5);

    graph.addRoute("Paris", "NewYork", 10);
    graph.addRoute("Paris", "Rome", 2);

    graph.addRoute("NewYork", "LosAngeles", 5);
    graph.addRoute("NewYork", "Toronto", 2);

    graph.addRoute("LosAngeles", "Sydney", 11);

    graph.addRoute("Toronto", "MexicoCity", 4);

    graph.addRoute("Rome", "Cairo", 3);

    graph.addRoute("Cairo", "Dubai", 4);

    graph.addRoute("Seoul", "Tokyo", 2);

    graph.addRoute("HongKong", "Singapore", 3);

    // OFFICERS

    balancer.addOfficer("OfficerA");
    balancer.addOfficer("OfficerB");
    balancer.addOfficer("OfficerC");
    balancer.addOfficer("OfficerD");

    do {

        cout << "\n========== CargoCheck System ==========\n";

        cout << "1. Add Shipment\n";
        cout << "2. Display Shipments\n";
        cout << "3. Search Customs Code\n";
        cout << "4. Add Manifest Change\n";
        cout << "5. Rollback Manifest\n";
        cout << "6. Add Container To Queue\n";
        cout << "7. Process Container\n";
        cout << "8. Validate Form\n";
        cout << "9. Sort Shipments By Tax\n";
        cout << "10. Display Routes\n";
        cout << "11. Find Shortest Path\n";
        cout << "12. Assign Officer\n";
        cout << "13. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        string input;
        string from;
        string to;

        switch(choice) {

            case 1: {

    shipmentManager.addShipment();

    vector<Shipment>& shipments =
    shipmentManager.getShipments();

    Shipment latestShipment =
    shipments.back();

    // VALIDATE FORM

    validator.validateForm(
        latestShipment.formID
    );

    // INSERT CUSTOMS CODE

    taxDir.insertCode(
        latestShipment.customsCode,
        latestShipment.companyName
    );

    cout << "\nCustoms Code Added To Trie\n";

    break;
}

            case 2:

                shipmentManager.displayShipments();

                break;

            case 3:

                cout << "Enter Prefix: ";

                cin >> input;

                taxDir.searchPrefix(input);

                break;

            case 4:

    shipmentManager.manifestChange(manifest);

    break;

            case 5: {

    if(!manifest.hasChanges()) {

        cout << "\nNo Manifest Changes Available\n";

        break;
    }

    Shipment oldShipment =
    manifest.rollbackChange();

    shipmentManager.restoreShipment(
        oldShipment
    );

    break;
}

            case 6:

                cout << "Enter Container ID: ";

                cin >> input;

                clearance.enqueueContainer(input);

                break;

            case 7:

                clearance.dequeueContainer();

                break;

            case 8:

                cout << "Enter Form ID: ";

                cin >> input;

                validator.validateForm(input);

                break;

            case 9: {

                vector<Shipment>& shipments =
                shipmentManager.getShipments();

                if(shipments.empty()) {

                    cout << "\nNo Shipments Available\n";

                    break;
                }

                for(auto s : shipments) {

                    sorter.addShipment(
                        s.shipmentID,
                        s.companyName,
                        s.taxAmount
                    );
                }

                sorter.sortShipments();

                sorter.displayShipments();

                break;
            }

            case 10:

                graph.displayRoutes();

                break;

            case 11:

                cout << "Enter Source Port: ";

                cin >> from;

                cout << "Enter Destination Port: ";

                cin >> to;

                pathFinder.shortestPath(from, to);

                break;

            case 12: {

    cout << "Enter Container ID: ";

    cin >> input;

    bool found = false;

    vector<Shipment>& shipments =
    shipmentManager.getShipments();

    for(auto s : shipments) {

        if(s.containerID == input) {

            found = true;

            break;
        }
    }

    if(found) {

        balancer.assignContainer(input);

        shipmentManager.removeByContainer(
            input
        );
    }
    else {

        cout << "\nInvalid Container ID\n";
    }

    break;
}

            case 13:

                cout << "\nExiting...\n";

                break;

            default:

                cout << "\nInvalid Choice\n";
        }

    } while(choice != 13);

    return 0;
}