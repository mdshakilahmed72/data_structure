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
void insert_at_head(node * &head,node * &tail, int value){
    node * newnode = new node(value);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insert_at_pos( node * head, int val, int pos){
    node * newnode =  new node(val);
    node * temp = head;
    
    for(int i=1; i<=pos-1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
      newnode->next->prev = newnode;
    newnode->prev = temp;
     
    
}

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

int size(node * head){
    node * temp = head;
    int count =0;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    return count;
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
    
   int pos, value;
   cin>>pos>>value;
    if(pos==0){
        insert_at_head(head,tail value);
    }
    else if(pos>=size(head)){
        cout<<"Invalid Index"<<endl;
    }else{
      insert_at_pos(head, value,pos);  
    }
   print_normal(head);
   cout<<endl;
   print_recurse(tail);
    

    return 0;
}
