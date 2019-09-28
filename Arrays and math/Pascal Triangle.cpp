/*Pascal Triangle
Given numRows, generate the first numRows of Pascal's triangle. Pascal's triangle :
To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1
*/
vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int> > vt;
    if(A==0){ return vt; }
    
    vector<int> tm; tm.push_back(1);
    vt.push_back(tm);
    if(A==1) { return vt; }
    tm.push_back(1); vt.push_back(tm);
    if(A==2) { return vt; }
    
    for(int i=2; i<A; i++)
    {
        vector<int> tmp;
        tmp.push_back(1);
        
        for(int j=1; j<i; j++)
        {  tmp.push_back(vt[i-1][j-1]+vt[i-1][j]);   }
        tmp.push_back(1);
        vt.push_back(tmp);
    }
    
    return vt;
    
}
