/*
Problem Description: Largest rectangular sub-matrix whose sum is 0

Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one starting from minimum row index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
Your Task:
You don't need to read input or print anything. You just have to complete the function sumZeroMatrix() which takes a 2D matrix mat[][], its dimensions N and M as inputs and returns a largest sub-matrix, whose sum is 0.

Expected Time Complexity: O(N*M*M).
Expected Auxiliary Space: O(N*M).


Constraints:
1 <= N, M <= 100
-1000 <= mat[][] <= 1000

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
       int n=a.size(),m=a[0].size();
      int area=0,x1=-1,x2=-1,y1=-1,y2=-1;
      for(int l=0;l<m;l++){
          vector<int>arr(n);
          for(int r=l;r<m;r++){
              for(int i=0;i<n;i++){
                  arr[i]+=a[i][r];
              }
              unordered_map<int,int>mp;mp[0]=-1;
              int sum=0,len=0,s=-1,e=-1;
              for(int i=0;i<n;i++){
                  sum+=arr[i];
                  if(mp.find(sum)!=mp.end()){
                     if(len<i-mp[sum]){
                         len=i-mp[sum];
                         e=i;
                         s=mp[sum]+1;
                     }
                  }
                  else mp[sum]=i;
              }
              if(area<len*(r-l+1)){
                  area=len*(r-l+1);
                  y1=l;y2=r;
                  x1=s;x2=e;
              }
          }
      }
      vector<vector<int>> ans;
      if(x1==-1||x2==-1||y1==-1||y2==-1) return ans;
      for(int i=x1;i<=x2;i++){
          vector<int>temp;
          for(int j=y1;j<=y2;j++){
              temp.push_back(a[i][j]);
          }
          ans.push_back(temp);
      }
      return ans;
  }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends
