/*
Problem Description: Consecutive 1's not allowed

Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation:
5 strings are (000,
001, 010, 100, 101).

Example 2:

Input:
N = 2
Output: 3
Explanation: 
3 strings are (00,01,10).
Your Task:
You don't have to print answer or take inputs. Complete the function countStrings() which takes single integer n, as input parameters and returns an integer denoting the answer. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    ll int zeroending=1;
	    ll int oneending=1;
	    ll int sum = zeroending+oneending;
	    
	    if(n==1)
	        return sum;
	        
	    int i=2;
	    while(i<=n){
	        oneending = zeroending;
	        zeroending = sum;
	        
	        sum = (oneending+zeroending)%1000000007;
	        i++;
	    }
	    
	    return sum%1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
