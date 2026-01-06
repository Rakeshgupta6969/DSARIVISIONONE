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
public:
    int maxLevelSum(TreeNode* root) {
    
    // using the brute force solution.

    // using the concept of the level order traversal.
    
    vector<int> eleSum;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);   // this NULL is act as seperator of level;


    int sum = 0;

    while(!q.empty()){

         TreeNode* frontNode = q.front();
         q.pop();

         if(frontNode != NULL ){
             sum += frontNode -> val;
            if(frontNode ->left != NULL){
                q.push(frontNode -> left);
            }

            if(frontNode -> right != NULL){
                q.push(frontNode -> right);
            }

         }
         else{
            eleSum.push_back(sum);
            sum = 0;
           if(!q.empty()){
            q.push(NULL);
           }
         }

    }

    int maxSum = *max_element(eleSum.begin(),eleSum.end());

    for(int i = 0; i<eleSum.size(); i++){
        if(maxSum == eleSum[i]){
            return i + 1;
        }
    }

   return -1;

    }
};