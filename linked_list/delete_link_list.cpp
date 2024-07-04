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

void delete_at_pos(node * head, int pos){
    
    node * temp = head;
    for(int i=1; i<=pos-1; i++){
        temp = temp->next;
    }
    node * deletenode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deletenode;
}

void delete_tail( node * &tail){
    node * deletetail = tail;
    tail = tail->prev;
    delete deletetail;
    tail->next = NULL;
    
}
void delete_head( node * &head){
    node * deletehead = head;
    head = head->next;
    delete deletehead;
    head->prev = NULL;
    
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
    
  int pos;
  cin>>pos;
  
  if( pos>=size(head)){
      cout<<"Invalid Index";
  }else if(pos==0){
      delete_head(head);
  }else if(pos == size(head)-1){
      delete_tail(tail);
  }else{
      delete_at_pos(head,pos);
  }
   //
   //
   
   print_normal(head);
   cout<<endl;
   print_recurse(tail);
    

    return 0;
}
