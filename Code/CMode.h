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

#include "opencv2/imgcodecs.hpp"

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

    /**
     * @brief Converts a string to an enum.
     * 
     * @param colourString, the colour input string of the user.
     * @return eColours, returns the enum. 
     */
    eColours StringToColour(const std::string& colourString);

    /**
     * @brief Converts a string to an enum.
     * 
     * @param shapeString, the shape input string of the user.
     * @return eShapes, returns the enum.
     */
    eShapes StringToShape(const std::string& shapeString);
    
    /**
     * @brief 
     * 
     * @param eColour 
     * @return const std::string& 
     */
    const std::string& ColourToString(eColours eColour);

    /**
     * @brief 
     * 
     * @param eShape 
     * @return const std::string& 
     */
    const std::string& ShapeToString(eShapes eShape);

    /**
     * @brief Is the shape that will be detected.
     * 
     */
    eShapes m_selectedShape;

    /**
     * @brief Is the colour that will be detected.
     * 
     */
    eColours m_selectedColour;

private:
    std::shared_ptr<CFeatureExtraction> m_spFeatureExtraction;
    std::shared_ptr<CFeatureDetection> m_spFeatureDetection;
};

#endif /*CMODE_H*/
