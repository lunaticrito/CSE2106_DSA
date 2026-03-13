#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> st;
    string result;

    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string input;
    getline(cin, input);

    vector<string> expressions;
    string temp;
    bool inside = false;

    for (char c : input) {
        if (c == '{') {
            inside = true;
            temp.clear();
        }
        else if (c == '}') {
            inside = false;
            expressions.push_back(temp);
        }
        else if (inside) {
            if (c != ' ')
                temp += c;
        }
    }
    cout << "Total Expressions Found: " << expressions.size() << endl;
    cout << "Extracted Infix Expressions:" << endl;

    for (int i = 0; i < expressions.size(); i++) {
        cout << i + 1 << ". " << expressions[i] << endl;
    }
    cout << "Corresponding Prefix Expressions:" << endl;
    for (int i = 0; i < expressions.size(); i++) {
        cout << i + 1 << ". " << infixToPrefix(expressions[i]) << endl;
    }

    return 0;
}