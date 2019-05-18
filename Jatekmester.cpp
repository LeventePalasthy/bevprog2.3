#include "graphics.hpp"
#include "widgets.hpp"
#include "Jatekmester.hpp"
#include "TextBox.hpp"
#include <iostream>

using namespace genv;

Jatekmester::Jatekmester(int x, int y, int sx, int sy)
    :Widget(x,y,sx,sy)
{
 valasztva=false;
}

void Jatekmester::handle(genv::event ev){
    gout.open(400,400);
    std::vector<Widget*> widgets;
    gout<<move_to(0,0)<<color(150,150,150)<<box(400,400);
    for(unsigned i=0; i<9; i++){
        for (unsigned j=0; j<9; j++){
            TextBox* n=new TextBox(35+35*i,35+35*j,35,35);
            widgets.push_back(n);
        }
    }

    for (Widget * wg : widgets){
        wg->draw();
    }
    int focus = 0, _last=0;
    while(gin >> ev && ev.keycode!=key_escape){
        //if(ev.type==ev.button && ev.keycode==key_down && focus<=71) focus+=9;
        for(unsigned i=0; i<widgets.size(); i++){
        if (ev.type == ev_mouse && ev.button==btn_left){
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) focus=i;
            }
        }
        widgets[focus]->handle(ev);
        for(unsigned j=0; j<widgets.size();j++)
        for(unsigned i=0; i<widgets.size();i++){
            if(((unsigned) j%9==i%9 || (unsigned) j/9==i/9/* || widgets[focus]->_box==widgets[i]->_box*/) && widgets[j]->getvalue()==widgets[i]->getvalue() && widgets[j]->getvalue()!="" && (unsigned)j!=i){
                widgets[i]->serror();
                widgets[j]->serror();
            }
        }
        if((unsigned) focus!=widgets.size()-1){
                    widgets[widgets.size()-1]->nohighlight();
                }
        /*for (Widget * w : widgets) {
            w->draw();
        }*/
        widgets[_last]->draw();
        widgets[focus]->highlight();
        _last=focus;
    }
    gout << refresh;
    }
}

void Jatekmester::draw()
{

}

void Jatekmester::highlight(){

}

void Jatekmester::nohighlight(){

}

std::string Jatekmester::getvalue()
{
    return "It's working!!!";
}

void Jatekmester::del(){
}



void Jatekmester::addvalue(std::string _new){

}

void Jatekmester::setvalue(std::vector<std::string> _list){

}

void Jatekmester::dilit(){
}

void Jatekmester::serror(){
};
