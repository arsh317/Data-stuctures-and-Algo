/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
*/

#include<bits/stdc++.h>


class Solution {
public:
    
    int isposs(vector<int>& A, vector<int>& B,int mid){
        
        int k=(A.size()+B.size())/2; 
        
        if(mid>A.size()){ return 1; }
     
        if(mid-1>=0 && mid<A.size() && A[mid-1]>A[mid]){ return 1;  }
        else if(k-mid>B.size()){ return -1; }
        else if(mid-1>=0 && k-mid<B.size() && A[mid-1]>B[k-mid]){ return 1; }
        else if(k-mid-1>=0 && k-mid<B.size() && B[k-mid-1]>B[k-mid]){ return -1; }
        else if(k-mid-1>=0 && mid<A.size() && B[k-mid-1]>A[mid] ){ return -1; }
        
        else{ return 0; }         
        
    }
    
    
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        
        int k=(A.size()+B.size())/2;  int sz=A.size();
        
        if(A.empty())
        {
            if(B.size()%2==0){ return (double)(B[k-1]+B[k])/2; }
            else{ return B[k]; }
        }
        
        if(B.empty())
        {
            if(A.size()%2==0){ return (double)(A[k-1]+A[k])/2; }
            else{ return A[k]; }
        }
        
        int l=0,h=min(k,sz);   int mid=(l+h)/2;
        
        while(l<=h)
        {
            mid=(l+h)/2;
            
            if(isposs(A,B,mid)==0){ break; }
            else if(isposs(A,B,mid)==1){ h=mid-1; }
            else{ l=mid+1; }
        }
        
        int a=INT_MIN;
        if(mid-1>=0){ a=A[mid-1]; }
        if(k-mid-1>=0 && B[k-mid-1]>a){ a=B[k-mid-1]; }
        
        
        int b=INT_MAX;
        if(mid<A.size()){ b=A[mid]; }
        if(k-mid<B.size() && B[k-mid]<b){ b=B[k-mid]; }
        
        if((A.size()+B.size())%2==0)
        {            
            return (double)(a+b)/2;
        }
        
        return b;
        
        
    }
};