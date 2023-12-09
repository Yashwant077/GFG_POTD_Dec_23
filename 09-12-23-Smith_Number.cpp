/*
Problem Description: Smith Number

Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.

Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

Expected Time Complexity: O(n * log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^5

*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sum(int n){
        int ans=0;
        while(n!=0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    
    bool isPrime(int n)
    {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
    }
    
    int help(int i,int n){
        int r=0,ii=i;
        while(n%i==0){
        r++;
        i*=ii;
        }
        return r;
    }
    
    int smithNum(int n) {
        int n1=sum(n);
        int n2=0;
        for(int i=2;i<=n/2;i++){
            if(n%i==0 && isPrime(i)){
                int m=sum(i);
                m*=help(i,n);
                n2+=m;
            }
        }
        return n1==n2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
