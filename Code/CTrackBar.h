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

#ifndef CTRACKBAR_H
#define CTRACKBAR_H

#include <string>
#include <memory>

#include "ESelections.h"

template<typename T>
class CTrackBar
{
public:
    CTrackBar(std::shared_ptr<T> value, uint8_t count): m_value(value), m_count(count) {}
    ~CTrackBar() = default;

    void Create();
    void TriggerCallback();

private:
    std::string m_windowName;
    std::shared_ptr<T> m_value;
    uint8_t m_count;
};

#endif /*CTRACKBAR_H*/