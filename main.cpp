#include "widgets.hpp"
#include "Jatekmester.hpp"
using namespace genv;

int main(){
    event ev;
    Jatekmester* sudoku= new Jatekmester(0,0,400,400);
    sudoku->handle(ev);
    return 0;
}
