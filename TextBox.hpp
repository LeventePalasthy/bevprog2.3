#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include <string>
#include "widgets.hpp"
#include "graphics.hpp"

class TextBox: public Widget
{
protected:
    std::string szoveg;
    int _box;
    bool valasztva;
public:
    TextBox(int x, int y, int sx, int sy);

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
};

#endif
