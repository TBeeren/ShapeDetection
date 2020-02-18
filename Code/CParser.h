/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief The CParser class is responsible for reading and parsing commands from the given inputfile. 
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CTRACKBAR_H
#define CTRACKBAR_H

#include "ESelections.h"

class CParser
{
public:
    CParser(eShapes rSelectedShape, eColours rSelectedColour);
    ~CParser();

    /**
     * @brief Parses all commands from an input file and translates
     *        it to an action in the system.
     * 
     * @param rFilename: The input file given by the user as input.
     */
    void ParseFile(std::ifstream& rFilename);

    /**
     * @brief Checks if the given colour is configured for the program.
     * 
     * @param colourArgument: Given colour argument of the command. 
     * @return true, if the colour is specified in the configuration.
     * @return false, if the colour isn't specified in the program. 
     */
    bool IsConfiguredAsColour(const std::string& colourArgument);

    /**
     * @brief Checks if the given shape is configured for the program.
     * 
     * @param shapeArgument: Given shape argument of the command. 
     * @return true, if the shape is specified in the configuration.
     * @return false, if the shape isn't specified in the program. 
     */
    bool IsConfiguredAsShape(const std::string& shapeArgument);

private:
    eShapes& m_rSelectedShape;
    eColours& m_rSelectedColour;

    std::string m_firstArgument;
    std::string m_secondArgument;
};

#endif /*CTRACKBAR_H*/