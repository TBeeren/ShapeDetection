/**
 * @file CCommandMode.h
 * @author Evren Kilic (ET.Kilic@student.han.nl), Tim Beeren (T.Beeren1@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 06-02-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CCOMMANDMODE_H
#define CCOMMANDMODE_H

#include "CMode.h"

//Forward Declarations
class CParser;

class CCommandMode : public CMode
{
public:
    CCommandMode();
    virtual ~CCommandMode();

private:
    std::shared_ptr<CParser> m_spParser;

};

#endif /*CCOMMANDMODE_H*/