/**
 * @file CTriangle.h
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CTriangle is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "../CShape.h"

class CTriangle: public CShape
{
public:
    CTriangle();
    virtual ~CTriangle() = default;

    bool Process(std::vector<cv::Point> contour) override;
private:
    
};

#endif /*CTRIANGLE_H*/