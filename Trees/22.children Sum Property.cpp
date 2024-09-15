/*
PROBLEM LINK -> https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
explanation -> easy case of returning from the point when we find the answer .
    caviat -> since we don't have to check for leaf node hence just check if the current is leaf node or not if it is then just 
    return true
     //for root node
    if(root -> left == NULL  && root->right == NULL)return true;

  full-code explanation-> we are simply doing inorder traversal and checking simple codition if current_root node value is equal to 
  sum of value of it's right and left child 

*/


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
//using inorder traversal
bool children_sum_property(Node *root ){
    if(root == NULL)return true;
    int curr_sum = 0;
    //for root node
    if(root -> left == NULL  && root->right == NULL)return true;
    if(root->left)curr_sum += root->left->data;
    if(root->right)curr_sum +=root->right->data;
    if(root->data != curr_sum)return false;
    if(!children_sum_property(root->left))return false; 
    if(!children_sum_property(root->right))return false;
    return true;
}
bool isParentSum(Node *root){
    return children_sum_property(root);
}
