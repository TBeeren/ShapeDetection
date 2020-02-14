/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CCalibration is responsible for initialising the proper threshhold values for each detectable colour, it also holds a vector to each colour
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CCALIBRATION_H
#define CCALIBRATION_H

#include <stdint.h>
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "CColour.h"

class CCalibration
{
public:
    CCalibration();
    ~CCalibration();

    /**
     * @brief Initialises threshhold values for each colour
     * 
     * @param userCalibration Set as true to user ask the user to calibrate the colours or false if the threshholds will be set to default values. Default set as false
     * @return true This function returns true when the colours have been succesfully initialised
     * @return false This function returns false when the colours have been unsuccesfully initialised
     */
    bool InitColours(bool userCalibration = false);
    std::shared_ptr<CColour> GetColour(eColours colourValue);
private:
    std::vector<std::shared_ptr<CColour>> m_colourList;
};

#endif /*CCALIBRATION_H*/