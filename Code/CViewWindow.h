/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CVIEWWINDOW_H
#define CVIEWWINDOW_H

#include <memory>

#include "ESelections.h" 
#include "CTrackBar.h"

//Forward declarations

class CViewWindow
{
public:
    CViewWindow(std::shared_ptr<eShapes> spShape, std::shared_ptr<eColours> spColour);
    ~CViewWindow();

private:
    std::unique_ptr<CTrackBar<eShapes>> m_spColourTrackBar;
    std::unique_ptr<CTrackBar<eColours>> m_spShapeTrackBar;
};

#endif /*CVIEWWINDOW_H*/