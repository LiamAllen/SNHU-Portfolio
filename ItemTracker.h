#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>

/**
 * ItemTracker class handles the reading of the input file,
 * tracking the frequency of items using a map, and providing
 * methods to retrieve this data.
 */
class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies;
    std::string inputFileName;

public:
    ItemTracker(const std::string& fileName);

    /**
     * Reads the input file and populates the frequency map.
     * @return true if the file was read successfully, false otherwise.
     */
    bool loadFrequencies();

    /**
     * Returns the frequency of a specific item.
     * @param item The item to look for.
     * @return The frequency of the item, or 0 if not found.
     */
    int getFrequency(const std::string& item) const;

    /**
     * Returns the entire frequency map.
     */
    const std::map<std::string, int>& getAllFrequencies() const;

    /**
     * Backs up the current frequencies to a specified data file.
     * @param outputFileName The name of the file to save the data to.
     * @return true if the file was written successfully, false otherwise.
     */
    bool backupData(const std::string& outputFileName) const;
};

#endif // ITEM_TRACKER_H
