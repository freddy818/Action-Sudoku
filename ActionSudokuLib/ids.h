/**
 * @file ids.h
 * @author Aion
 *
 * ID values for the program
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_IDS_H
#define PROJECT1_ACTIONSUDOKULIB_IDS_H
#include <wx/frame.h>
#include <wx/sizer.h>

/**
 * Ids of menu options for the game
 */
enum IDs
{
    IDM_SOLVE = wxID_HIGHEST + 1,
    IDM_LEVEL0 = wxID_HIGHEST + 2,
    IDM_LEVEL1 = wxID_HIGHEST + 3,
    IDM_LEVEL2 = wxID_HIGHEST + 4,
    IDM_LEVEL3 = wxID_HIGHEST + 5,
};

#endif //PROJECT1_ACTIONSUDOKULIB_IDS_H
