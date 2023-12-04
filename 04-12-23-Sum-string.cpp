/*
Problem Description: Sum-string

Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string when it is broken down into more than one substring and the rightmost substring can be written as a sum of two substrings before it and the same is recursively true for substrings before it.

Example 1:

Input:
S = "12243660"
Output:
1
Explanation:
"12243660" can be broken down as {"12", "24", "36", "60"}.
We can get 60 from 24 and 36 as 24 + 36 = 60. Similarly 36 can be written as 12 + 24.
Example 2:

Input:
1111112223
Output:
1
Explanation:
"1111112223" can be broken down as {"1", "111", "112", "223"}.
We can get 223 from 111 and 1112 as 111 + 112 = 223. Similarly 112 can be written as 1 + 111.
Your Task:

You don't need to read input or print anything. Your task is to complete the function isSumString() which takes the string S and returns 1 is S is a sum-string otherwise returns 0.

Expected Time Complexity: O(|S|3)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <= 500
String consists of characters from '0' to '9'.

*/

#User function Template for python3
class Solution:
    def isSumString (ob,s):
        # code here 
        n = len(s)
        def check(i,j,k):
            nonlocal s, n
            if k==n:
                return True
            if k>n:
                return False
            n1 = int(s[i:j])
            n2 = int(s[j:k])
            ns = str(n1+n2)
            
            if not s[k:].startswith(ns):
                return False
            return check(j,k,k+len(ns))
            
        for i in range(1,n):
            for j in range(i+1, n):
                if check(0,i,j):
                    return 1
                    
        return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        
        print(ob.isSumString(S))
# } Driver Code Ends
