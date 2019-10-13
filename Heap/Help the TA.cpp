/* 
Help the TA
Ayush has recently joined InterviewBit Academy as TA (Teaching Assistant). He has been assigned a job to keep record of all the errors each student is having in his batch and report it to the Mentor.

Since, the mentor gives extra attention to weak students, he resolves the issues of student having maximum number of errors first. But, to keep equality among students, he gives one minute to each student to resolve one of his errors and then ask the TA for next student.

Also, the lecture would not last more than B minutes and whenever a student has no more errors left, he leaves the lecture immediately.

Ayush, being confused each time, needs your help to shout out the roll number of student who should be helped at any time i.
You are given an array of integers, where A[i] denotes number of errors in code of student with roll number i.
Return a list containing the roll numbers,where element at index i denotes the roll number to be helped at minute i.
Ayush should keep on shouting roll numbers unless the B minutes are over or, the class is empty(everyone has left).

HINT: The returning array size will depend on the time till which roll numbers are shouted.
 NOTE 1. Roll Numbers are 0-indexed (i.e, Roll numbers start from 0) 2. In case of tie(same number of errors), the least roll number is given preference. 3. There is no restriction on spending more than one minute consecutively on one student, as far as the mentor's condtions are met 4. Your code will be run on multiple test cases(<=10), try to come up with optimised solution. Constraints
1 <= Number of Students <= 10^6
0 <= A[i] : Errors for each student <= 10^5
0 <= Sum of All Errors <= 10^6
1 <= B <= 10^6
 */

struct cmp{
     bool operator()(pair<int, int > a, pair<int, int > b)
     {
         if(a.first == b.first)
         {
             return a.second > b.second;
         }
         return a.first < b.first;
     }
 };

vector<int> Solution::solve(vector<int> &a, int b) {
    int n = a.size();
    priority_queue<pair<int, int >,vector<pair<int, int>>,  cmp> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({a[i], i});
    }
    vector<int> v;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    int mnm = min(sum, b);
    while(!pq.empty() &&  mnm--)
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int value = p.first;
        int index = p.second;
        v.push_back(index);
        value--;
        pq.push({value, index});
    }
    return v;
    
}
