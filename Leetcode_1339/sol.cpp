/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   
   private:

   void findSum(TreeNode * root,long long  & totalSum){
    if(root == NULL) return;
    
    if(root -> left){
          findSum(root -> left,totalSum);
    }

    totalSum += root -> val;

    if(root -> right){
        findSum(root -> right,totalSum);
    }

 

   }

   long long  solve(TreeNode * root,long long & maxProduct,long long & totalSum){
      
        if(root == NULL) return 0;

        if(root -> left  == NULL && root -> right == NULL){
            long long  value = root -> val;

            long long  rem = totalSum - value;

            long long product = rem*value;

            maxProduct  = max(maxProduct,product);

            return value;   
        }


      long long  leftValue = solve(root -> left,maxProduct,totalSum);
      long long  rightValue = solve(root -> right, maxProduct,totalSum);

      long long value = root -> val;
      long long  tillValue = value + leftValue + rightValue;

      long long  rem = totalSum - tillValue;

      long long Product = (rem*tillValue);
     
     maxProduct  = max(maxProduct,Product);

     return tillValue;


   }


public:
    const int MOD = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        
     // using the optimal solution;

     long long totalSum = 0;

     findSum(root,totalSum);

     long long  maxProduct = INT_MIN;

     solve(root,maxProduct,totalSum);

     return maxProduct%MOD;


    }
};