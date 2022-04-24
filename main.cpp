#include <iostream>

using namespace std; 

class Node{
public:
  int data;
  Node* next;
};
class Queue{
private:  
  Node* front; 
  Node* rear; 
  int count; 

public:
  void enqueue();
  void dequeue();
  bool isEmpty();
  void printCount(); 
  Queue(){
    front = NULL;
    rear = NULL;
    count = 0; 
  }
};

int main() {
  Queue test; 
  test.dequeue(); // Should return that the queue is empty
  cout << test.isEmpty() << endl; // Should return 1 for true
  test.enqueue();
  test.printCount(); // Should print 1 item in queue
  cout << endl << test.isEmpty() << endl; 
  test.dequeue();
  test.printCount(); 
  test.enqueue();
  test.enqueue();
  test.enqueue();
  test.enqueue();
  test.dequeue();
  test.printCount(); // Should print 3 items in queue
  cout << endl << test.isEmpty(); // Should 0 print false.
}

void Queue::enqueue(){
  int _data;
  Node* temp = new Node;
  cout<<"Enter the data to enqueue: ";
  cin>>_data;
  temp->data = _data;
  temp->next = NULL;
  if(front == NULL){
    front = temp;
  }
  else{
  rear->next = temp;
  }
  rear = temp;
  this->count++;
}

void Queue::dequeue(){
  Node* temp = new Node;
  if(front == NULL){
  cout<<"\nQueue is Empty\n";  
  }
  else{
  temp = front;
  front = front->next;
  cout<<"The data Dequeued is "<<temp->data << "\n";
  delete temp;
  this->count--;
  }
}

bool Queue::isEmpty(){
  if(front == NULL){
    return true;
  }
  else{
    return false; 
  }
}
void Queue::printCount(){
  cout << "\n" << this->count << " items are in the queue\n"; 
}

//Output from main
/* 
Queue is Empty
1
Enter the data to enqueue: 10

1 items are in the queue

0
The data Dequeued is 10

0 items are in the queue
Enter the data to enqueue: 10
Enter the data to enqueue: 12
Enter the data to enqueue: 14
Enter the data to enqueue: 16
The data Dequeued is 10

3 items are in the queue

0
*/