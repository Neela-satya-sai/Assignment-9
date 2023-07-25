#include<vector>
#include <iostream>

using namespace std;
/*Find the majority element in the array. A majority element in an array A[] of size n is an element
that appears more than n/2 times (and hence there is at most one such element). 
Input: A[]={3, 3, 4, 2, 4, 4, 2, 4, 4}
Output: 4
Explanation: The frequency of 4 is 5 which is greater than half of the size of the array size. 
*/

int mories_voting_algo(int arr[],int n){
    int candidete=0;
    int votes=0;
    for(int i=0;i<n;i++) {
        if(votes==0) {
            candidete=arr[i];
        }
        if(candidete==arr[i])  votes++;
        else  votes--;
    }
    return candidete;
}

int main()
{
   int arr[]={3, 3, 4, 2, 4, 4, 2, 4, 4};
  
   int n=sizeof(arr)/sizeof(arr[0]);
   
   cout<<mories_voting_algo(arr,n);

    return 0;
}
