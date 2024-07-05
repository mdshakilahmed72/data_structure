// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node * next;
    node(int value){
        this->value = value;
        this->next = NULL;
    }
    
};
void insert_at_tail( node * &head,node* &tail,int value){
    node * newnode = new node(value);
    node * temp = head;
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_link(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

void duplicate_value(node * head){
    node * temp = head;
    int flag =0;
    while(temp!=NULL){
        node * x = temp->next;
        while(x !=NULL){
            if(temp->value==x->value){
                flag=1;
                break;
            }
            x = x->next;
            
        }
        temp = temp->next;
    }
    
    if(flag==0){
        cout<<"Uniquee Value";
    }else{
        cout<<"Duplicate Value";
    }
}
int size(node * head){
    node* temp = head;
    int count =0;
    while(temp!=0){
        count++;
        temp = temp->next;
    }
    return count;
}

void mid_value(node * head){
    node * temp = head;
    int sz = (size(head)/2)-1;
        
        while(sz--){
            temp = temp->next;
        }
        if(size(head)%2==0){
            cout<<temp->value<<" "<<temp->next->value;
        }else{
               cout<<temp->next->value;
        }
     
}



int main() {
    node * head = NULL;
    node * tail = NULL;
    
    while(true){
        int val;
        cin>>val;
        if(val==-1){
            break;
        }else{
            insert_at_tail(head,tail,val);
        }
    }
    
    //duplicate_value(head);
  
    mid_value(head);
    return 0;
}
