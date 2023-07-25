/******************************************************************************
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. Since each version is developed based 
on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether the version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to the API.
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int n,int bad,int x){
    vector<int> versions(n+1,0);
    for(int i=1;i<bad;i++){
        versions[i]=1;
    }
    if(versions[x]) return false;
    else return true;
    
    
}
int firstBadVersion(int n,int bad) {
        int lo=1;                //its a right baised binary search
        int hi=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(!isBadVersion(n,bad,mid)){ //if not bad then move to right. 
                 lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
    }
int main()
{
    int n=9, bad=7;
    cout<<firstBadVersion(n,bad);

    return 0;
}
