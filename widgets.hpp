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
    virtual void draw() = 0;
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void handle(genv::event ev) =0;
    virtual void highlight();
    virtual void nohighlight();
    virtual std::string getvalue()=0;
    virtual void del()=0;
    virtual void setvalue(std::vector<std::string> _list)=0;
    virtual void addvalue(std::string _new)=0;
    virtual void dilit()=0;
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
