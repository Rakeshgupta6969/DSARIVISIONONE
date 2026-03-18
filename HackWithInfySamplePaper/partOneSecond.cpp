// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<climits>
#include<cmath>
#include <algorithm>

using namespace std;

  // here we want to find the maximum subarray sum after swaping the 
  // at most k usefull swap
int main() {
 
      vector<int> nums = {1,-4,5,6,-3};
      int k = 3;
      int n = nums.size();
      
      int maxsum = INT_MIN;
      
      // approach: using the brute force solution
      
      // here want to update the every window of the subarray
      // {l...r}  and after the updating just find sum of the element of that subarray
      
      
      for(int left  = 0; left<n; left++){
        
             for(int right = left; right<n; right++){
                     
             vector<int>inside; // inside the window elements;
             vector<int>outside;// outside window element;
                   
            
                   for(int i  = 0; i<n; i++){
                       if(i>=left && i<=right){
                           inside.push_back(nums[i]);
                       }
                       else{
                           outside.push_back(nums[i]);
                       }
                   }
                   
                   // find the initial sum;
                   int sum  = 0;
                   for(auto & num : inside){
                       sum += num;
                   }
                   
                   
                   // sort the both vector
                   
                   sort(inside.begin(),inside.end());
                   sort(outside.begin(), outside.end(),greater<int>());
                   
                   for(int i = 0; i<k; i++){
                        
                        if(i < inside.size() && i<outside.size()){
                            if(inside[i] < outside[i]){
                                sum += outside[i] - inside[i];
                            }
                            else{
                                break; // because next element inside[i]>outside[i]
                            }
                        } 
                   }
                   
                   maxsum  = max(maxsum,sum);
                 
             }
           
          
          
      }
      
      
      cout<<"maximum subarray sum after the k useful swap :"<<maxsum<<endl;
      
    
     

    return 0;
}