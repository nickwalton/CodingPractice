#include "Stack.h"
#include <iostream> 

using namespace std;

int main(){

    Stack<int> stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    
    cout << stack.pop() << " ";
    cout << stack.pop() << " ";
    cout << stack.pop() << endl;
}
