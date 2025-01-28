#include "main.h"

using namespace std;
int main(void){
    AbstractStack *stack = new ArrayStack(50);
    for (int i = 0; i < 60; i++) stack->push(1);
    cout << stack->stackSize() << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < 60; i++) stack->pop();
    cout << stack->stackSize() << endl;
    cout << "---------------" << endl;
}