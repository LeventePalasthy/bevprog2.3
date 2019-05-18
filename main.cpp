#include "graphics.hpp"
#include "widgets.hpp"
#include "textbox.hpp"
#include <vector>
#include <iostream>
#include<fstream>
using namespace std;
using namespace genv;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = 0;
    while(gin >> ev && ev.keycode!=key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) focus=i;
            }
        }
        widgets[focus]->handle(ev);
        widgets[focus]->highlight();
        if(focus>=1){
                widgets[focus-1]->nohighlight();
            }
        if((unsigned) focus!=widgets.size()-1){
                    widgets[widgets.size()-1]->nohighlight();
                }
        if(ev.type==ev_key && ev.keycode==key_tab){
            focus++;
            if((unsigned) focus==widgets.size()){
                focus=0;
            }
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}

int main(){
    gout.open(400,400);
    gout<<move_to(0,0)<<color(150,150,150)<<box(400,400);
    vector<Widget*> w;
    TextBox* t1 = new TextBox(30,55,30,30);
    w.push_back(t1);
    for (Widget * wg : w){
        wg->draw();
    }
    gout << refresh;
    event_loop(w);
    return 0;
}
