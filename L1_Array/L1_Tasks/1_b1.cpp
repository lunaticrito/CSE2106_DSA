#include <bits/stdc++.h>
using namespace std;

void ins(int &size,int arr[], int pos, int val){
    for(int i=size;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=val;
    size++;
}
int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int size=n;
    for(int i=0;i<size;i++){
        if (i > 0 && arr[i] == arr[i - 1])
        continue;

        int count=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>1){
            ins(size,arr,i+1,count);
            i++;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
