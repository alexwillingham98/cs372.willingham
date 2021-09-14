#include "cs372Deque.h"
template <typename T>
class List {
private :
    Deque<T> ∗aDeque ;
    public :
    = new
    Deque<T>() ;
    Queue() {}
    Queue(Queue &rhs ) {}
    ~Queue () { delete aDeque;}
    bool empty() {return aDeque.empty();}
    void push(T data) {aDeque.push_front(data);}
    T pop() {return aDeque.pop_back()}
    void traverse(void (*doIt)(T data)){
        aDeque.traverse(doIt);
    };
}

