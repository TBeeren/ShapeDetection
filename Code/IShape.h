#ifndef ISHAPE_H
#define ISHAPE_H

#include <string>

class IShape
{
public:
    IShape(/* args */);
    ~IShape();
    virtual bool Process() = 0;
private:
    std::string m_label;
};

#endif /*ISHAPE_H*/