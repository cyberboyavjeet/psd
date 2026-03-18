#include <bits/stdc++.h>
using namespace std;

int main() {
   /*
   1. traverse the array from rigth to left
   2.maintain a stack that stores potential greater element
   3. for each element:
      -Remove element from the stack than are less than or equal to the current element
      -If stack became empty
          --> the answer =-1
      -Otherwise, the top will be the answer as the next greater element current element
   4.Push the current element onto the stack
   5.Store the result and print it in the origin oder:
      Example Input: 4 5 2 25
      Output: -1 25 25 5
      Stack: 25 2 5 (remove)
   
    
   */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}