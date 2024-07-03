// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node{
  public:
  int value;
  node * next;
  node * prev;
  
  node(int value){
      this->value = value;
      this->next = NULL;
      this->prev = NULL;
  }
  
};
void doubly_reverse(node * head, node * tail){
    node * i = head;
    node * j = tail;
    while( i!=j && i->next != j){
        swap(i->value, j->value);
        i= i->next;
        j= j->prev;
    }
}

void normal_print(node * head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

int main() {
    node * head = new node(10);
    node * a = new node (20);
    node * b = new node(30);
    node * c = new node(40);
   node * d = new node(50);
    node * tail = d;
    
    
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;

    
    doubly_reverse(head,tail);
    normal_print(head);
    
    

    return 0;
}
