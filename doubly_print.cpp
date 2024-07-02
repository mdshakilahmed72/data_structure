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

void print_normal(node *head){
    node * temp = head;
    
    while(temp !=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

void print_recurse(node *tail){
    node * temp = tail;
    
    while(temp !=NULL){
        cout<<temp->value<<" ";
        temp = temp->prev;
    }
}

int main() {
    node * head = new node(10);
    node * a    = new node(20);
    node * b    = new node(30);
    node * c    = new node(40);
    node * tail = c;
    
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
  
    print_normal(head);
    cout<<endl;
    print_recurse(tail);
    
    

    return 0;
}
