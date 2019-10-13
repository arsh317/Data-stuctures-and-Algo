/* 
Stairs
You are climbing a stair case and it takes A steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
 */


int Solution::climbStairs(int A) {
    
    int arr[A+1];
    memset(arr,0,sizeof(arr));
    
    arr[1]=1; arr[0]=1;
    for(int i=2; i<=A; i++)
    {
        arr[i]=arr[i-2]+arr[i-1];
    }
    
    return arr[A];
}
