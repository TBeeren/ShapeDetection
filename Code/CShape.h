/**
 * @file CShape.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief The abstract class for all shapes. It can also has functions to call to determine whether a shape has an elongated side, which is useful for detecting half circles.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef CSHAPE_H
#define CSHAPE_H

#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

class CShape
{
public:
    CShape();
    ~CShape();

    /**
     * @brief the function that should be called to match this "shape" to a contour
     * 
     * @param contour the contour of which to determine whether it resembles this shape.
     * @return true the function returns true when the shapes match.
     * @return false the function returns false when the shapes don't match.
     */
    virtual bool Process(std::vector<cv::Point> contour) = 0;
protected:
    /**
     * @brief HasElongatedSide determines whether a shape has one side which is considerably longer than other sides. This function is mostly used to separate halfcircles from circles.
     * 
     * @param contour the contour of which to determine whether it has an elongated side
     * @return true returns true when the shape has an elongated side.
     * @return false returns false when the shade does not have an elongated side.
     */
    bool HasElongatedSide(std::vector<cv::Point> contour);
private:
    /**
     * @brief a private function to calculate the distance between two points
     * 
     * @param point1 point A for the calculation
     * @param point2 point B for the calculation
     * @return float the distance between point A and B
     */
    float DistanceBetweenCorners(cv::Point point1, cv::Point point2);
    std::string m_label;
};

#endif /*CSHAPE_H*/