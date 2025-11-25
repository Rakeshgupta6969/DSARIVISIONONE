class Solution {
public:
    int smallestRepunitDivByK(int k) {

     // using the  brute force solution.

     if(k % 2 == 0) return -1;
     if(k % 5 == 0) return -1;

    

    int rem = 1;

    for(int i = 1; i<=k; i++){
    
      if(rem % k == 0) return i;

      rem = (rem*10 + 1) % k;


    }

    return -1;

    }
};