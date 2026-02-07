class Solution {
public:
    int minimumDeletions(string s) {


   // using the brute force solution.

   stack<char>st;

   int count = 0;

   for(auto & ch:s){
    if(!st.empty() && (st.top() == 'b' && ch == 'a')){
        st.pop();
        count++;
    }
    else{
        st.push(ch);
    }
   }
        
    

      return count;

    }
};