/* 
Tennis Logs

Three friends P, Q and R are playing tennis, and they play in such a way that:
P and Q start playing initially, R is spectating.
Whoever loses, becomes the spectator, and the winner plays with the person who was spectating.
It is given that no draws take place.
A games are played, and a log of each game with the winner is made, but the players are not sure if the log is correct or not.
In the log, every time P wins, it is represented by the integer 1, when Q wins it is represented as 2, when R wins, 3. You are given the log of N integers, you are supposed to return "Yes" if the log is correct, else return "No", without double quotes. Input:
A: Number of log entries
B: Array of A integers.
Output:
"Yes" if the log is correct, else "No".
*/

void swap(int &a, int &b)
{
    int t=a; a=b;
    b=t;
}

string Solution::solve(int A, vector<int> &B) {
    
    int a=1,b=2,c=3;
    for(int i=0; i<A; i++)
    {
        if(B[i]==c){ return "No"; }
        
        if(B[i]==a){ swap(b,c); }
        else{ swap(a,c); }
    }
    
    return "Yes";
}