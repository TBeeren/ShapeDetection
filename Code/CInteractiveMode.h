/**
 * @file CInteractiveMode.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class makes the interactive mode. It asks a shape and colour from the user. 
 * If he enters a valid shape and colour, the shape detection will start.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CINTERACTIVEMODE_H
#define CINTERACTIVEMODE_H

#include "CMode.h"
#include "ESelections.h"

#include "opencv2/imgcodecs.hpp"

//Forward Declarations
class CViewWindow;

class CInteractiveMode : public CMode
{
public:
    /**
     * @brief Construct a new CInteractiveMode object
     * 
     */
    CInteractiveMode();

    /**
     * @brief Destroy the CInteractiveMode object
     * 
     */
    virtual ~CInteractiveMode();

    /**
     * @brief Initializes the shape and color that the user gives in the commandline
     * 
     * @return true, if the shape and color is correct, proceed.
     * @return false, if the shape and color is not correct, try again.
     */
    bool Init() override;

    /**
     * @brief Executes the program
     * 
     */
    void Execute() override;

private:
    /**
     * @brief Draws a shape in the window based on the coordinates of the vector extractedCorners.
     * 
     * @param source, source of the webcam window.
     * @param points, vector with coordinates of a shape.
     */
    void DrawShape(cv::Mat& rSource, std::vector<cv::Point>& rPoints);

    void SetLabel(cv::Mat& rSource, const std::string& rLabel , const cv::Point& rCentre);

    std::shared_ptr<CViewWindow> m_spViewWindow;
};

#endif /*CINTERACTIVEMODE_H*/
