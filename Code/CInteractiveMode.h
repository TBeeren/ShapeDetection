/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief This class has two functions: Init() and Execute().
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

private:
    std::shared_ptr<CViewWindow> m_spViewWindow;

    enum eShapes shape = END_OF_SHAPES;
    enum eColours color = END_OF_COLOURS;
};

#endif /*CINTERACTIVEMODE_H*/
