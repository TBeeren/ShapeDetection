/**
 * @file CHalfCircle.h
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CHalfCircle is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CHALFCIRCLE_H
#define CHALFCIRCLE_H

#include "../CShape.h"

class CHalfCircle: public CShape 
{
public:
    CHalfCircle();
    virtual ~CHalfCircle();
    bool Process(std::vector<cv::Point> contour);
private:
    
};

#endif /*CHALFCIRCLE_H*/