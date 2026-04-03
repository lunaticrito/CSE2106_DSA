#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class DoublyList{
public:
    Node* head;
    DoublyList(){
        head=NULL;  
    }
    //insertion at front
    void push_front(int val){
        Node* ptr=new Node(val);
        if(head==NULL){ //empty list
            head=ptr;
        }
        else{
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
    }
    //insertion at back
    void push_back(int val){
        Node* ptr=new Node(val);
        if(head==NULL){
            head=ptr;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
        }
    }
    //insertion after given element
    void push_after(int val,int pos){
        Node* temp=head;
        while(temp!=NULL && temp->data!=pos){
            temp=temp->next;
        }
        if(temp==NULL) return;

        Node* newNode=new Node(val);
        newNode->next=temp->next;
        newNode->prev=temp; 
        if(temp->next==NULL)
            temp->next->prev=newNode;
        temp->next=newNode;
    }
    //insertion before given element
    void push_before(int val,int pos){
        if(head==NULL) return;
        //at first
        if(head->data==pos){
            push_front(val);
            return;
        }
        Node* temp=head;
        while(temp!=NULL && temp->data!=pos){
            temp=temp->next;
        }
        if(temp==NULL) return;

        Node* newNode=new Node(val);
        
        newNode->prev=temp->prev;
        newNode->next=temp;

        temp->prev->next=newNode;
        temp->prev=newNode;        
    }
    //deletion at front
    void pop_front(){
        if(head==NULL) return; //empty list
        Node* temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        delete temp;
    }
    //deletion at back
    void pop_back(){
        if(head==NULL) return;
        Node* temp=head;
        if(temp->next==NULL){
            head=NULL;
            delete temp;
            return;
        }
        while(temp->next!=NULL){
            temp=temp->next; 
        }
        temp->prev->next=NULL;
        delete temp; 
    }
    //deletion after given element
    void pop_after(int val){
        Node* temp=head;
        while(temp!=NULL && temp->data!=val){
            temp=temp->next;
        }
        if(temp==NULL||temp->next==NULL) return;
        Node* del=temp->next;
        temp->next=del->next;
        if(del->next==NULL){
            del->next->prev=temp;
        }
        delete del;
    }
    void pop_before(int val){
        Node* temp=head;
        while(temp!=NULL && temp->data!=val){
            temp=temp->next;
        }
        if(temp==NULL||temp->prev==NULL) return;
        Node* del = temp->prev;
        if(del->prev!=NULL){
            del->prev->next=temp;
            temp->prev=del->prev;
        }
        else{
            head=temp;
            temp->prev=NULL;
        }
        delete del; 
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<->";
            temp=temp->next; 
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);

    dll.push_back(4);
    dll.push_after(5, 2);
    dll.push_before(6, 3);

    dll.display();

    dll.pop_front();
    dll.pop_back();
    dll.pop_after(2);
    dll.pop_before(5);

    dll.display();
}