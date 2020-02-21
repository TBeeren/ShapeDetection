/**
 * @file CSquare.cpp
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CSquare is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "CSquare.h"

CSquare::CSquare()
    : CShape()
{
}

bool CSquare::Process(std::vector<cv::Point> corners)
{
    return(corners.size() == 4 && cv::isContourConvex(corners));
}