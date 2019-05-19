#include "graphics.hpp"
#include "widgets.hpp"
#include "TextBox.hpp"

using namespace genv;

TextBox::TextBox(int x, int y, int sx, int sy)
    :Widget(x,y,sx,sy)
{
 szoveg="";
 _box=0;
 valasztva=false;
}


void TextBox::draw()
{

    gout<<color(0,0,0)<<move_to(_x,_y)<<box(_size_x,_size_y);
    gout<<color(255,255,255)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2);
    gout<<color(0,0,255)<<move_to(_x+_size_x/2-5,(_y+_size_y/2)+5)<<text(szoveg);


}

void TextBox::highlight(){
    gout<<color(0,0,0)<<move_to(_x,_y)<<box(_size_x,_size_y);
    gout<<color(255,230,80)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2);
    gout<<color(0,0,255)<<move_to(_x+_size_x/2-5,(_y+_size_y/2)+5)<<text(szoveg);
}

void TextBox::nohighlight(){
    gout<<color(0,0,0)<<move_to(_x,_y)<<box(_size_x,_size_y);
    gout<<color(255,255,255)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2);
    gout<<color(0,0,255)<<move_to(_x+_size_x/2-5,(_y+_size_y/2)+5)<<text(szoveg);
}

std::string TextBox::getvalue()
{
    return szoveg;
}

void TextBox::del(){
    szoveg="";
}


void TextBox::handle(event ev)
{
    if(gout.twidth(szoveg)==0)
      {
         if ( ev.type == ev_key && ev.keycode >= 49 &&  ev.keycode<= 57 && ev.keycode!=key_backspace && ev.keycode!=key_tab)
        {
            szoveg = szoveg + (char)ev.keycode;
        }
      }
         if( ev.type == ev_key && ev.keycode==key_backspace)
    {
        if(!szoveg.empty())
        szoveg.erase(prev(szoveg.end()));
    }

}

void TextBox::addvalue(char _new){
    szoveg=_new;
}

void TextBox::setvalue(std::vector<std::string> _list){

}

void TextBox::dilit(){
}

void TextBox::serror(){
    gout<<color(0,0,0)<<move_to(_x,_y)<<box(_size_x,_size_y);
    gout<<color(230,100,100)<<move_to(_x+1,_y+1)<<box(_size_x-2,_size_y-2);
    gout<<color(255,0,0)<<move_to(_x+_size_x/2-5,(_y+_size_y/2)+5)<<text(szoveg);
}

void TextBox::setbox(int b){
    _box=b;
}

int TextBox::getbox(){
    return _box;
}

