/**
 * @file GameView.h
 * @author Aion
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_GAMEVIEW_H
#define PROJECT1_ACTIONSUDOKULIB_GAMEVIEW_H

#include "Game.h"

/** provides a view for the game */
class GameView : public wxWindow
{
private:
    /// Game board
    Game mGame;

    /// Timer event
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    ///the current level that the game is on
    std::string mCurrentLevel;

    ///the current level that the game is on but its sanitized for banner use
    std::string mTitleText;


public:
    void Initialize(wxFrame *parent);
    void OnPaint(wxPaintEvent &event);
    void OnLeftDown(wxMouseEvent &event);
    void OnTimer(wxTimerEvent &event);

    /**
     * Stop the timer so the window can close
     */
    void Stop() { mTimer.Stop(); }

    void OnKeyDown(wxKeyEvent &event);

    void SetCurrentLevel(const std::string& levelFileName);

    void Solve(wxCommandEvent&);};

#endif //PROJECT1_ACTIONSUDOKULIB_GAMEVIEW_H
