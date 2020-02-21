/**
 * @file CTriangle.cpp
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CTriangle is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CTriangle.h"

CTriangle::CTriangle()
: CShape()
{
}

bool CTriangle::Process(std::vector<cv::Point> corners)
{
    return(corners.size() == 3  && cv::isContourConvex(corners));
}