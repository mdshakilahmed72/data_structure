#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node* next;
    node * prev;
    
    node(int value){
        this->value= value;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_pos(node * &head, int value, int pos){
                node * newnode = new node(value);
                node * temp = head;
                
                for(int i=1; i<=pos-1; i++){
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
                newnode->next->prev= newnode;
                newnode->prev = temp;
}

void print_link_normal(node * head){
    node * temp = head;
    
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void print_link_recurse(node * tail){
    node * temp = tail; 
    
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main() {
    
    node * head = new node(10);
    node * a = new node(20);
    node * b = new node(30);
    node * c = new node(40);
    node * d = new node(50);
    node * tail = d;
    
    head->next = a;
    a->next = b;
    a->prev = head;
    b->next = c;
    b->prev = a;
    c->next = d;
    c->prev  = b;
    d->prev = c;
    print_link_normal(head);
    print_link_recurse(tail);
    
    
    
    return 0;
}
