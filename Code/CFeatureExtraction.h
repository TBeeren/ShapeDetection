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

#ifndef CFEATUREEXTRACTION_H
#define CFEATUREEXTRACTION_H

#include <vector>
#include "opencv2/opencv.hpp"
#include "ESelections.h"
#include <memory>

class CCalibration;
class CColour;

class CFeatureExtraction
{
public:
    CFeatureExtraction();
    ~CFeatureExtraction();

    /**
     * @brief Initialise the CFeatureExtraction. Mostly meaning that the colours get calibrated
     * 
     * @param userCalibration Passing this bool as true will mean that the user will have to manually set the threshholds for all colours. Default set to false 
     * @return true This function returns true when the initialisation of the feature extrator was succesful
     * @return false This function returns false when the initialisation of the feature extrator was unsuccesful
     */
    bool init(bool userCalibration = false);

    /**
     * @brief Extracts the colours from the input Matrix
     * 
     * @param input an input Matrix from out of which the colours will be extracted
     * @param colour the colour to extract from the input
     * @return cv::Mat This function returns a Matrix in which the colours from the image that fit between the thresholds get turned to white and all others are black 
     */
    cv::Mat extractColours(cv::Mat& input, eColours colour);

    /**
     * @brief Uses the Canny edge detection algorithm to detect all edges from the image NOTE: use after ExtractColours function for best results
     * 
     * @param input the input matrix from which to extract the edges
     * @return cv::Mat a Matrix which shows only edges as detected by the Canny algorithm
     */
    cv::Mat extractEdges(cv::Mat& input);

    /**
     * @brief Turns detected into contours
     * 
     * @param input the input matrix out of which the edges will be turned into contours
     * @return std::vector<std::vector<cv::Point>> This function returns a vector which contains another vector of points for each detected shape above a certain size
     */
    std::vector<std::vector<cv::Point>> extractContours(cv::Mat& input);

private:
    std::shared_ptr<CColour> m_lookupColour;
    std::shared_ptr<CCalibration> m_spCalibration;
};

#endif /*CFEATUREEXTRACTION_H*/