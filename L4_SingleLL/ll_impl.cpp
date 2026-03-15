#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL
    }
};
class List{
public:
    Node* head;
    List(){
        head=NULL;
    }
    //insertion at front
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    //insertion at back
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            return;
        }
    }
    //insertion after given node
    void insert(int pos,int val){
        else{
            Node* temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }

    //deletion from the front
    void pop_front(){
        Node *temp=head;

        
    }
    //deletion from the back
    void pop_back(){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete temp;

    }
    //delete given node
    void pop_pos(int pos,int val){}

    //printing the values
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    int search(){}
};
int main(){

}