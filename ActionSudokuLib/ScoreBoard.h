/**
 * @file ScoreBoard.h
 * @author owenl
 *
 *
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_SCOREBOARD_H
#define PROJECT1_ACTIONSUDOKULIB_SCOREBOARD_H

/** Class to draw the scoreboard/timer */
class ScoreBoard
{
private:
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The starting stopwatch time
    long mStartTime = 0;
public:
    ScoreBoard();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);


    /**
     * Reset the timer
     */
    void Reset(){
        mStopWatch.Start();
        mStartTime = mStopWatch.Time();
    };

    /**
     * Get Current time
     * @return the current time
     */
    double GetCurTime()
    {
        // Compute the time that has elapsed
        // since the last call to OnPaint.
        auto newTime = mStopWatch.Time();
        return (double)(newTime - mStartTime) * 0.001;
    }
};

#endif //PROJECT1_ACTIONSUDOKULIB_SCOREBOARD_H
