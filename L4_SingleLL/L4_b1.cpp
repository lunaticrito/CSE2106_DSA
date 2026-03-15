#include<bits/stdc++.h>
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
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }    
        cout<<"NULL";
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void cond_insert(){
        Node* temp=head;
        int pos=1;
        while(temp!=NULL && temp->next!=NULL){
            if(pos%2==0){
                Node* newNode=new Node(400);
                newNode->next=temp->next;
                temp->next=newNode;

                temp = newNode->next;
                pos+=2;
            }
            else{
                temp = temp->next;
                pos++;
            }
        }
        cout<<"Conditional Modification done"<<endl;
    }
};
int main(){
    List l ;
    int choice,val;
    while(true){
        cout<<"\nMenu:\n";
        cout<<"1. Display\n";
        cout<<"2. Insert at First\n";
        cout<<"3. Conditional Insert Operation\n";
        cout<<"4. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                l.display();
                break;
            case 2:
                cout<<"Enter value :"<<endl;
                cin>>val;
                l.push_front(val);
                break;
            case 3:
                l.cond_insert();
                break;
            case 4:
                cout<<"Program terminated"<<endl;
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}
