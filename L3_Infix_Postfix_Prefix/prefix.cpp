#include <bits/stdc++.h>
using namespace std;
class Stack{
    char* arr;
    int top;
    int cap;
public:
    Stack(){
        top=-1;
    }
    void push(char c){
        arr[++top]=c;
    }
    char pop(){
        return arr[top--];
    }
    char peek(){
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};
int prec(char c) {
    if (c == '^')return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}
bool isRightAssociative(char c) {
    return c == '^';
}
string infixToPostfix(string &s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // If operand, add to result
        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9'))
            res += c;

        // If '(', push to stack
        else if (c == '(')
            st.push('(');

        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        // If operator
        else {
            while (!st.empty() && st.top() != '(' &&
                   (prec(st.top()) > prec(c) ||
                   (prec(st.top()) == prec(c) && !isRightAssociative(c)))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop remaining operators
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}
int main() {
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    for(char &c:s){
        if(c=='('){ c=')';}
        else if(c==')'){ c='(';}
    }
    s=infixToPostfix(s);
    cout<<s;
    return 0;
}