#include "ItemTracker.h"
#include "MenuHandler.h"
#include <iostream>

int main() {
    const std::string inputFileName = "CS210_Project_Three_Input_File.txt";
    const std::string backupFileName = "frequency.dat";

    ItemTracker tracker(inputFileName);

    // Initial data load and backup
    if (!tracker.loadFrequencies()) {
        std::cerr << "Error: Could not open input file " << inputFileName << std::endl;
        return 1;
    }

    if (!tracker.backupData(backupFileName)) {
        std::cerr << "Error: Could not create backup file " << backupFileName << std::endl;
    } else {
        std::cout << "Backup data successfully saved to " << backupFileName << std::endl;
    }

    MenuHandler menu(tracker, backupFileName);
    menu.run();

    return 0;
}
