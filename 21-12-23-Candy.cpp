/*
Problem Description: Candy

There are N children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:

Each child must have atleast one candy.
Children with a higher rating than its neighbors get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute.

Example 1:

Input:
N = 3
ratings = [1, 0, 2]
Output: 
5
Explanation: 
You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input:
N = 3
ratings = [1, 2, 2]
Output: 
4
Explanation: 
You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it statisfies the above two conditions.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minCandy() which takes the interger N and integer array ratings as parameters and returns the minimum number of candies you need to have to distribute.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
0 ≤ ratingsi ≤ 10^9

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int> v(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                v[i]=v[i-1]+1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                v[i]=max(v[i],v[i+1]+1);
            }
        }
        int sum=0;
        for(auto x:v)sum+=x;
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends

