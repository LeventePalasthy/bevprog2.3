#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x+_size_y && mouse_y>_y && mouse_y<_y+_size_y;
}

/*void Widget::highlight()
{
}

void Widget::nohighlight()
{
  gout<<color(0,0,0)<<move_to(_x+_size_x+_size_y/2+5,_y+_size_y/2)<<line(6,10)<<line(10,-20);
}*/


