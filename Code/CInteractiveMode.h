/**
 * @file CInteractiveMode.h
 * @author Evren Kilic (ET.Kilic@student.han.nl), Tim Beeren (T.Beeren1@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 06-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CINTERACTIVEMODE_H
#define CINTERACTIVEMODE_H

#include "CMode.h"

//Forward Declarations
class CViewWindow;

class CInteractiveMode : public CMode
{
public:
    CInteractiveMode();
    virtual ~CInteractiveMode();

private:
    std::shared_ptr<CViewWindow> m_spViewWindow;
};

#endif /*CINTERACTIVEMODE_H*/
