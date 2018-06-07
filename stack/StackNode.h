template <class T>
class StackNode{
    
    public:
    
        T item;
        StackNode<T>* next;
    
        StackNode(T newItem){
            item = newItem;
        }
};
