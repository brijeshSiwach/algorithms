#include <iostream>
#include <csignal>

template<typename T>
class stack{

private:
	struct node{
		int val;
		node * next;
		node (int x){
			val = x;
			next = nullptr;
		}
	};

	node * front;

public:

	stack (){
		front = nullptr;
	}

	void push(T x){
		node * Node = new node(x);

		Node->next = this->front;
		this->front = Node;
	}

	bool empty(){
		return this->front == nullptr;
	}

	T top(){
		if(this->empty()){
			throw std::raise(SIGSEGV);
		}
		else {
			return this->front->val;
		}
	}

	void pop(){
		node * Node = this->front;
		this->front = this->front->next;
		delete(Node);
	}

};

int main(){
	stack<int> s;
	s.push(5);
	s.push(5);
	std::cout << s.top() << "\n";
	s.pop();
	s.pop();
	std::cout << s.empty() << "\n";

}