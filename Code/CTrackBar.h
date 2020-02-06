#ifndef CTRACKBAR_H
#define CTRACKBAR_H

#include <string>

#include "ESelections.h"
#include <memory>

template<typename T>
class CTrackBar
{
public:
    CTrackBar(std::shared_ptr<T> value, uint8_t count): m_Selection(eSelection), m_Count(count) {};
    ~CTrackBar();

    void Create();
    void TriggerCallback();

private:
    std::string m_windowName;
    std::shared_ptr<T> value;
    uint8_t m_Count;
};

#endif /*CTRACKBAR_H*/