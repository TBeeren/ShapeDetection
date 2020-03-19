/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class creates opencv windows.
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

    /**
     * @brief Construct a new CViewWindow object
     * 
     * @param windowName, name of the window
     * @param src, src of the image
     */
    explicit CViewWindow(const std::string& rWindowName, cv::Mat src);

    /**
     * @brief Construct a new CViewWindow object. This constructor opens a window with webcam.
     * 
     * @param windowName, name of the window
     */
    explicit CViewWindow(const std::string& rWindowName);

    /**
     * @brief Destroy the CViewWindow object
     * 
     */
    virtual ~CViewWindow();

    void UpdateSource(bool updateWindow = true);
    cv::Mat GetSource() const;

private:
    std::unique_ptr<CTrackBar<eShapes>> m_spColourTrackBar;
    std::unique_ptr<CTrackBar<eColours>> m_spShapeTrackBar;

    std::string m_windowName;
    cv::Mat m_src;
    std::shared_ptr<cv::VideoCapture> m_spVideoCapture;
};

#endif /*CVIEWWINDOW_H*/