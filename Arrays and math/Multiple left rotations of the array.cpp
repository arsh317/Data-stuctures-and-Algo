/*Multiple left rotations of the array
Given an array of integers A and multiple values in B which 
represents the indices of the array A around which left rotation of the array
A needs to be performed. Find the rotated array for each value and return the 
result in the from of a matrix where i'th row represents the rotated array for
the i'th value in B.
*/
vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    
    vector<vector<int> > vt;
    for(int i=0; i<B.size(); i++)
    {
        vector<int> tmp;
        int rt=B[i]%A.size();
        for(int j=rt; j<A.size(); j++)
        { tmp.push_back(A[j]); }
        
        for(int j=0; j<rt; j++)
        { tmp.push_back(A[j]); }
        
        vt.push_back(tmp);
    }
    
    return vt;
}
