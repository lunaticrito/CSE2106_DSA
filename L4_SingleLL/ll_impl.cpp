#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
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
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    //insertion at position
    void insert(int pos,int val){
        if(pos<0){return;}
        else if(pos==0){
            push_front(val);
            return;
        }
        else{
            Node* temp=head;
            for(int i=0;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    //deletion from the front
    void pop_front(){
        if(head==NULL){ return; }
        
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    //deletion from the back
    void pop_back(){
        if(head==NULL){ return; }
        if(head->next==NULL){
            delete head;
            head==NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete temp->next;
    }
    //delete node at position
    void pop_pos(int pos){
        if(head==NULL){ return; } 
        else if(pos==0){
            pop_front();
            return;
        }
        else{
            Node* temp=head;
            for(int i=0;i<pos-1 && temp->next!=NULL;i++){
                temp=temp->next;
            }

            if(temp->next==NULL) return;
            Node *del=temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    //printing the values
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    int search(int key){
        Node* temp=head;
        int pos=0;
        while(temp!=NULL){
            if(temp->data==key)
                return pos;
            temp=temp->next;
            pos++;
        }
        return -1;
    }
};
int main(){
    List l;

    l.push_front(10);
    l.push_front(5);
    l.push_back(20);
    l.insert(1,15);
    l.display();

    cout << "Position of 20: " << l.search(20) << endl;

    l.pop_front();
    l.pop_back();
    l.display();
}
