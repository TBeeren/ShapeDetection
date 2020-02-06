#ifndef CMODE_H
#define CMODE_H

#include <memory>

#include "ESelections.h" 

//Forward declarations
class CFeatureExtraction;
class CFeatureDetection;

class CMode
{
public:
    CMode();
    ~CMode();

private:
    std::shared_ptr<CFeatureExtraction> m_spFeatureExtraction;
    std::shared_ptr<CFeatureDetection> m_spFeatureDetection;

    eShapes m_SelectedShape;
    eColours m_SelectedColour;
};

#endif /*CMODE_H*/
