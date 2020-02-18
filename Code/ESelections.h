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

<<<<<<< HEAD
=======
#include <string>
>>>>>>> d6d5bd8bc361a15deecb502208b9681118ad8304
#include <map>

enum eShapes 
{
    TRIANGLE = 0,
    SQUARE = 1,
    CIRCLE = 2,
    HALF_CIRCLE = 3,

    END_OF_SHAPES = 4
};

static std::map<eShapes, std::string> configuredShapes=
{
    {eShapes::TRIANGLE, "TRIANGLE"},
    {eShapes::SQUARE, "SQUARE"},
    {eShapes::CIRCLE, "CIRCLE"},
    {eShapes::HALF_CIRCLE ,"HALF_CIRCLE"}
};

enum eColours
{
    RED = 0,
    BLUE = 1,
    GREEN = 2,
    YELLOW = 3,
    BLACK = 4,
    WHITE = 5,

    END_OF_COLOURS = 6
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