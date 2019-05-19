#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <string.h>
#include <vector>

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual void draw()=0;
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void handle(genv::event ev) =0;
    virtual void highlight()=0;
    virtual void nohighlight()=0;
    virtual std::string getvalue()=0;
    virtual void del()=0;
    virtual void setvalue(std::vector<std::string> _list)=0;
    virtual void addvalue(char _new)=0;
    virtual void dilit()=0;
    virtual void serror()=0;
    virtual void setbox(int b)=0;
    virtual int getbox()=0;
};

#endif // WIDGETS_HPP_INCLUDED
