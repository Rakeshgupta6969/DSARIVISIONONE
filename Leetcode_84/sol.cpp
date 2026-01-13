class Solution {
  
   private:

   vector<int> findPre(vector<int> & nums){
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    st.push(-1); // basically this is for the first elements of the nums.

    for(int  i  = 0; i<nums.size(); i++){

       int p = nums[i];

       while(st.top() != -1 && nums[st.top()] >= p){
        st.pop();
       }

       ans[i] = st.top();
       st.push(i);


    } 


     return ans;

   }


   vector<int> findNext(vector<int> & nums){
       
       int n = nums.size();


       vector<int> ans(n);

       stack<int> st;

       st.push(-1);

       for(int  i = n-1; i>=0; i--){
         
         int p = nums[i];

         while(st.top() != -1 && nums[st.top()]>=p){
            st.pop();
         }

        ans[i] = st.top();

        st.push(i);


       }


      return ans;
   }





public:
    int largestRectangleArea(vector<int>& heights) {

      // using the brute force solution.

    //   int ans  = 0;


    //   int n = heights.size();

    //   for(int i = 0; i<n; i++){
        
    //     int h = heights[i];
        
    //     int totalwidth = 0;

    //       int temp1 = i-1;

    //       while(temp1 >=0 && heights[temp1] >= h){
    //               totalwidth++;
    //               temp1--;
    //       }

    //       int temp2 = i;
    //       while(temp2 < n && heights[temp2] >= h){
    //         totalwidth++;
    //         temp2++;
    //       }
        


    //     int currArea = h*totalwidth;

    //     ans = max(ans,currArea);

    //   }


    //   return ans;

    // but above solution takes approx of the O(n^2) T.C;

   

     // using the optimal solution.

     
     int ans =0;
     int n = heights.size();
    
     vector<int> preSml; // for storing the index of its previous smaller element.
     vector<int> nextSml;// for storing the index of its next smaller element.
              

     preSml =  findPre(heights);
     nextSml=  findNext(heights);

    for(int i  = 0; i<n; i++){
        int h = heights[i];

        if(nextSml[i] == -1) nextSml[i] = n; // generally for the last element.

        
        int w = nextSml[i] - preSml[i] - 1; // method of the finding width of the reactangle.

        int area = h*w;

        ans = max(ans,area);


    }   


      return ans; 





    }
};