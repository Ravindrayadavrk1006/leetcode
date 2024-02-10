#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

/*
    simple variation of BFS and simple application of 14. 987. Vertical Order Traversal of a Binary Tree
    it is saying we just have to see only element in for each column that is just first element for each column
    hence normally doing BFS and when we see that for the current column, if element was not inserted earlier we insert element

    we haven't ran for loop of BFS since we don't need to store separately for each level or row 
*/
vector<int> helper(TreeNode<int> * root){
    vector<int> ans;
    if(root == NULL)return ans;
    //for each element in the queue for BFS traversal we will store the node and it's column number
    queue<pair<TreeNode<int>*,int>> q;
    //0 is the column here
    q.push({root,0});
    map<int,int> mp;

    //simply doing BFS 
    while(!q.empty()){
        pair<TreeNode<int>*, int> front = q.front();
        //if for current element's column ther is no element present in map then we push in the map
        if(mp.find(front.second) == mp.end()){
            mp[front.second] = front.first->data;
        }
        //remove the front from the queue
        q.pop();
        //push current root's left in the queue
        if(front.first->left != NULL){
            q.push({front.first->left,front.second-1});
        }
        //push current root's right in the queue
        if(front.first->right != NULL){
            q.push({front.first->right, front.second+1});
        };
    }

    //store all the element from the map into the ans 
    for (auto el : mp){
        ans.push_back(el.second);
    }
    return ans;

}
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    return helper(root);
}
