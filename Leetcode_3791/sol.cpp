class Solution {
public:
    long long countBalanced(long long low, long long high) {
        
      // using the brute force solution.

      long long count = 0;

      if(low < 10){
        for(int i = 10; i<=high; i++){
          
          vector<long long> digit;

           long long temp = i;
           while(temp >0){
            digit.push_back(temp % 10);
            temp  /= 10;
           }

           reverse(digit.begin(),digit.end());
          
          int evensum  = 0;
          int oddsum = 0;

          for(int j = 0;  j<digit.size(); j++){
            if(j % 2  == 0){
                evensum += digit[j];
            }
            else{
                oddsum += digit[j];
            }
          }
         
         if(evensum == oddsum) count++;

        }
      }
      else{
       for(int i = low; i<=high; i++){
          
          vector<long long> digit;

           long long temp = i;
           while(temp >0){
            digit.push_back(temp % 10);
            temp  /= 10;
           }

           reverse(digit.begin(),digit.end());
          
          int evensum  = 0;
          int oddsum = 0;

          for(int j = 0;  j<digit.size(); j++){
            if(j % 2  == 0){
                evensum += digit[j];
            }
            else{
                oddsum += digit[j];
            }
          }
         
         if(evensum == oddsum) count++;

        }

      }

     return count;


    }
};