/* 
Bulbs
N light bulbs are connected by a wire.  Each bulb has a switch associated with it, however due to faulty wiring, 
a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs, 
find the minimum number of switches you have to press to turn on all the bulbs.  You can press the same switch \
multiple times. Note : 0 represents the bulb is off and 1 represents the bulb is on. 
*/

int Solution::bulbs(vector<int> &A) {
    
    int ct=0;
    for(int i=0; i<A.size(); i++)
    {
        if(ct%2==0)
        {
            if(A[i]==0){ ct++; }//to turn this on
        }
        else//ct%2==1
        {
            if(A[i]==1){ ct++; }
        }
    }
    
    return ct;
}
