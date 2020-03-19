/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CFeature extraction is responsible for extracting features from input Matrixes. It does this primarily by applying an inRange mask for the specified colour,
 * afterwards Canny edge detection is applied to gather edges. These edges are used to determine the corner points for each shape that has the specified colout.
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
    virtual ~CFeatureExtraction();

    /**
     * @brief Initialise the CFeatureExtraction. Mostly meaning that the colours get calibrated
     * 
     * @param userCalibration Passing this bool as true will mean that the user will have to manually set the threshholds for all colours. Default set to false 
     * @return true This function returns true when the initialisation of the feature extrator was succesful
     * @return false This function returns false when the initialisation of the feature extrator was unsuccesful
     */
    bool Init(bool userCalibration = false);

    /**
     * @brief Execute all extraction functions and return the corner points for the shapes with specified colour
     * 
     * @param colour the colour for which to extract the corner points
     * @param source the Matrix input for the function from which the corners will be extracted
     * @return std::vector<std::vector<cv::Point>> vector of points in a vector the inner vector contains all the points for a single detected "Shape". The outer
     * vector contains the different shapes.
     */
    static std::vector<std::vector<cv::Point>> GetCornerPoints(const cv::Mat& source, eColours colour);

    /**
     * @brief Extracts the colours from the input Matrix
     * 
     * @param input an input Matrix from out of which the colours will be extracted
     * @param colour the colour to extract from the input
     * @return cv::Mat This function returns a Matrix in which the colours from the image that fit between the thresholds get turned to white and all others are black 
     */
    static cv::Mat ExtractColours(const cv::Mat &rInput, eColours colour);

    /**
     * @brief Uses the Canny edge detection algorithm to detect all edges from the image NOTE: use after ExtractColours function for best results
     * 
     * @param input the input matrix from which to extract the edges
     * @return cv::Mat a Matrix which shows only edges as detected by the Canny algorithm
     */
    static cv::Mat ExtractEdges(const cv::Mat &input);

    /**
     * @brief Turns detected into contours
     * 
     * @param input the input matrix out of which the edges will be turned into contours
     * @return std::vector<std::vector<cv::Point>> This function returns a vector which contains another vector of points for each detected shape above a certain size
     */
    static std::vector<std::vector<cv::Point>> ExtractContours(const cv::Mat &input);

private:
    std::shared_ptr<CColour> m_spLookupColour;
    std::shared_ptr<CCalibration> m_spCalibration;
};

#endif /*CFEATUREEXTRACTION_H*/