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
  void print();
  Queue(){
    front = NULL;
    rear = NULL;
    count = 0; 
  }
};

int main() {
  Queue test; 
  cout << test.isEmpty() << endl; 
  test.enqueue();
  cout << test.isEmpty() << endl; 
  test.dequeue();
  test.enqueue();
  test.enqueue();
  test.enqueue();
  test.enqueue();
  test.dequeue();
  cout << test.isEmpty() << endl;   
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
  count++;
}

void Queue::dequeue(){
  Node* temp = new Node;
  if(front == NULL){
  cout<<"\nQueue is Emtpty\n";  
  }
  else{
  temp = front;
  front = front->next;
  cout<<"The data Dequeued is "<<temp->data << "\n";
  delete temp;
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

void Queue::print(){
  Node* temp = new Node(); 
  temp = front; 
  while(temp->next != NULL){
    cout << temp->data << " ";
    temp->next = temp; 
  }
}