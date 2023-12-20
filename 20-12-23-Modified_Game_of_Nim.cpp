/*
Problem Description: Modified Game of Nim

You are given an array A of n elements. There are two players player 1 and player 2.
A player can choose any of element from an array and remove it. If the bitwise XOR of all remaining elements equals 0 after removal of the selected element, then that player loses. Find out the winner if player 1 starts the game and they both play their best. 

Example 1:

Input: 
n = 3
A = [3, 3, 2]
Output: 
2
Explaination: 
Optimal removal of values are 3, 2, 3 sequentially. Then the array is empty. So player 2 wins.

Example 2:

Input: 
n = 2
A = [3, 3]
Output: 
1
Explaination: 
Since the xor of an array is already 0, player 1 wins.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findWinner() which takes the number n and the array A as input parameters and returns an integer denoting the winner.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 10^5
0 ≤ A[i] ≤ 10^9

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int xorRes = 0;
        
        for(int i=0; i<n; i++)
            xorRes^=A[i];
            
        if(xorRes==0)
            return 1;
        else
            return n%2+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
