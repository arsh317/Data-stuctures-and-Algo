/*
Linked-List
Design and implement a Linked List data structure. A node in a linked list should have the following attributes - an integer value and a pointer to the next node. It should support the following operations:
insert_node(position, value) - To insert the input value at the given position in the linked list.
delete_node(position) - Delete the value at the given position from the linked list.
print_ll() - Print the entire linked list, such that each element is followed by a single space.
 */

#include<iostream>
using namespace std;

struct node
{
    int val;
    node* next;
    node(int v)
    { val=v; next=NULL; }
};

node *root=NULL;
int p=0;

void insert_node(int pos, int value) {
    
    if(pos>p+1 || pos<1){ return; }
    
    p++;
    node* temp=new node(value);
    if(pos==1){ temp->next=root; root=temp; return; }
    
    pos=pos-2;  node* curr=root;
    while(pos--)
    {  curr=curr->next;  }
    
    node* t=curr->next;
    curr->next=temp;
    temp->next=t;
}

void delete_node(int pos) {
    
    if(pos>p || pos<1){ return; }
    
    node* temp; p--;
    if(pos==1){ temp=root; root=root->next; delete(temp); return; }
    
    pos=pos-2;  node* curr=root;
    while(pos--)
    {  curr=curr->next;  }
    
    temp=curr->next;
    curr->next=temp->next;
    delete(temp);
}


void print_ll() {
    
    node* curr=root;
    while(curr!=NULL)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}
