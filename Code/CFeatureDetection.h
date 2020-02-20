/**
 * @file CFeatureDetection.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class is responsible for processing detecting data from the, by the CFeatureExtraction extracted, data. It provides functions to filter on a shape and 
 * find middlepoints aswell as surface areas.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "ESelections.h"

#include "stdint.h"
#include "opencv2/opencv.hpp"
#include <vector>
#include <memory>

class CShape;
class CFeatureDetection
{
public:
    CFeatureDetection();
    ~CFeatureDetection();

    /**
     * @brief Set the Shape object the set shape will be used as a strategy to process incoming contours.
     * 
     * @param shape a shape in eShapes which will be translated to a realisation of the shape interface
     */
    void SetShape(eShapes shape);

    /**
     * @brief This function filters all the contours down to the contours that match the shape that has been set for this instance of CFeatureDetection
     * 
     * @param rAllContours all the contours of a specific colour as was returned by CFeatureExtraction
     * @return std::vector<std::vector<cv::Point>> a filtered list of contours that match the set shape
     */
    std::vector<std::vector<cv::Point>> ShapeFilter(const std::vector<std::vector<cv::Point>>& rAllContours);

    /**
     * @brief Finds the geometric centre for a contour
     * 
     * @param rContour a contour from which the geometric centre will be calculated
     * @return cv::Point the geometric centre for the given contour
     */
    cv::Point FindCenter(const std::vector<cv::Point>& rContour);

    /**
     * @brief Calculates the surface area for the given contour
     * 
     * @param rContour a contour from which the surface area will be calculated
     * @return uint64_t the surface area for the given contour
     */
    uint64_t CalcSurfaceArea(const std::vector<cv::Point>& rContour);
 
private:
    std::shared_ptr<CShape> m_spShape;
};
