//parenthesis checker 
#include <bits/stdc++.h>
using namespace std;

class Stack{
    char *arr;
    int cap;
    int top; 
public:
    Stack(int c){
        cap=c;
        arr=new char[cap];
        top = -1;
    }
    void push(char x){
        if(top==cap-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=x;
    }    
    char peek(){
        if(top==-1){
            cout<<"Empty Stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    char pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
bool match(char a,char b){
    return  (a=='('&&b==')')||
            (a=='{'&&b=='}')||
            (a=='['&&b==']');
}
bool isBalanced(string s){
    Stack st(s.size());
    for(char x:s){
        if(x=='('||x=='{'||x=='['){
            st.push(x);
        }
        else{ 
            if(st.isEmpty()){
                return false;
            }
            if(!match(st.peek(),x)){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    return st.isEmpty();
}
int main(){
    string s;
    cin>>s;
    if(isBalanced(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}