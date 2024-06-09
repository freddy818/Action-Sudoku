/**
 * @file Game.h
 * @author Frederick Fan
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_GAME_H
#define PROJECT1_ACTIONSUDOKULIB_GAME_H

#include <utility>

#include "ScoreBoard.h"
#include "ItemSparty.h"
#include "Banner.h"
#include <random>

class Item;

/** class for the action sudoku game */
class Game
{
private:
    /// All items to be drawn on the game
    std::vector<std::shared_ptr<Item>> mItems;

    /// items to be added to the mitems list after update
    std::vector<std::shared_ptr<Item>> toAdd;

    /// Handle scaling when resizing window
    double mScale;

    /// Offset for X scale
    double mXOffset;

    /// Offset for Y scale
    double mYOffset;

    /// Scoreboard Object
    ScoreBoard mScoreBoard = ScoreBoard();

    /// Banner Object
    Banner mBanner = Banner();

    /// Level width
    int mLevelWidth;

    /// Level height
    int mLevelHeight;

    /// Tile width
    int mTileWidth;

    /// Tile height
    int mTileHeight;

    /// Sparty item
    std::shared_ptr<ItemSparty> mSparty = nullptr;

    /// Solution column
    int mSolCol;

    /// Solution row
    int mSolRow;

    /// Solution
    int mSolution[9][9];

    ///Random number generator
    std::mt19937  mRandom;

    ///Number of containers in the game
    int mNumContainers = 0;

    ///Number of traps in the game
    int mNumTraps = 0;

    ///String for CUrrent level
    wxString mCurrentLevel = "";

    /// True if puzzle is solved, false otherwise
    bool mSolved = false;

    /// True if all pieces are put in the cells
    bool mFull = false;

public:

    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /**
     * Setter for sparty
     * @param sparty the sparty to set the game sparty to
     */
    void SetSparty(std::shared_ptr<ItemSparty> sparty) { mSparty = sparty; }

    void Clear();

    /**
     * Setter for the items vector
     * @param items a vector that the mItems vector can be set to
     */
    void SetItems(std::vector<std::shared_ptr<Item>> &items) { mItems = items; }

    void OnLeftDown(int x, int y);

    void Update(double elapsed);

    void Accept(ItemVisitor *visitor);

    std::shared_ptr<Item> HitTest(double x, double y);

    void SpartyEat();

    void SpartyHeadbutt();

    void SpartyRegurgitate(int number);

    /**
     * Setter for the tile width
     * @param tileWidth the tile width to set to
     */
    void SetTileWidth(int tileWidth) { mTileWidth = tileWidth; }

    /**
     * Setter for the tile height
     * @param tileHeight tile height to set to
     */
    void SetTileHeight(int tileHeight) { mTileHeight = tileHeight; }

    /**
     * Setter for the level width
     * @param levelWidth level width being set to
     */
    void SetLevelWidth(int levelWidth) { mLevelWidth = levelWidth; }

    /**
     * Setter for the level height
     * @param levelHeight being set to
     */
    void SetLevelHeight(int levelHeight) { mLevelHeight = levelHeight; }

    /**
    * Getter for the level width
    * @return the level width
    */
    int GetLevelWidth() const { return mLevelWidth; }

    /**
    * Getter for the level height
    * @return the level height
    */
    int GetLevelHeight() const { return mLevelHeight; }

    /**
     * Setter for the solution column
     * @param col column being set to
     */
    void SetSolCol(int col) { mSolCol = col; }

    /**
     * Setter for the solution row
     * @param row row being set to
     */
    void SetSolRow(int row) { mSolRow = row; }

    /**
     * Getter for the solution column
     * @return col column start at
     */
    int GetSolCol() { return mSolCol; }

    /**
     * Getter for the solution row
     * @return row row start at
     */
    int GetSolRow() { return mSolRow; }

    /**
     * Getter for the tile width
     * @return the tile width
     */
    int GetTileWidth() { return mTileWidth; }

    /**
     * Getter for the tile height
     * @return the tile height
     */
    int GetTileHeight() { return mTileHeight; }

    /**
     * Getter for the solution array
     * @return the solution
     */
    int (*GetSolArr())[9] { return mSolution; }

    /**
     * Getter for the game sparty
     * @return the sparty in the game
     */
    const std::shared_ptr<ItemSparty> GetSparty() const { return mSparty; }

    void SolveGame();

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
     * push an item into the Items vector
     * @param item item being pushed
     */
    void ItemPushBack(std::shared_ptr<Item> item)
    {
        toAdd.push_back(item);
    }

    /**
     * Add to the container counter
     */
    void AddContainer()
    {
        mNumContainers++;
    }

    /**
     * Getter for the number of containers
     * @return number of containers
     */
    int GetNumContainers()
    {
        return mNumContainers;
    }

    /**
     * Set the number of containers to 0
     */
     void ResetContainers()
    {
         mNumContainers = 0;
    }
    /**
    * Starts the scoreboard when the level loads
    */
    void StartScoreBoard()
    {
        mScoreBoard.Reset();
    }

    /**
     * Get the number of traps in the game
     * @return number of traps in the game
     */
    int GetNumTraps()
    {
        return mNumTraps;
    };

    /**
     * Add a trap to the games trap count
     */
    void AddTrapCount()
    {
        mNumTraps++;
    };

    /**
     * Reset the number of traps in the game to 0
     */
    void ResetTraps()
    {
        mNumTraps = 0;
    }
    /**
     * Set mCurrentLevelTitle
     * @param levelFileName the current filename  we are loading
     */
    void SetCurrentLevelTitle(const wxString &levelFileName);

    bool CheckSolved();

    bool CheckFull();
};

#endif //PROJECT1_ACTIONSUDOKULIB_GAME_H
