/**
 * @file MainFrame.cpp
 * @author Aion
 *
 * Main Frame for the Action Sudoku app
 */

#include "pch.h"
#include "MainFrame.h"
#include "ids.h"
#include <wx/frame.h>
#include <wx/sizer.h>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


/**
 * Initialize the main frame
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"ActionSudoku",
           wxDefaultPosition, wxSize(1000, 800));

    // Create a sizer that will lay out child windows vertically one above each other
    auto sizer = new wxBoxSizer(wxVERTICAL);

    // Create the view class object as a child of MainFrame
    mGameView = new GameView();
    mGameView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mGameView, 1, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer(sizer);

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar();

    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto levelMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    fileMenu->Append(IDM_SOLVE, "Solve\tAlt-Y", "Solve this Level");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    menuBar->Append(levelMenu, L"&Levels");
    levelMenu->Append(IDM_LEVEL0, "Level 0\tF2", "Load Level 0");
    levelMenu->Append(IDM_LEVEL1, "Level 1\tF3", "Load Level 1");
    levelMenu->Append(IDM_LEVEL2, "Level 2\tF4", "Load Level 2");
    levelMenu->Append(IDM_LEVEL3, "Level 3\tF5", "Load Level 3");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLoadLevel0, this, IDM_LEVEL0);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLoadLevel1, this, IDM_LEVEL1);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLoadLevel2, this, IDM_LEVEL2);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnLoadLevel3, this, IDM_LEVEL3);

    menuBar->Append(helpMenu, L"&Help");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSolve, this, IDM_SOLVE);





    SetMenuBar(menuBar);

    CreateStatusBar(1, wxSTB_SIZEGRIP, wxID_ANY);

}

/**
* Exit menu option handler
 * @param event the command event
*/
void MainFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

/**
* Help menu option handler
 * @param event the command event
*/
void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(L"Action Sudoku",
                 L"Action Sudoku",
                 wxOK,
                 this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent &event)
{
    mGameView->Stop();
    Destroy();
}

/**
 * Set the current level to 0
 * @param event the menu command event
 */
void MainFrame::OnLoadLevel0(wxCommandEvent &event)
{
    mGameView->SetCurrentLevel("level0.xml");
}

/**
 * Set current level to 1
 * @param event menu command event
 */
void MainFrame::OnLoadLevel1(wxCommandEvent &event)
{
    mGameView->SetCurrentLevel("level1.xml");
}

/**
 * Set current level to 2
 * @param event menu command event
 */
void MainFrame::OnLoadLevel2(wxCommandEvent &event)
{
    mGameView->SetCurrentLevel("level2.xml");
}

/**
 * Set current level to 3
 * @param event menu command event
 */
void MainFrame::OnLoadLevel3(wxCommandEvent &event)
{
    mGameView->SetCurrentLevel("level3.xml");
}

/**
 * Handles the solve menu command
 * @param event menu command event
 */
void MainFrame::OnSolve(wxCommandEvent &event)
{
    // Delegate the call to GameView::Solve
    wxCommandEvent solveEvent;
    mGameView->Solve(solveEvent);
}
