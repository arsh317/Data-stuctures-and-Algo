/* 
Stacking Cubes
You are given N cubes that are of the same size. You are allowed to stack cubes on top of each other. 
You can choose P cubes from the N cubes, such that you should stack all the remaining cubes on top of the P cubes, 
and each of the P cubes should have equal number of cubes on top of them. Eg: Let's say you have 4 cubes.

If P = 1, you can stack the remaing 3 cubes on top of 1 cube.
If P = 2, you can stack the remaining 2 cubes each on top of one P cube, 
such that you have 2 stacks of 2 cubes each (as each of the P cubes should have the same number of cubes stacked). 
Given N number of cubes, find out the number of ways you can stack cubes on top of each other in the given manner. 
Every cube has to be stacked, you cannot have unstacked cubes. No stack can consist of a total of just one cube. 

Input:
N: Number of cubes
*/

int Solution::solve(int A) {
    
    int i=1; int ct=0;
    
    while(i<=A/2)
    {
        if( (A-i)%i==0 ){  ct++; }
        i++;
    }
    
    return ct;
}
