#include <iostream>
using namespace std;

struct Node{
  int value;
  Node *next;
  ~Node(){
    cout << "Node was deconstructed" << endl;
  }
};


class List {
  public:
    Node* top;
    int Count = 0;
    ~List() {
      cout << "List was deconstructed" << endl;
    }

  bool isEmpty() {
    return top == NULL;
  }

  void push(int data) {
    Node *temp = new Node();
    temp -> value = data;
    temp -> next = top;
    top = temp;
    Count+=1;
  }

  void pop() {

    cout << "Count: " << Count << endl;
    if((Count-1) == 0 || Count == 0){
      top = NULL;
      cout << "The stack is empty: " << endl;
      Count--;
    }
    else{
      Node* temp = top;
      cout << "Popped Value: " << temp -> value << endl;
      top = top -> next;
      delete(temp);
      Count--;
    }
  }


  void print() {
    cout << "The stack (from the top): " << endl;
    for (Node * temp = top; temp != NULL; temp = temp -> next)
      cout << endl << temp -> value << " " << endl;
    cout << endl;
}

};

int main(void) {
  List stack;
  stack.push(4);
  stack.push(9);
  stack.push(10);
  stack.print();

  return 0;
}