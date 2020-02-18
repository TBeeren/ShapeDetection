/**
 * @file CColour.h
 * @author Tim Beeren (T.Beeren@student.han.nl) Stijn Krabbenborg (S.Krabbenborg@student.han.nl) Evren Kilic (ET.Kilic@student.han.nl)
 * @brief CMode is the abraction layer for CCommandMode and CInteractiveMode. It provides the CMode functions for multiple modes.
 * @version 0.1
 * @date 07-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CMODE_H
#define CMODE_H

#include <memory>
#include <iostream>

#include "ESelections.h" 

//Forward declarations
class CFeatureExtraction;
class CFeatureDetection;

class CMode
{
public:
    CMode();
    virtual ~CMode();
    
    /**
    * @brief Initializes variables for the specified CMode.
    * 
    * @return true, If the initialisation flow worked correctly.
    * @return false, if there's a mistake during the init process.
    */
    virtual bool Init() = 0; 
    
    /**
     * @brief Execute the program and fixes thread boundries if needed.
     * 
     */
    virtual void Execute() = 0;

protected:
    eShapes m_selectedShape;
    eColours m_selectedColour;

private:
    std::shared_ptr<CFeatureExtraction> m_spFeatureExtraction;
    std::shared_ptr<CFeatureDetection> m_spFeatureDetection;
};

#endif /*CMODE_H*/
