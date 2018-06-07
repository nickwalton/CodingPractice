#include "StackNode.h"

template <class T>
class Stack{

    private:
        StackNode<T>* top;

    public:
        T pop();
        
        T peek();
        
        void push(T elem);
        
        bool isEmpty();

};

template <class T>
T Stack<T>::pop(){
    StackNode<T>* newTop = top->next;
    T returnVal = top->item;
    delete top;
    top = newTop;
    return returnVal;
}

template <class T>
T Stack<T>::peek(){
    return top->item;
}

template <class T>
void Stack<T>::push(T elem){
    StackNode<T>* newTop = new StackNode<T>(elem);
    newTop->next = top;
    top = newTop;
}

template <class T>
bool Stack<T>::isEmpty(){
    return (top == 0);
}

