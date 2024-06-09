/**
 * @file Banner.h
 * @author Aion
 *
 * Class for the Start Banner
 */

#ifndef PROJECT1_ACTIONSUDOKULIB_BANNER_H
#define PROJECT1_ACTIONSUDOKULIB_BANNER_H

/** Class for the Start Banner */
class Banner
{
private:

public:
    void StartBanner(std::shared_ptr<wxGraphicsContext> graphics, const wxString filename);
    void SolveBanner(std::shared_ptr<wxGraphicsContext> graphics, bool solved);
};

#endif //PROJECT1_ACTIONSUDOKULIB_BANNER_H
