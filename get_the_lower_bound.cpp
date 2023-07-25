/******************************************************************************
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index
where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Input: nums = [1,3,5,6], target = 5
Output: 2

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
int get_the_correct_idx_place(vector<int> v,int target){
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]<target) lo=mid+1;
        else hi=mid-1;
    }
    return lo;

}

int main()
{
    vector<int> v={1,3,5,6};
    int target=7;
    cout<<get_the_correct_idx_place(v,target);

    return 0;
}
