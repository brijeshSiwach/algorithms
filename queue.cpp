#include <iostream>
#include <csignal>

using namespace std;

template<typename T> 
class queue{

private:
    struct node{
        T val;
        node * next;
        node(T v){
            val = v;
            next = nullptr;
        }
    };

    node *Front, *rear;

    void push_element(T x){
        node * Node = new node(x);
        if(this->rear == nullptr){
            this->Front = this->rear = Node;
            return;
        }
        this->rear->next = Node;
        this->rear = Node;
        return;
    }

    void pop_element(){
        node * Node = this->Front;
        this->Front = this->Front->next;

        if(this->Front == nullptr){
            this->rear = nullptr;
        }

        delete(Node);

        return;
    }

    T front_element(){
        return this->Front->val;
    }

    bool is_empty(){
        return this->Front == nullptr;
    }


public:

    queue (){
        
        Front = rear = nullptr;
    }



    void pop(){
        if (this->is_empty()){
            cout << "ok\n";
            throw std::raise(SIGSEGV);
        }
        else {
            this->pop_element();
        }
    }

    void push(T x){
        push_element(x);
    }

    T front(){
        if(this->is_empty()){
            throw std::raise(SIGSEGV);
        }
        else{
            return this->front_element();
        }
    }

    bool empty(){
        return this->is_empty();
    }

};


int main(){
    queue<int> q;

    q.push(4);

    queue<string> Q;
    Q.push("abc");
}