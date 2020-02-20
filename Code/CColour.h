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
    explicit CColour(eColours colour);
    explicit CColour(eColours colour, cv::Scalar lowerRange, cv::Scalar upperRange);
    virtual ~CColour();

    const eColours GetColour() const;
    const cv::Scalar& GetLowerLimit() const;
    const cv::Scalar& GetUpperLimit() const;

    /**
     * @brief Get the Rgb Colour object
     * 
     * @return const cv::Scalar& 
     */
    const cv::Scalar& getRgbColour() const;
private:
    eColours m_colour;
    cv::Scalar m_lowerLimit;
    cv::Scalar m_upperLimit;
    cv::Scalar m_rgbColour;
};

#endif /*CCOLOUR_H*/