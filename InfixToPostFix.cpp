#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string expr) {
    stack<char> st;
    string output = "";
    
    for(char ch : expr) {
        // Operand
        if(isalnum(ch)) {
            output += ch;
        }
        // Left parenthesis
        else if(ch == '(') {
            st.push(ch);
        }
        // Right parenthesis
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while(!st.empty() &&
                  st.top() != '(' &&
                  precedence(st.top()) >= precedence(ch) &&
                  !isRightAssociative(ch)) {
                output += st.top();
                st.pop();
            }
            // Handle equal precedence for right-associative
            while(!st.empty() &&
                  st.top() != '(' &&
                  precedence(st.top()) > precedence(ch)) {
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    // Pop remaining operators
    while(!st.empty()) {
        output += st.top();
        st.pop();
    }
    
    return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    cin >> S;
    cout << infixToPostfix(S) << endl;
    
    return 0;
}