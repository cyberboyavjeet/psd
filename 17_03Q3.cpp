#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    // Compute sum of first window
    long long windowSum = 0;
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    long long maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];  // Add new element, remove old
        maxSum = max(maxSum, windowSum);
    }

    cout << maxSum << endl;

    return 0;
}