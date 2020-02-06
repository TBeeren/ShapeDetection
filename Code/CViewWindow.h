/**
 * @file CViewWindow.h
 * @author Evren Kilic (ET.Kilic@student.han.nl), Tim Beeren (T.Beeren1@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 06-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CVIEWWINDOW_H
#define CVIEWWINDOW_H

#include <memory>

#include "ESelections.h" 

//Forward declarations
class CTrackBar;

class CViewWindow
{
public:
    CViewWindow(std::shared_ptr<eShapes> spShape, std::shared_ptr<eColours> spColour );
    ~CViewWindow();

private:
    std::unique_ptr<CTrackBar> m_spColourTrackBar;
    std::unique_ptr<CTrackBar> m_spShapeTrackBar;
};

#endif /*CVIEWWINDOW_H*/