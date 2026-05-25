#include <iostream>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

int ans = -1;
void solve(Node * rootNode,int num){
  if(rootNode == NULL) return;
  if(rootNode -> key  >= num){
   solve(rootNode -> left,num);
  }
  if(rootNode -> key < num){
   ans = rootNode -> key;
   solve(rootNode -> right,num);
  }
}
int findLargestSmallerKey(Node *rootNode, int num) 
{
  // using the concept of the binary search tree
  ans = -1; // this one is very important because for every test cases global variable store the new values in the memory and we have to update that
  // memory for the each test cases.
  if(rootNode == NULL) return -1;
  if(rootNode -> left == NULL && rootNode -> right == NULL){
   if(rootNode -> key >= num) return -1;
   else return rootNode -> key;
  }
  
   solve(rootNode,num);
   return ans;
}

// Comment out main() before running tests
int main() {
  return 0;
}