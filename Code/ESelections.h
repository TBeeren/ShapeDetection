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

#ifndef ESELECTIONS_H
#define ESELECTIONS_H

#include <string>
#include <map>

enum eShapes 
{
    TRIANGLE,
    SQUARE,
    CIRCLE,
    HALF_CIRCLE,
    END_OF_SHAPES
};

enum eColours
{
    RED,
    BLUE,
    GREEN,
    YELLOW,
    WHITE,
    BLACK,
    END_OF_COLOURS
};

static std::map<eColours, std::string> configuredColours=
{
    {eColours::RED, "RED"},
    {eColours::BLUE, "BLUE"},
    {eColours::GREEN, "GREEN"},
    {eColours::YELLOW, "YELLOW"},
    {eColours::BLACK, "BLACK"},
    {eColours::WHITE, "WHITE"}
};

#endif /*ESELECTIONS_H*/