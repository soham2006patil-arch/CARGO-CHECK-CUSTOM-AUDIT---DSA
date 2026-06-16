#include "ManifestLog.h"

void ManifestLog::addChange(Shipment oldShipment) {

    changes.push(oldShipment);

    cout << "\nManifest Change Saved\n";
}

bool ManifestLog::hasChanges() {

    return !changes.empty();
}

Shipment ManifestLog::rollbackChange() {

    Shipment oldShipment = changes.top();

    changes.pop();

    return oldShipment;
}