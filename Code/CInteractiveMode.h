/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class makes the interactive mode. It asks a shape and colour from the user. 
 * If he enters a valid shape and colour, the shape detection will start.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CINTERACTIVEMODE_H
#define CINTERACTIVEMODE_H

#include "CMode.h"
#include "ESelections.h"

//Forward Declarations
class CViewWindow;

class CInteractiveMode : public CMode
{
public:
    CInteractiveMode();
    virtual ~CInteractiveMode();

    /**
     * @brief Initializes the shape and color that the user gives in the commandline
     * 
     * @return true, if the shape and color is correct, proceed.
     * @return false, if the shape and color is not correct, try again.
     */
    bool Init();

    /**
     * @brief Executes the program
     * 
     */
    void Execute();

    /**
     * @brief This function checks for a valid shape user input.
     * 
     * @param aShape, the input value of a shape by the user.
     * @return true, if the given shape matches with a shape in configuredShapes.
     * @return false, if the given shape doesn't matches a shape in configuredShapes.
     */
    bool checkShapeInput(std::string aShape);

    /**
     * @brief This function checks for a valid colour user input.
     * 
     * @param aColour, the input value of acolour by the user.
     * @return true, if the given colour matches with a colour in configuredShapes.
     * @return false, if the given colour doesn't matches a colour in configuredShapes.
     */
    bool checkColourInput(std::string aColour);

private:
    std::shared_ptr<CViewWindow> m_spViewWindow;

    enum eShapes m_shape;
    enum eColours m_colour;
};

#endif /*CINTERACTIVEMODE_H*/
