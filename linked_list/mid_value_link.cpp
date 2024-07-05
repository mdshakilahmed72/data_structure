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
void insert_link_list(node * &head, node* &tail, int value){
    node * newnode = new node(value);
    node * temp = head;
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    while(temp->next!=NULL){
        temp= temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;
    tail = temp->next;
}

// void print_link(node * head){
//     node * temp = head;
//     while(temp != NULL){
//         cout<<temp->value<<" ";
//         temp = temp->next;
//     }
// }
int size(node * head){
    node * temp = head;
    int count =0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void middle_element(node * head,node * tail){
    node * slow = head;
    node * fast = head;
    while(fast!=NULL && fast->next!=NULL){
         slow = slow->next;
         fast = fast->next->next;
    }
    
    if(size(head)%2==0){
        cout<<slow->prev->value<<" "<<slow->value;
    }else{
        cout<<slow->value;
    }
    
}

int main() {
    node * head = NULL;
    node * tail = NULL;
    
    while(1){
        int value;
        cin>>value;
        if(value==-1){
            break;
        }else{
            insert_link_list(head,tail,value);
        }
    }
    middle_element(head,tail);
    

    return 0;
}
