/* 

Russian Doll Envelopes
Given a matrix of integers A of size N x 2 describing dimensions of N envelopes, where A[i][0] denotes the height of the ith envelope and A[i][1] denotes the width of the ith envelope. One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope. Find the maximum number of envelopes you can put one inside other.

*/


int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), [](const vector<int> & p1, const vector<int> & p2){
        return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
    });
    vector<int>dp;
    for(auto x: A){
        int pos = lower_bound(dp.begin(), dp.end(), x[1]) - dp.begin();
        if(pos == dp.size()) dp.push_back(x[1]);
        else dp[pos] = x[1];
    }
    return dp.size();
}