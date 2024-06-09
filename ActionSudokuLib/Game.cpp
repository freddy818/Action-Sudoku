/**
 * @file Game.cpp
 * @author Aion
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"
#include "SolveCheck.h"


/**
 * The size of the Sudoku board.
 * Represents the number of cells in one row or column.
 */
const int BOARD_SIZE = 9;

Game::Game()
{
    std::random_device rd;
    mRandom.seed(rd());
}

/**
 * Draw the Sudoku game
 * @param graphics The device context to draw on
 * @param width Width of the window
 * @param height Height of the window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Determine the size of the playing area in pixels
    // This is up to you...
    int pixelWidth = mLevelWidth * mTileWidth;
    int pixelHeight = mLevelHeight * mTileHeight;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if(height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    for(auto item : mItems)
    {
        item->Draw(graphics, mTileWidth, mTileHeight);
    }

    mScoreBoard.Draw(graphics);

    if(mScoreBoard.GetCurTime() < 3)
    {
        mBanner.StartBanner(graphics, mCurrentLevel);
    }

    if(mSolved && mFull)
    {
        mBanner.SolveBanner(graphics, mSolved);
    }
    else if(!mSolved && mFull)
    {
        mBanner.SolveBanner(graphics, mSolved);
    }

    graphics->PopState();

}

/**
 * Clear the game data
 *
 * Delete all data in the mItem vector
 */
void Game::Clear()
{
    mItems.clear();
}

/**
* Handle a mouse click
 * @param screenX x coordinate of the click
 * @param screenY y coord of the click
*/
void Game::OnLeftDown(int screenX, int screenY)
{
    double virtualX = (screenX - mXOffset) / mScale;
    double virtualY = (screenY - mYOffset) / mScale;

    if(virtualX < 0 || virtualX >= mLevelWidth * mTileWidth ||
        virtualY < 0 || virtualY >= mLevelHeight * mTileHeight)
    {
        // Ignore click
        return;
    }

    mSparty->SetMoveTarget(virtualX, virtualY);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    for(auto item : mItems)
    {
        if(!item)
        {
            continue;
        }
        item->Update(elapsed);
    }
    for(auto addItem : toAdd)
    {
        mItems.insert(mItems.end() - 2, addItem);
    }
    toAdd.clear();

    mFull = CheckFull();
    if(mFull)
    {
        mSolved = CheckSolved();
    }
    else
    {
        mSolved = false;
    }
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemVisitor *visitor)
{
    for(auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Test a x, y click location to see if it clicked on some item or in a cell
 * @param x X location in pixels
 * @param y Y location in pixels
 * @return Pointer to item we clicked on or nullptr if none
 */
std::shared_ptr<Item> Game::HitTest(double x, double y)
{
    for(auto i = mItems.begin(); i != mItems.end(); i++)
    {
        if((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return nullptr;
}

/**
 * Ask sparty to eat if sparty is not moving
 */
void Game::SpartyEat()
{
    if(mSparty->IsMoving())
        return;

    mSparty->Eat();
}

/**
 * Ask sparty to headbutt if he is not moving
 */
void Game::SpartyHeadbutt()
{
    if(mSparty->IsMoving())
        return;

    mSparty->SetHeadbutting(true);
}

/**
 * Automatically solve the game for the player
 */
void Game::SolveGame()
{

}

/**
 * Regurgitate the digit with value number if it exists in the stomach
 * @param number
 */
void Game::SpartyRegurgitate(int number)
{
    if(mSparty->IsMoving())
        return;

    mSparty->Regurgitate(number);
}

void Game::SetCurrentLevelTitle(const wxString &levelFileName)
{
    if(levelFileName == "levels/level0.xml")
    {
        mCurrentLevel = "Level 0";
    }
    else if(levelFileName == "levels/level1.xml")
    {
        mCurrentLevel = "Level 1";
    }
    else if(levelFileName == "levels/level2.xml")
    {
        mCurrentLevel = "Level 2";
    }
    else
    {
        mCurrentLevel = "Level 3";
    }
}

/**
 * Check if the game has been solved
 * @return
 */
bool Game::CheckSolved()
{
    bool isSolved = true;
    int i = 0, j = 0;
    for(int row = mSolRow; row < mSolRow + BOARD_SIZE; row++)
    {
        for(int col = mSolCol; col < mSolCol + BOARD_SIZE; col++)
        {
            SolveCheck visitor(mSolution[i][j], col, row);
            Accept(&visitor);
            bool found = visitor.GetFound();
            isSolved &= found;
            j++;
            if(j > BOARD_SIZE-1)
                j = 0;
        }
        i++;
        if(i > BOARD_SIZE-1)
            i = 0;
    }
    return isSolved;
}

/**
 * Check if the board is full
 * @return bool if the board is full
 */
bool Game::CheckFull()
{
    bool isFull = true;
    int i = 0, j = 0;
    for(int row = mSolRow; row < mSolRow + BOARD_SIZE; row++)
    {
        for(int col = mSolCol; col < mSolCol + BOARD_SIZE; col++)
        {
            SolveCheck visitor(-1, col, row);
            Accept(&visitor);
            bool full = visitor.GetFull();
            isFull &= full;
            j++;
            if(j > BOARD_SIZE-1)
                j = 0;
        }
        i++;
        if(i > BOARD_SIZE-1)
            i = 0;
    }
    return isFull;
}
