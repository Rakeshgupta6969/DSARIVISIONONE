
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
  
  void inorder(TreeNode* root,vector<int> &ele){
    
      if(root == NULL) return;

      inorder(root -> left,ele);

      ele.push_back(root -> val);

      inorder(root -> right,ele);

  }

  TreeNode * solve(TreeNode * root,int low,int high,vector<int>&ele){
      
      if(low > high) return NULL;
    
        int mid = low + (high - low)/2;
        TreeNode * temp = new TreeNode(ele[mid]);
        root = temp;

        root -> left = solve(root -> left,low,mid-1,ele);
        root -> right = solve(root -> right,mid+1,high,ele);
    

    return root;
       


  }




  

  
public:
    TreeNode* balanceBST(TreeNode* root) {
        
     // using the brute force solution.
        if(root == NULL) return NULL;


     vector<int>ele;

     inorder(root,ele);

     int n = ele.size();

     int low = 0;
     int high = n-1;
     
      int mid = low + (high-low)/2;

     TreeNode * root1 = new TreeNode(ele[mid]);

     root1 -> left = solve(root1-> left,low,mid-1,ele);
     root1 -> right = solve(root1 -> right,mid+1,high,ele);


     return root1;

    }
};