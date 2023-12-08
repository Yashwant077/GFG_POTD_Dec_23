/*
Problem Description: Transform to prime

Given an array of n integers. Find the minimum non-negative number to be inserted in array, so that sum of all elements of array becomes prime.

Example 1:

Input:
N=5
arr = {2, 4, 6, 8, 12}
Output:  
5
Explanation: 
The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.
Example 2:

Input:
N=3
arr = {1, 5, 7}
Output:  
0 
Explanation: 
The sum of the array is 13 which is already prime. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function minNumber() that takes array arr and integer N as input parameters and returns the minimum positive number to be inserted in the array so as to make it's sum a prime number.

Expected Time Complexity: O(N log(log N))
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10^5
1 ≤ sum of all elements ≤ 10^6

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    int isPrime(int SUM){
        int cnt=0;
        
        for(int i=2; i<SUM; i++){
            if(SUM%i==0){
                SUM++;
                cnt++;
                i=1;
            }
        }
        return cnt;
    }
    
    int minNumber(int arr[],int N)
    {
        int SUM=0;
        for(int i=0; i<N; i++)
            SUM+=arr[i];
            
        if(SUM==1)
            return 1;
            
        int ans = isPrime(SUM);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
