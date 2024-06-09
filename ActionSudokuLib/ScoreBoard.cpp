/**
 * @file ScoreBoard.cpp
 * @author Aion
 */

#include "pch.h"
#include "ScoreBoard.h"

/**
 * Offset for the timer.
 * Represents the initial time deduction from the elapsed time.
 */
const int TimerOffset = 3;

/**
 * Scoreboard constructor
 */
ScoreBoard::ScoreBoard()
{
    Reset();
}

/**
 * Draw the scoreboard
 * @param graphics graphics context being drawn to
 */
void ScoreBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)((newTime - mStartTime) * 0.001) - TimerOffset;

    if (elapsed > 0)
    {
        // calculate display time
        int minutes = elapsed / 60;
        int seconds = elapsed - (minutes * 60);
        wxString time;
        if(seconds < 10)
        {
            time = wxString::Format(wxT("%i:0%i"), minutes, seconds);
        }
        else
        {
            time = wxString::Format(wxT("%i:%i"), minutes, seconds);
        }

        //
        // Draw some text
        //
        wxFont font(wxSize(0, 64), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(255, 255, 255));
        //text
        graphics->DrawText(time, 10, 10);
    }
}
