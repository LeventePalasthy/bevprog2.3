#include "widgets.hpp"
#include "textbox.hpp"
#include "Jatekmester.hpp"
#include <iostream>
using namespace std;
using namespace genv;



int main(){
    event ev;
    TextBox* t1=new TextBox(0,0,40,40);
    Jatekmester* sudoku= new Jatekmester(0,0,400,400);
    sudoku->handle(ev);
    return 0;
}
