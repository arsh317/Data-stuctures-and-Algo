/* 
Binary Strings
You are given a string consisting of 1's and 0's. Now the task is to make the string consisting of only 1's. 
But you are allowed to perform only the following operation:
Take exactly k consecutive elements of string and change 1 to 0 and 0 to 1.
Each operation takes 1 unit time so you have to determine the minimum time required to make the string of 1's only. 
If not possible return -1. 

Input :
First argument is a string S consisting if 1's and 0's (2 ≤ length of S ≤ 1000).

Second argument is an integer K which represents the number of consecutive elements which can be changed 
(2 ≤ K ≤ length of S).

Output :
Return an integer which is the minimum time to make the string of 1's only and -1 if not possible.
*/

int Solution::solve(string A, int B) {
    
    int ct=0; 
    
    for(int i=0; i<=A.size()-B; i++)
    {
        if(A[i]=='0')
        {
            for(int j=i; j<A.size() && j<i+B; j++)
            {
                if(A[j]=='0'){ A[j]='1'; }
                else { A[j]='0'; }
            }
            ct++;
        }
    }
    for(int i=A.size()-1; i>=0; i--){ if(A[i]=='0'){ return -1; } }
    return ct;
}
