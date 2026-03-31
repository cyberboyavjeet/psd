#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string S;
    cin >> S;

    stack<int> st;
    for(char ch:S){
        if(isdigit(ch)){
            st.push(ch - '0');
        }
        else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            int result=0;
            switch(ch){
                case '+':result=a+b;
                        break;
                case '-':result=a-b;
                        break;
                case '*':result=a*b;
                        break;
                case '/':result =(int)(a/b);
                        break;
                case '%':result =a%b;
                        break;
               
            }
            st.push(result);
        }

    }
    cout<<st.top()<<endl;
    return 0;
}
