#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include "ItemTracker.h"
#include <string>

/**
 * MenuHandler class manages the user interface and interaction
 * for the item tracking program.
 */
class MenuHandler {
private:
    ItemTracker& tracker;
    const std::string backupFileName;

public:
    MenuHandler(ItemTracker& trackerInstance, const std::string& backupFile);

    /**
     * Displays the main menu and processes user input.
     * @return true if the user wants to continue, false if they want to exit.
     */
    bool run();

private:
    void displayMenu() const;
    void handleSearch();
    void handleDisplayAll();
    void handleHistogram();
};

#endif // MENU_HANDLER_H
