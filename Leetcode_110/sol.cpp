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

   pair<bool,int> check(TreeNode* root){

      if(root == NULL) return {true,0};


      pair<bool,int>left = check(root-> left);
      pair<bool,int>right = check(root -> right);

      if(left.first == false || right.first == false) return {false,left.second};

    if(fabs(left.second - right.second) > 1) return {false,left.second};

    return {true,max(left.second,right.second)+1};


   }


public:
    bool isBalanced(TreeNode* root) {

        // using the brute force solution;

        pair<bool,int> ans = check(root);

        return ans.first;





    }
};m