/**
 * @file MainFrame.h
 * @author Aion
 *
 * Main Frame for the Action Sudoku app
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_MAINFRAME_H
#define PROJECT1_ACTIONSUDOKULIB_MAINFRAME_H

#include "GameView.h"

/**
 * Main Frame for the Action Sudoku app
 */
class MainFrame : public wxFrame
{
private:
    ///A game view
    GameView *mGameView;

    ///string for the current level
    std::string mCurrentLevel;
public:

    void Initialize();
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);

    void OnLoadLevel0(wxCommandEvent &event);
    void OnLoadLevel1(wxCommandEvent &event);
    void OnLoadLevel2(wxCommandEvent &event);
    void OnLoadLevel3(wxCommandEvent &event);
    void OnSolve(wxCommandEvent &event);
};

#endif //PROJECT1_ACTIONSUDOKULIB_MAINFRAME_H
