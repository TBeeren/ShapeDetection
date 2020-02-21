/**
 * @file CShape.cpp
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief The abstract class for all shapes. It can also has functions to call to determine whether a shape has an elongated side, which is useful for detecting half circles.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "CShape.h"

CShape::CShape()
{
}

CShape::~CShape()
{
}

float CShape::DistanceBetweenCorners(cv::Point point1, cv::Point point2)
{
    float x = point1.x - point2.x;
    float y = point1.y - point2.y;
    return sqrt((x * x) + (y * y));
}

bool CShape::HasElongatedSide(std::vector<cv::Point> contour)
{
    std::vector<float> distances;
    for (uint64_t i = 0; i < contour.size() - 1; ++i)
    {
        distances.push_back(DistanceBetweenCorners(contour.at(i), contour.at(i + 1)));
    }

    distances.push_back(DistanceBetweenCorners(contour.at(0), contour.at(contour.size() - 1)));
    std::sort(distances.begin(), distances.end());

    return (distances.at(distances.size()-1) / (distances.at(distances.size() / 2)) > 2.0);
}