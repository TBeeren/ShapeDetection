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

#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

//Forward declarations

class CViewWindow
{
public:
    //CViewWindow(std::shared_ptr<eShapes> spShape, std::shared_ptr<eColours> spColour);
    CViewWindow(std::string windowName, cv::Mat src);
    CViewWindow(std::string windowName);
    ~CViewWindow();

private:
    std::unique_ptr<CTrackBar<eShapes>> m_spColourTrackBar;
    std::unique_ptr<CTrackBar<eColours>> m_spShapeTrackBar;

    std::string m_windowName;
    cv::Mat m_src;
};

#endif /*CVIEWWINDOW_H*/