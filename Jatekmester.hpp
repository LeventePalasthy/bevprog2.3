#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP
#include <string>
#include "widgets.hpp"
#include "graphics.hpp"

class Jatekmester: public Widget
{
protected:
    bool valasztva;
public:
    Jatekmester(int x, int y, int sx, int sy);

    virtual void draw();

    virtual void highlight();

    virtual void nohighlight();

    virtual void handle(genv::event ev);

    virtual std::string getvalue();

    virtual void del();

    virtual void setvalue(std::vector<std::string> _list);

    virtual void addvalue(std::string _new);

    virtual void dilit();

    virtual void serror();

    virtual void setbox(int b);

    virtual int getbox();
};

#endif
