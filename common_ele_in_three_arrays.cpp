#include <iostream>
#include <vector>
#include<algorithm>
#include<stack>

using namespace std;



int main()
{
    //return all the values in an array which are common in all three arrays.
    vector<int> arr1={2,3,4,5,6,9,10,12,18}; 
    vector<int> arr2={5,9,10,11,15,17,};
    vector<int> arr3={1,3,5,7,9,10,11,13,18};           //output: [5,9,10]
    
    int i=0,j=0,k=0;
    vector<int> ans;
    while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
             ans.push_back(arr1[i]);
             i++;j++;k++;
        }
        else{
            int mi=min(arr1[i],min(arr2[j],arr3[k]));
            if(mi==arr1[i]) i++;
            if(mi==arr2[j]) j++;
            if(mi==arr3[k]) k++;
        }
        
        
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
  
    return 0;
}
