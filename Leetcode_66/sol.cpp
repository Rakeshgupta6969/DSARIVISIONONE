class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    
    // using the brute force solution.

    // int number  = 0;
    
    // int n = digits.size();

    // for(int i  = 0; i<n; i++){
    //     number = number*10 + digits[i];
    // }
  
  

    //   number += 1;

    //   vector<int> ans;

    //   while(number>0){
    //     int p = number%10;
    //     ans.push_back(p);
    //     number /= 10;
    //   }

    //   reverse(ans.begin(),ans.end());
      
    //   return ans;



    // using the optimal solution.

    int carry;
    
    int n  = digits.size();
    
    int lastNumber = digits[n-1] + 1;
    carry = lastNumber / 10;
    digits[n-1] = lastNumber % 10;

      if(carry  == 0) return digits;

      if(n == 1 && carry == 1){
        digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
      }

      for(int i = n-2; i>=0; i--){  
         digits[i] += carry;
         carry = digits[i]/10;
         digits[i] %= 10;
    }
     
    if(carry  == 0) return digits;

    vector<int> ans;
    if(carry  == 1){
        ans.push_back(1);

        for(int i = 0; i<n; i++){
            ans.push_back(digits[i]);
        }

      
    }
     
   return ans;

    }
};