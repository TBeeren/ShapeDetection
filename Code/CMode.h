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
    ~CMode();
    
    virtual bool Init() = 0; 
    virtual void Execute() = 0;

protected:
    eShapes m_SelectedShape;
    eColours m_SelectedColour;

private:
    std::shared_ptr<CFeatureExtraction> m_spFeatureExtraction;
    std::shared_ptr<CFeatureDetection> m_spFeatureDetection;
};

#endif /*CMODE_H*/
