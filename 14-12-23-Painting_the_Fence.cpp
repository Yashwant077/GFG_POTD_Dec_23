/*
Problem Description: Painting the Fence

Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 109 + 7.

Example 1:

Input:
n = 3
k = 2 
Output: 6
Explanation: 
We have following possible combinations:

Example 2:

Input:
n = 2
k = 4 
Output: 16
Explanation: 
After coloring first post with
4 possible combinations, you can still color
next posts with all 4 colors. Total possible 
combinations will be 4x4=16
Your Task:
Since, this is a function problem. You don't need to take any input or print anything, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted (modulo 109 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5000
1 ≤ K ≤ 100

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n == 1)
            return k;
            
        long mod = (long) 1e9 + 7, same = 0, diff = k;
        
        for(int i = 2; i <= n; i++) 
        {
            long prev = same;
            same = diff;
            diff = ((prev + same) * (k - 1)) % mod;
        }
        
        return (same + diff) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
