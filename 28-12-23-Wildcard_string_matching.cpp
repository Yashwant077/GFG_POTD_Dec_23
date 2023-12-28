/*
Problem Description: Wildcard string matching

Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not. * and ? can be converted to another character according to the following rules:

* --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --> This character in string wild can be replaced by any one character.
Example 1:

Input: 
wild = ge*ks
pattern = geeks
Output: Yes
Explanation: Replace the '*' in wild string 
with 'e' to obtain pattern "geeks".


Example 2:

Input: 
wild = ge?ks*
pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in wild string with
'e' and 'forgeeks' respectively to obtain pattern 
"geeksforgeeks"
Your Task:
You don't need to read input or print anything. Your task is to complete the function match() which takes the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns false.

Expected Time Complexity: O(length of wild string * length of pattern string)
Expected Auxiliary Space: O(length of wild string * length of pattern string)

Constraints:
1 <= length of the two string <= 10^3

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
         int N = wild.size(), M = pattern.size();
        
        // Initialise 2-D Table With Values False (0).
        
        vector <vector<int>> dp(N + 1, vector <int> (M + 1, 0));
        
        dp[N][M] = 1;
        
        for (int i= N-1; i >= 0; --i) {
            
            for (int j= M-1; j >= 0; --j) {
                
                // Case 1 :- Can Replace 1 Character.
                
                if (wild[i] == '?') 
                    
                    // Skip Current Characters In Both Strings.
                    
                    dp[i][j] = dp[i + 1][j + 1];
                
                // Case 2 :- Can Replace Multiple Characters.
                
                else if (wild[i] == '*') {
                    
                    // * Occurs At Last Position In Wildcard String.
                    
                    if (i == N-1) {
                    
                        // Pattern String Already Matches Of Remaining Characters Automatically.
                        
                        dp[i][j] = 1;
                    }
                    
                    else
                        dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                }
                
                // Normal Characters (A-Z || 0-9)
                else {
                    
                    if (wild[i] != pattern[j]) {
                    
                        dp[i][j] = 0;
                    }
                    
                    else
                        dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }
        
        // Answer -> dp[0][0].
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
