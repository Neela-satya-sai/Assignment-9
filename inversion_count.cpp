/******************************************************************************
Given an array of integers, find the inversion of an array. Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
N=5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: (2,1) (4,1) and (4,3) forms an inversion in an array


*******************************************************************************/

#include <iostream>
#include<vector>

using namespace std;
int c=0;
void merge(vector<int> &v,vector<int> &p1,vector<int> &p2)  // tc=n
{
    int i=0,j=0,k=0;
    while(i<p1.size() && j<p2.size())
    {
        if(p1[i]<=p2[j]) v[k++]=p1[i++];
        else v[k++]=p2[j++];
    }
    if(i==p1.size())
    {
        while(j<p2.size()) v[k++]=p2[j++];
    }
    if(j==p2.size())
    {
        while(i<p1.size())  v[k++]=p1[i++];
    }
   
}
int inversion(vector<int> &p1,vector<int> &p2)
{
    int i=0,j=0;
    int count=0;
    while(i<p1.size() && j<p2.size())
    {
        if(p1[i]>p2[j]) {count+=p1.size()-i;
            j++;
        }
        else{ //p1[i]<=p2[j]
            i++;
        }
        
    }
    return count;
}
void mergesort(vector<int> &v)
{
    int n=v.size();
    if(n==1) return;
    int n1=n/2, n2=n-n/2;
    vector<int> p1(n1);
    vector<int> p2(n2);
    for(int i=0;i<n1;i++) p1[i]=v[i];
    for(int i=0;i<n2;i++) p2[i]=v[i+n1];
    mergesort(p1);
    mergesort(p2);
    //inversion count
    c+=inversion(p1,p2);
    merge(v,p1,p2);  
    p1.clear();        //50 and 60 line is to reduce space complicity
    p2.clear();
}
int main()
{
    vector<int> v={5,8,1,9,3,6}; //2+3+2
    mergesort(v);   //tc= O(nlogn)
    int n=v.size();
    cout<<c;
    
    //for(int i=0;i<n;i++) cout<<v[i]<<" ";
    

    return 0;
}
