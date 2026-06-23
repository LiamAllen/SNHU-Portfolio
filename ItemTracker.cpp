#include "ItemTracker.h"
#include <fstream>

ItemTracker::ItemTracker(const std::string& fileName) : inputFileName(fileName) {}

bool ItemTracker::loadFrequencies() {
    std::ifstream file(inputFileName);
    if (!file.is_open()) {
        return false;
    }

    std::string item;
    while (file >> item) {
        itemFrequencies[item]++;
    }
    file.close();
    return true;
}

int ItemTracker::getFrequency(const std::string& item) const {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0;
}

const std::map<std::string, int>& ItemTracker::getAllFrequencies() const {
    return itemFrequencies;
}

bool ItemTracker::backupData(const std::string& outputFileName) const {
    std::ofstream outFile(outputFileName);
    if (!outFile.is_open()) {
        return false;
    }

    for (const auto& pair : itemFrequencies) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
    return true;
}
