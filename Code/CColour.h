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

#ifndef CCOLOUR_H
#define CCOLOUR_H

#include "ESelections.h"
#include "opencv2/opencv.hpp"

class CColour
{
public:
    CColour(eColours aColour);
    CColour(eColours aColour, cv::Scalar lowerRange, cv::Scalar upperRange);
    ~CColour();

    eColours GetColour();
    cv::Scalar GetLowerLimit();
    cv::Scalar GetUpperLimit();
private:
    eColours m_colour;
    cv::Scalar m_lowerLimit;
    cv::Scalar m_upperLimit;
};

#endif /*CCOLOUR_H*/