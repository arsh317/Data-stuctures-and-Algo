/* 

Rod Cutting
There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, ..., AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut. Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest. Notes:
Sequence a1, a2 ,..., an is lexicographically smaller than b1, b2 ,..., bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be upto 109.

*/

void getAns(vector<int> &ans, vector<vector<int>> &dp, int i, int j, vector<int> p) {
    if (i + 1 == j) return ;
    for (int k = i + 1; k < j; k++) {
        if (dp[i][k] + dp[k][j] + p[j] - p[i] == dp[i][j]) {
            ans.push_back(p[k]);
            getAns(ans, dp, i, k, p);
            getAns(ans, dp, k, j, p);
            return ;
        }
    }
    return ;
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    vector<int> p;
    p.push_back(0);
    for (int b: B) p.push_back(b);
    p.push_back(A);
    sort(p.begin(), p.end());
    
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            dp[i][i+l-1] = INT_MAX;
            for (int k = i + 1; k < i + l - 1; k++)
                dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][k] + dp[k][i+l-1] + p[i+l-1] - p[i]);
        }
                
    }
    
    vector<int> ans;
    getAns(ans, dp, 0, n - 1, p);
    return ans;
    
}