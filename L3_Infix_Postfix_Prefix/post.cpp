#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/'||c=='*'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
bool RightAssoc(char c){
    return c=='^';
}
string in2post(string &s){
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a' && c<='z')||(c>='A'&& c<='Z')||(c>='0' && c<='9')){
            res +=c;
        }

        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(!st.empty()&& st.top()=='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty()&& st.top()!='(' && 
            (prec(st.top())>prec(c)||(prec(st.top())==prec(c)) && !RightAssoc(c))){
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<<in2post(s);
    return 0;
}