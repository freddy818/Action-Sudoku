/**
 * @file GameView.cpp
 * @author Aion
 */

#include "pch.h"
#include "GameView.h"
#include "LevelLoader.h"
#include "SolveVisitor.h"

/// Frame duration in milliseconds
const int FrameDuration = 30;
/**
 * Initialize the game view class.
 * @param parent
 */
void GameView::Initialize(wxFrame *parent)
{
    Create(parent, wxID_ANY, wxDefaultPosition,
           wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    Bind(wxEVT_CHAR, &GameView::OnKeyDown, this);

    if(mCurrentLevel.empty())
    {
        mCurrentLevel = "level1.xml";
    }
    LevelLoader loader;
    loader.LoadLevel(&mGame, "levels/" + mCurrentLevel);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();

    if(mTitleText.empty())
    {
        mTitleText = "Level 1 Begin";
    }

}

/**
 * Handling On paint event
 * @param event paint event
 */
void GameView::OnPaint(wxPaintEvent &event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.

    //mGame.Update(elapsed);
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;


    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.Update(elapsed);
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

/**
 * Handle a left click event
 * @param event event being handled
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    mGame.OnLeftDown(event.GetX(), event.GetY());
    Refresh();
}

/**
 * event handler for a timer event
 * @param event timer event
 */
void GameView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}

/**
 * event handler for check what key was pressed
 * @param event key down event
 */
void GameView::OnKeyDown(wxKeyEvent &event)
{
    int keyCode = event.GetKeyCode();
    if(keyCode == 'b')
    {
        mGame.SpartyHeadbutt();
    }
    else if(keyCode == WXK_SPACE)
    {
        mGame.SpartyEat();
    }
    else if(keyCode >= '0' && keyCode <= '9')
    {
        int number = keyCode - '0';
        mGame.SpartyRegurgitate(number);
    }

}

/**
 * Set the game to the current level
 * @param levelFileName the name of the level being loaded
 */
void GameView::SetCurrentLevel(const std::string &levelFileName)
{
    mCurrentLevel = levelFileName;
    LevelLoader loader;
    loader.LoadLevel(&mGame, "levels/" + mCurrentLevel);
    Refresh();
}


/**
 * Automatically solve the game for the player
 * @param event Solve menu option event
 */
void GameView::Solve(wxCommandEvent& event)
{
    // Get the solution array from the game
    int (*solutionArray)[9] = mGame.GetSolArr();

    // Create a visitor and accept it
    SolveVisitor visitor;
    visitor.SetSolutionArray(solutionArray);
    visitor.SetGame(&mGame);
    mGame.Accept(&visitor);

    // Call the Solve method
    visitor.Solve();
}
