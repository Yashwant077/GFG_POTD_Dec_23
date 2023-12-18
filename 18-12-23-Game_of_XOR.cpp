/*
Problem Description: Game of XOR

Given an array A of size N. The value of an array is denoted by the bit-wise XOR of all elements it contains. Find the bit-wise XOR of the values of all subarrays of A.

Example 1:

Input: 
N = 3 
A = [1,2,3] 
Output: 
2
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
Example 2:

Input: 
N = 2
A = [1,2]
Output: 
0
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2] = 2
Result : 1 ^ 3 ^ 2 = 0
Your Task:
You don't need to read input or print anything. Your task is to complete the function gameOfXor() which takes an integer N and array A[] as input parameters and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^5
0 <= A[i] <= 10^9

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int n, int arr[]) {
        // code here
        int ans=0;
        
        if(n%2==0)
            return 0;
        else{
            for(int i=0; i<n; i++){
                if(i%2==0)
                    ans^=arr[i];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends
