/******************************************************************************

 Given an array of integer nums sorted in non-decreasing order,
 find the starting and ending position of a given target value.
If the target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*******************************************************************************/
#include<vector>
#include <iostream>

using namespace std;

int binarysearch(int arr[],int n,int target,bool leftbias){
    int l=0,h=n-1;
    int i=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]<target) l=mid+1;
        else if(arr[mid]>target) h=mid-1;
        else{    //condition comes to else only if arr[mid]==target.
            i=mid;
            if(leftbias){
                h=mid-1;
            }
            else l=mid+1;
        }
    }
    return i;
}

vector<int>  getidxs(int arr[],int n,int target){
     int left=binarysearch(arr,n,target,true); //true means first index of target occurence.
     int right= binarysearch(arr,n,target,false);
     return {left,right};
    
}


int main()
{
     int arr[]={5,7,7,8,8,8,8,8,8,8,10};
     int target=8;
     int n = sizeof(arr)/sizeof(arr[0]);
     vector<int> ans= getidxs(arr,n,target);
     
     for(auto ele:ans) cout<<ele<<" ";
     
     
     

    return 0;
}
