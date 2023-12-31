/*
Problem Description: New Year Resolution

As the clock struck midnight on New Year's Eve, Geek bid farewell to the wasted moments of 2023, realizing the untapped potential of GFG's Problem of the Day.

His 2024 resolution: Solve POTD every day.

Eager to earn coins for GFG Merchandise, Geek faces new rules:

Earning Coin: Geek can accumulate coins[i] by solving the POTD on the ith day, where 1 <= coins[i] <= 2024 and the sum of coins <= 2024.
Merchandise Eligibility: To purchase merchandise, the coins earned must be divisible by 20 or 24, or precisely equal to 2024.
Geek's resolutions often fades over time. Realistically, he can only commit to active participation for N (where N ≤ 366) days. Given the value of N and number of coins associated with each POTD, can Geek strategically solve some (or all) POTDs to become eligible for redeeming merchandise?

Example 1:

Input:
N = 8
coins = [5, 8, 9, 10, 14, 2, 3, 5]

Output: 1

Explanation:
Geek can fulfill the criteria in many ways.
One such way is to solve POTD on 4th and 5th day.
Another way is to solve POTD on 1st, 4th and 8th day.

Example 2:

Input:
N = 5
coins = [1, 2, 3, 4, 5]

Output: 0

Explanation: There is no way Geek can become eligible.
Your Task: 
You don't need to read input or print anything. Complete the function isPossible() which takes n and coins[ ] as input parameters and returns a boolean value.

Expected Time Complexity: O(N*(Sum of coins))
Expected Auxiliary Space: O(N*(Sum of coins))

Constraints:
1 <= N <= 366
1 <= coins[i] <= 2024
1 <= Sum of coins <=  2024

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        set<int> sums;
        sums.insert(0);
        
        for(int i=0; i<N; i++){
            set<int> ss = sums;
            for(auto it:ss){
                int t = it+coins[i];
                
                if(t%20==0 || t%24==0)
                    return 1;
                
                sums.insert(it+coins[i]);
            }
        }
        
        return sums.find(2024)!=sums.end();
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
