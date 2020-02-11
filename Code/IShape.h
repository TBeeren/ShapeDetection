/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ISHAPE_H
#define ISHAPE_H

#include <string>

class IShape
{
public:
    IShape(/* args */);
    ~IShape();
    virtual bool Process() = 0;
private:
    std::string m_label;
};

#endif /*ISHAPE_H*/