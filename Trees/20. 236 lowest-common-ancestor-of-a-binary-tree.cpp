
/*  
    idea---> simple approach of pre-order travesal
    we are having a variable which checks if at any point checker becomes true we don't do anything further

    we are pushing the current element in answer array and poping from if we don't have the checker true
    checker is set to true if we got answer from (left and right) or (left and root) or (right and root)

    brute force approach -> this is the not implemented here but what can we do is find the path to both the node , store the paths in two separate vectors one for each node path,
    then we compare the values of both the vector from the start and the moment, we found a match we can store in a matched variables and once we find a non matching element after finding the match we break and the matched element is our answer
    

*/
class Solution {
bool checker = false;
bool helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& ans){
    if(root == NULL)return false;
    cout<<"current root"<<root->val<<" checker "<<checker<<endl;
    cout<<"checker value"<<checker<<endl;

    ans.push_back(root);
    bool left= false, right = false, is_root = false; 

    //if current root is equal to p or q
    if(root == q || root == p){
        is_root = true;
    }
    left = helper(root->left,p,q, ans);
    if(!checker)right = helper(root->right, p, q, ans);


    //if we don't have answer at the current root we remove the current root
    if(!checker){
        if(((left && right) || (right && is_root) || (left && is_root)) == false){
        ans.pop_back();
    }
    //if we have the answer we set the checkr to true
    else{
        checker = true;
    }
    }
    return is_root || left || right;
}

================================ solution 2
/*
        here we are travesing the node, if we find a node to be either p or q or null we return it , if we find eithr p or q at root we return it since the other would come from either left or right
        **Important Point-> 
            we are checking from in the left and right, if we get from the left we return the left, if we found in the right we return the right , else it means one is the left and one is in the right and we return the root then 
    */
    TreeNode* sol_2(TreeNode* root, TreeNode* p, TreeNode* q){
        /*
            here we are saying if we didn't find either p or q and we reached till last node we return NULL
            if we find either p or q at any place we return the node
            let's suppose we find the root to be p then q must be either in left or right
            similarly if the node at any 
        */
        if(root == NULL || root == p || root == q)return root;

        TreeNode* left = sol_2(root->left, p, q);
        TreeNode* right = sol_2(root->right, p, q);
        if(left == NULL)return right;
        if(right == NULL)return left;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans;
        helper(root,p,q, ans);
        //print the last node
        cout <<"size of vector"<<ans.size();
        return ans[ans.size()-1];



        //calling sol 2
        return sol_2(root, p, q);
    }
};
