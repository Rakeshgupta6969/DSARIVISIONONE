class Solution {
public:
    int totalWaviness(int num1, int num2) {
          // using the brute force solution.


          int ans = 0;
      
          for(int i = num1; i<=num2; i++){

             string s = to_string(i);
             if(s.size()<3) continue;

            
            int p = 0, j = 1,k = 2;

            while(k<s.size()){

               int a  =  (s[p++] - '0');
               int b =   (s[j++] - '0');
               int c =   (s[k++] - '0');

               if((b>a && b>c) || (b<a && b<c)) ans++;

            }

         }

      

      return ans;


    }
};