/**
 * @file LevelLoader.h
 * @author Aion
 *
 * Class to load the levels
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_LEVELLOADER_H
#define PROJECT1_ACTIONSUDOKULIB_LEVELLOADER_H

#include "Game.h"
#include "Item.h"
#include "Declaration.h"

#include <map>

/**
 * Load level data from XML
 *
 * Create the declarations and items and return the list of items for the game
 */
class LevelLoader
{
private:
    /// A map to store the declarations of each item, the id will be the key, values the value
    std::map<wxString, std::shared_ptr<Declaration>> mDeclarations;

    /// pointer to game that is being loaded
    Game *mGame = nullptr;



public:
    void LoadLevel(Game *game, const wxString &levelName);

    void CreateDeclarations(wxXmlNode *declRoot);
    std::vector<std::shared_ptr<Item>> CreateItems(wxXmlNode *itemRoot);
    void CreateSolution(wxXmlNode *solutionRoot, int (*sol)[9]);
};

#endif //PROJECT1_ACTIONSUDOKULIB_LEVELLOADER_H
