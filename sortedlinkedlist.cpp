#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next;
  Node(int data = NULL, Node *ptr = NULL) {
    value = data;
    next = ptr;
  }~Node() {}

  int nextvalue() {
    return next -> value;
  }

};

class SLL {
  public:
    Node *front;
    int Count = NULL;

  SLL() {
      front = NULL;
  }

  ~SLL() {
      cout << "List was deconstructed" << endl;
  }

  void print() {
    cout << "List in sorted position: ";
    for (Node *temp = front; temp != NULL; temp = temp -> next)
      cout << temp -> value << " ";
    cout << endl;
  }

  void insertionsort(int data) {
    Node *n = new Node(data);
    if (Count == NULL) {
      front = n;
    } else {
      if (data < front -> value) {
        n -> value = data;
        n -> next = front;
        front = n;
      } else {
        for (Node *temp = front; temp != NULL; temp = temp -> next) {
          if (temp -> next == NULL) {
            temp -> next = n;
            break;
          }
          if (data > temp -> value && data < temp -> nextvalue()) {
            n -> next = temp -> next;
            temp -> next = n;
            break;
          }
        }
      }
    }
    Count++;
  }


};

int main(void) {
  int temp1;
  SLL list;
  
  while(true){
    cout << "Enter a number: ";
    cin >> temp1;
    if(temp1 == -1)
      break;
    list.insertionsort(temp1);
    list.print();
  }


  cout << "You entered -1." << endl;

  return 0;
}
