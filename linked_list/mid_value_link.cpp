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
void insert_link_list(node * &head ,int value){
    node * newnode = new node(value);
    node * temp = head;
    if(head==NULL){
        head = newnode;
        return;
    }
    while(temp->next!=NULL){
        temp= temp->next;
    }
     newnode->next = temp->next;
    temp->next = newnode;
   
}

void print_link(node * head){
    node * temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}
int size(node * head){
    node * temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void middle_element(node * head){
    node * slow = head;
    node * fast = head;
    while(fast!=NULL && fast->next!=NULL){
         slow = slow->next;
         fast = fast->next->next;
    }
    cout<<endl<<slow->value;
}

int main() {
    node * head = NULL;
    
    while(1){
        int value;
        cin>>value;
        if(value==-1){
            break;
        }else{
            insert_link_list(head,value);
        }
    }
    print_link(head);
    middle_element(head);

    return 0;
}
