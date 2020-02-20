/**
 * @file CSquare.h
 * @author Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CSquare is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 20-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CSQUARE_H
#define CSQUARE_H

#include "../CShape.h"

class CSquare: public CShape
{
public:
    CSquare();
    virtual ~CSquare();

    bool Process(std::vector<cv::Point> contour);
private:
    
};

#endif /*CSQUARE_H*/