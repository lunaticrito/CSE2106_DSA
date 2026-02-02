#include <bits/stdc++.h>
using namespace std;

void display(int size,int arr[]){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insert(int size,int arr[],int pos,int val){
    size++;
    for(int i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;
    display(size,arr);
}
void del(int size,int arr[],int pos){
    for(int i=pos;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    display(size,arr);
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos, val;
    cout<<"Enter the position & value for insertion"<<endl;
    cin>>pos>>val;
    insert(n,arr,pos,val);
    cout<<"Enter the position for deletion"<<endl;
    cin>>pos;
    del(n,arr,pos);

    return 0;
}
