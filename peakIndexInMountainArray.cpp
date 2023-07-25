/******************************************************************************
  A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
Input: nums = [1,2,3,1]
Output: 2
 
*******************************************************************************/
#include<vector>
#include <iostream>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int lo=1;
        int hi=n-2;
        int idx=-1;

        while(lo<=hi)
        {
            int mid= lo+(hi-lo)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                idx=mid;
                break;
            }
            else if(arr[mid]>arr[mid-1] )  //left side
            {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
       return idx;
    }


int main()
{
     vector<int> arr={2,5,4,7,8,3,2};
     cout<<peakIndexInMountainArray(arr);

    return 0;
}
