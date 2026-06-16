# CARGOCHECK – GLOBAL SUPPLY CUSTOM DOCUMENT AUDIT ENGINE

OVERVIEW

CargoCheck is a Data Structures and Algorithms based customs management system developed in C++. The system helps customs officers manage shipments, validate customs forms, track manifest changes, process containers, prioritize audits, and find optimal shipping routes.

FEATURES

1. Tax Directory (Trie)

* Fast customs code search using prefixes.
* Stores customs codes and tax categories.

2. Manifest Log (Stack)

* Tracks shipment manifest changes.
* Supports rollback functionality.

3. Clearance Queue (Queue)

* Processes containers using FIFO (First In First Out).

4. Form Validator (Hashing)

* Instantly validates customs forms.

5. Tax Sorter

* Sorts shipments based on tax amount.
* Prioritizes high-value shipments.

6. Route Map (Graph)

* Represents ports and shipping routes.

7. Shortest Path Finder (Dijkstra Algorithm)

* Finds the shortest route between ports.

8. Workload Balancer

* Distributes containers among customs officers.

9. Shipment Manager

* Add, display, update, and remove shipments.
* Stores data permanently using file handling.

DATA STRUCTURES USED

* Trie
* Stack
* Queue
* Hashing (unordered_set)
* Graph
* Dijkstra Algorithm
* Sorting Algorithms
* File Handling

TECHNOLOGY STACK

* C++
* Object-Oriented Programming
* STL Libraries
* File Handling

HOW TO COMPILE

g++ *.cpp -o cargo

HOW TO RUN

Mac/Linux:
./cargo

Windows:
cargo.exe

CONCLUSION

CargoCheck demonstrates the practical implementation of Data Structures and Algorithms in a real-world customs management environment. It improves shipment management, route optimization, form validation, manifest auditing, and customs clearance efficiency.

AUTHOR

Soham Patil
School of Future Tech
ITM Skills University
