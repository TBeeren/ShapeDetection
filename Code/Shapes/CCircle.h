/**
 * @file CCircle.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CCircle is the derived class from CShape, it required the functions and members of a shape.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "../CShape.h"

class CCircle: public CShape
{
public:
    CCircle();
    virtual ~CCircle() = default;
    
    bool Process(std::vector<cv::Point> contour) override;
private:
    /* data */
};

#endif /*CCIRCLE_H*/