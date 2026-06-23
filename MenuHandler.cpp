#include "MenuHandler.h"
#include <iostream>
#include <iomanip>

MenuHandler::MenuHandler(ItemTracker& trackerInstance, const std::string& backupFile) 
    : tracker(trackerInstance), backupFileName(backupFile) {}

bool MenuHandler::run() {
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                handleSearch();
                break;
            case 2:
                handleDisplayAll();
                break;
            case 3:
                handleHistogram();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                return false;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return true;
}

void MenuHandler::displayMenu() const {
    std::cout << "\n--- Corner Grocer Item Tracking ---\n";
    std::cout << "1. Search for item frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display frequency histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void MenuHandler::handleSearch() {
    std::string item;
    std::cout << "Enter the item to search for: ";
    std::cin >> item;
    std::cout << "Frequency of '" << item << "': " << tracker.getFrequency(item) << "\n";
}

void MenuHandler::handleDisplayAll() {
    std::cout << "\n--- Item Frequencies ---\n";
    for (const auto& pair : tracker.getAllFrequencies()) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}

void MenuHandler::handleHistogram() {
    std::cout << "\n--- Frequency Histogram ---\n";
    for (const auto& pair : tracker.getAllFrequencies()) {
        std::cout << std::left << std::setw(12) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
