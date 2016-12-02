#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node* next;
  Node* prev;
  Node(int val){
    cout << "Node constructor!" << endl;
    this->value=val;
    this->next=(Node*)0;
    this->prev=(Node*)0;
  }
  ~Node(){
    cout << "Node destructor" << endl;
    cout << "I had the value "<<this->value << endl;
  }
};
class List
{

public:
  Node* head;
  Node* tail;

  List(){
    cout << "List Constructor!" << endl;
    this->head=0;
    this->tail=0;
  }
  ~List(){
    cout << "List destructor!" << endl;
    cout << "Todo: properly delete nodes..." << endl;
  }

  void remove(Node* n){                //removes pointers and deletes node
  if (n->prev!=0){              //if it is not the first node in the list,
    n->prev->next=n->next;      //changes previous node's pointer to the next node
    }
  else{
    this->head=n->next;         //make the next node the first node in the list
    }
  if (n->next!=0){              //if it is not the last node in the list,
    n->next->prev=n->prev;      //changes next node's pointer to the previous node
    }
  else{
   this->tail=n->prev;          //make the previous node the last node in the list
  }
    delete n;                   //delete the node
  }

  void insert(Node* n, Node* x){
    if (n!=0){
      x->next=n->next;
      n->next=x;
      x->prev=n;
      if (x->next!=0)
        x->next->prev=x;
    }
    if (this->head==0){
      this->head=x;
      this->tail=x;
      x->prev=0;
      x->next=0;
    }else if (this->tail==n){
      this->tail=x;
    }
  }
  void display(){
    Node* i=this->head;
    cout << "List: " ;
    while(i!=0){
      cout << i->value << ",";
      i=i->next;
    }
    cout << endl;
  }
};

void W5_2()
{
  List* l=new List();
  l->insert(0,new Node(4));
  l->insert(l->head,new Node(6));
  l->insert(l->head,new Node(8));
  l->display();
  l->remove(l->head);
  l->display();
  delete l;
}
