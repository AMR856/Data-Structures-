#include "main.h"

using namespace std;
int main(void){
    AbstractStack *stack = new LinkedListStack();
    for (int i = 0; i < 50; i++) stack->push(i);
    for (int i = 0; i < 50; i++) stack->pop();
    cout << stack->stackSize() << endl;
    cout << stack->top() << endl;
}