/*
Problem Description: String's Count

Given a length n, count the number of strings of length n that can be made using a, b and c with at-most one b and two c allowed.

Example 1:

Input: n = 1
Output: 3
Explanation: Possible strings are: "a",
"b" and "c"

Example 2:

Input: n = 3
Output: 19
Explanation: Number of strings with 3 
occurrances of a: 1
2-a and 1-b: 3
2-a and 1-c: 3
1-a, 1-b and 1-c: 6
1-a and 2-c: 3
1-b and 2-c: 3
So, total number of strings of length 3
is 1 + 3 + 3 + 6 + 3 + 3 = 19
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countStr() which takes the n as inputs and returns the total number of valid strings.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 10^5

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int length){
    //complete the function here
    // Case 1: Strings with all 'a'
    long long int strings_all_a = 1;

    // Case 2: Strings with at most 1 'b'
    long long int strings_at_most_1_b = length;

    // Case 3: Strings with at most 1 'c'
    long long int strings_at_most_1_c = length;

    // Case 4: Strings with one 'b' and one 'c'
    long long int strings_one_b_one_c = length * (length - 1);

    // Case 5: Strings with two 'c'
    long long int strings_two_c = (length * (length - 1)) / 2;

    // Case 6: Strings with one 'b' and two 'c'
    long long int strings_one_b_two_c = (length * (length - 1) * (length - 2)) / 2;

    long long int total_strings = strings_all_a + strings_at_most_1_b + strings_at_most_1_c +
                        strings_one_b_one_c + strings_two_c + strings_one_b_two_c;

    return total_strings;
}