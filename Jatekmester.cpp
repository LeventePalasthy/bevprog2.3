#include "graphics.hpp"
#include "widgets.hpp"
#include "Jatekmester.hpp"
#include "TextBox.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace genv;

Jatekmester::Jatekmester(int x, int y, int sx, int sy)
    :Widget(x,y,sx,sy)
{
 valasztva=false;
}

void Jatekmester::handle(genv::event ev){
    gout.open(400,400);
    std::vector<Widget*> widgets;
    gout<<move_to(0,0)<<color(150,150,150)<<box(400,400)<<move_to(20,370)<<color(0,0,0)<<text("Press r to start a new game");

    std::ifstream bf("sud1.txt");
    std::string _code;
    int puzzles=4;
    srand(time(0));
    int wo=rand()%puzzles+1;
    for(int i=0;i<wo;i++){
        getline(bf,_code);
    }
    for(unsigned i=0; i<9; i++){
        for (unsigned j=0; j<9; j++){
            TextBox* n=new TextBox(35+35*i,35+35*j,35,35);
            if(_code[9*i+j]!=';') n->addvalue(_code[9*i+j]);
            n->setbox(j/3*3+i/3);
            widgets.push_back(n);
        }
    }
    bf.close();

    for (Widget * wg : widgets){
        wg->draw();
    }
    int focus = 0;
    while(gin >> ev && ev.keycode!=key_escape){
        if(ev.type==ev_key && ev.keycode==key_down && focus%9!=8) focus++;
        if(ev.type==ev_key && ev.keycode==key_up && focus%9!=0) focus--;
        if(ev.type==ev_key && ev.keycode==key_right && focus<=71) focus+=9;
        if(ev.type==ev_key && ev.keycode==key_left && focus>=8) focus-=9;
        if(ev.type==ev_key && ev.keycode==114){
            std::ifstream bf("sud1.txt");
            widgets.clear();
            int wo=rand()%puzzles+1;
            for(int i=0;i<wo;i++){
                getline(bf,_code);
            }
            for(unsigned i=0; i<9; i++){
                for (unsigned j=0; j<9; j++){
                    TextBox* n=new TextBox(35+35*i,35+35*j,35,35);
                    if(_code[9*i+j]!=';') n->addvalue(_code[9*i+j]);
                    n->setbox(j/3*3+i/3);
                    widgets.push_back(n);
                }
            }
            bf.close();
        }
        for(unsigned i=0; i<widgets.size(); i++){
        if (ev.type == ev_mouse && ev.button==btn_left){
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) focus=i;
            }
        }
        widgets[focus]->handle(ev);
        for (unsigned j=0;j<widgets.size();j++){
        bool _error=false;
        for(unsigned i=0; i<widgets.size();i++){
            if((j%9==i%9 || j/9==i/9 || widgets[j]->getbox()==widgets[i]->getbox()) && widgets[j]->getvalue()==widgets[i]->getvalue() && widgets[j]->getvalue()!="" && j!=i){
                _error=true;
        }
        }
        if(_error) widgets[j]->serror();
        else widgets[j]->draw();
        }
        widgets[focus]->highlight();
    }
    gout << refresh;



    bool _done=true;
    for (unsigned j=0;j<widgets.size();j++){
        for(unsigned i=0; i<widgets.size();i++){
            if((j%9==i%9 || j/9==i/9 || widgets[j]->getbox()==widgets[i]->getbox()) && widgets[j]->getvalue()==widgets[i]->getvalue() && widgets[j]->getvalue()!="" && j!=i){
                _done=false;
        }
        }
        if(widgets[j]->getvalue()=="") _done=false;
    }
    if(_done){
        gout<<move_to(20,390)<<color(0,0,0)<<text("Congratulations, You won the game");
    }
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



void Jatekmester::addvalue(char _new){

}

void Jatekmester::setvalue(std::vector<std::string> _list){

}

void Jatekmester::dilit(){
}

void Jatekmester::serror(){
};

void Jatekmester::setbox(int b){
};

int Jatekmester::getbox(){
};
