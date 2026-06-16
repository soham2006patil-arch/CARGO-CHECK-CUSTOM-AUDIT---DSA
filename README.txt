# CargoCheck - Global Supply Custom Document Audit Engine

## Overview

CargoCheck is a Data Structures and Algorithms based customs management system developed in C++. The system helps customs officers manage shipments, validate forms, track manifest changes, process containers, prioritize audits, and find optimal shipping routes.

The project demonstrates the practical application of various data structures and algorithms in a real-world customs clearance environment.

---

## Features

### 1. Tax Directory (Trie)
- Stores customs codes and tax categories.
- Supports fast prefix-based search.
- Example:
  - Search: IMP
  - Output:
    - IMP001
    - IMP002
    - IMP003

### 2. Manifest Log (Stack)
- Tracks shipment manifest changes.
- Supports rollback functionality.
- Uses LIFO (Last In First Out) principle.

### 3. Clearance Queue (Queue)
- Manages containers waiting for customs clearance.
- Processes containers using FIFO (First In First Out).

### 4. Form Validator (Hashing)
- Validates customs forms instantly.
- Uses hash-based lookup for O(1) average search time.

### 5. Tax Sorter
- Sorts shipments according to tax amount.
- Prioritizes high-revenue shipments for inspection.

### 6. Route Map (Graph)
- Represents international ports and customs checkpoints.
- Ports are represented as nodes.
- Shipping routes are represented as weighted edges.

### 7. Customs Path Finder (Dijkstra Algorithm)
- Finds the shortest route between ports.
- Helps optimize customs clearance and transportation.

### 8. Workload Balancer
- Distributes containers among customs officers.
- Prevents workload bottlenecks.

### 9. Shipment Management
- Add, update, display and remove shipments.
- Stores data permanently using file handling.

---

## Data Structures Used

| Feature | Data Structure |
|----------|---------------|
| Customs Code Search | Trie |
| Manifest Rollback | Stack |
| Container Processing | Queue |
| Form Validation | Hash Table |
| Shipment Sorting | Sorting Algorithms |
| Route Mapping | Graph |
| Shortest Path | Dijkstra Algorithm |
| Officer Assignment | Queue/Round Robin |
| Data Persistence | File Handling |

---

## Technology Stack

- Language: C++
- IDE: Visual Studio Code
- Compiler: GCC / G++
- File Storage: Text Files
- Libraries:
  - iostream
  - vector
  - queue
  - stack
  - unordered_set
  - map
  - algorithm
  - fstream

---

## Project Structure

```
CargoCheckProject/
│
├── main.cpp
├── Shipment.h
├── ShipmentManager.h
├── ShipmentManager.cpp
│
├── TaxDirectory.h
├── TaxDirectory.cpp
│
├── ManifestLog.h
├── ManifestLog.cpp
│
├── ClearanceQueue.h
├── ClearanceQueue.cpp
│
├── FormValidator.h
├── FormValidator.cpp
│
├── TaxSorter.h
├── TaxSorter.cpp
│
├── RouteGraph.h
├── RouteGraph.cpp
│
├── PathFinder.h
├── PathFinder.cpp
│
├── WorkloadBalancer.h
├── WorkloadBalancer.cpp
│
├── shipments.txt
└── README.md
```

---

## How to Compile

```bash
g++ *.cpp -o cargo
```

---

## How to Run

### Linux / Mac

```bash
./cargo
```

### Windows

```bash
cargo.exe
```

---

## Sample Menu

```text
1. Add Shipment
2. Display Shipments
3. Search Customs Code
4. Add Manifest Change
5. Rollback Manifest
6. Add Container To Queue
7. Process Container
8. Validate Form
9. Sort Shipments By Tax
10. Display Routes
11. Find Shortest Path
12. Assign Officer
13. Exit
```

---

## Real World Applications

- Customs Clearance Systems
- Port Management Systems
- Shipping & Logistics Platforms
- International Trade Monitoring
- Cargo Inspection Management
- Route Optimization Systems

---

## Conclusion

CargoCheck successfully integrates multiple Data Structures and Algorithms into a single customs management platform. The project demonstrates efficient searching, sorting, auditing, route optimization, workload balancing, and persistent shipment management in a real-world logistics environment.

---

## Authors

Soham Patil

ITM Skills University

School of Future Tech# CargoCheck - Global Supply Custom Document Audit Engine

## Overview

CargoCheck is a Data Structures and Algorithms based customs management system developed in C++. The system helps customs officers manage shipments, validate forms, track manifest changes, process containers, prioritize audits, and find optimal shipping routes.

The project demonstrates the practical application of various data structures and algorithms in a real-world customs clearance environment.

---

## Features

### 1. Tax Directory (Trie)
- Stores customs codes and tax categories.
- Supports fast prefix-based search.
- Example:
  - Search: IMP
  - Output:
    - IMP001
    - IMP002
    - IMP003

### 2. Manifest Log (Stack)
- Tracks shipment manifest changes.
- Supports rollback functionality.
- Uses LIFO (Last In First Out) principle.

### 3. Clearance Queue (Queue)
- Manages containers waiting for customs clearance.
- Processes containers using FIFO (First In First Out).

### 4. Form Validator (Hashing)
- Validates customs forms instantly.
- Uses hash-based lookup for O(1) average search time.

### 5. Tax Sorter
- Sorts shipments according to tax amount.
- Prioritizes high-revenue shipments for inspection.

### 6. Route Map (Graph)
- Represents international ports and customs checkpoints.
- Ports are represented as nodes.
- Shipping routes are represented as weighted edges.

### 7. Customs Path Finder (Dijkstra Algorithm)
- Finds the shortest route between ports.
- Helps optimize customs clearance and transportation.

### 8. Workload Balancer
- Distributes containers among customs officers.
- Prevents workload bottlenecks.

### 9. Shipment Management
- Add, update, display and remove shipments.
- Stores data permanently using file handling.

---

## Data Structures Used

| Feature | Data Structure |
|----------|---------------|
| Customs Code Search | Trie |
| Manifest Rollback | Stack |
| Container Processing | Queue |
| Form Validation | Hash Table |
| Shipment Sorting | Sorting Algorithms |
| Route Mapping | Graph |
| Shortest Path | Dijkstra Algorithm |
| Officer Assignment | Queue/Round Robin |
| Data Persistence | File Handling |

---

## Technology Stack

- Language: C++
- IDE: Visual Studio Code
- Compiler: GCC / G++
- File Storage: Text Files
- Libraries:
  - iostream
  - vector
  - queue
  - stack
  - unordered_set
  - map
  - algorithm
  - fstream

---

## Project Structure

```
CargoCheckProject/
│
├── main.cpp
├── Shipment.h
├── ShipmentManager.h
├── ShipmentManager.cpp
│
├── TaxDirectory.h
├── TaxDirectory.cpp
│
├── ManifestLog.h
├── ManifestLog.cpp
│
├── ClearanceQueue.h
├── ClearanceQueue.cpp
│
├── FormValidator.h
├── FormValidator.cpp
│
├── TaxSorter.h
├── TaxSorter.cpp
│
├── RouteGraph.h
├── RouteGraph.cpp
│
├── PathFinder.h
├── PathFinder.cpp
│
├── WorkloadBalancer.h
├── WorkloadBalancer.cpp
│
├── shipments.txt
└── README.md
```

---

## How to Compile

```bash
g++ *.cpp -o cargo
```

---

## How to Run

### Linux / Mac

```bash
./cargo
```

### Windows

```bash
cargo.exe
```

---

## Sample Menu

```text
1. Add Shipment
2. Display Shipments
3. Search Customs Code
4. Add Manifest Change
5. Rollback Manifest
6. Add Container To Queue
7. Process Container
8. Validate Form
9. Sort Shipments By Tax
10. Display Routes
11. Find Shortest Path
12. Assign Officer
13. Exit
```

---

## Real World Applications

- Customs Clearance Systems
- Port Management Systems
- Shipping & Logistics Platforms
- International Trade Monitoring
- Cargo Inspection Management
- Route Optimization Systems

---

## Conclusion

CargoCheck successfully integrates multiple Data Structures and Algorithms into a single customs management platform. The project demonstrates efficient searching, sorting, auditing, route optimization, workload balancing, and persistent shipment management in a real-world logistics environment.

---

## Authors

Soham Patil

ITM Skills University

School of Future Tech
