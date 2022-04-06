#include <iostream>
#include <string>
#include <vector>
#include <cassert>


using namespace std;


template<typename T>
struct Stack {
    struct Node {
        T value;
        Node *next = nullptr;
    };

    void push(T const& value){
        storage_.push_back(Node{});
        Node *new_top = &storage_.front();
//        auto new_top = new Node;
        new_top->value = value;
        new_top->next = top_;
        top_ = new_top;
        size_++;
    }

    T pop(){
       if(empty())
           throw std::runtime_error("Nothing to pop");
       T ret = top_->value;
       Node * next = top_->next;
//       delete top_;

       top_ = next;
       size_--;
       return ret;
    }

    T& top(){
        if(empty())
            throw std::runtime_error("stack is empty!");
        return top_->value;
    }

    size_t size() {
        return size_;
#if 0
        Node *it = top_;
        size_t sz = 0;
        while (it != nullptr) {
            ++sz;
            it = it->next;
        }
        return sz;
#endif
    }

    bool empty(){ return size() == 0; }

private:
    size_t size_ = 0;
    Node *top_ = nullptr;
    std::vector<Node> storage_;
};


int main(){
    Stack<string> mystackstr;

/*
    Stack<int> mystack;
    assert(mystack.empty());
    mystack.push(123);
    assert(mystack.size() ==  1);
    int x = mystack.pop();
    assert(x == 123);
    assert(mystack.empty());

    for(int i =1; i<=100; i++){
        mystack.push(i*i);
        cout << i << " ";
    }
    cout << endl;
    assert(mystack.size() == 100);
    assert(mystack.top() == 10000);
    mystack.pop();
    assert(mystack.top() == 99*99);
    cout << endl<< "pop: "<< endl;
    for(int i=1; i<=98; i++){
        auto y = mystack.pop();
        cout << y << " ";
    }
    cout << "pop end"<< endl;
    assert(mystack.size() == 1);
    x = mystack.pop();
    assert(x == 1);
    assert(mystack.empty());

    try {
        x = mystack.pop();
    }catch(std::exception const&ex){
        cout << "ERR: " << ex.what() <<endl;
    }*/
}
