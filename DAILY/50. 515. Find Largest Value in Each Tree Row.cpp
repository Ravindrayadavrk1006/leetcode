/*
    basic -> direct bfs or level order travesal 

*/


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
    vector<int> solLargestValues(TreeNode* root){
        vector<int> ans;
        //if no element in tree
        if(root == NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            int currMax = INT_MIN;
            for(int i = 0;i<qSize; i++){
                TreeNode* front = q.front();
                currMax = max(currMax, front->val);
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            ans.push_back(currMax);
        }
        return ans;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        return solLargestValues(root);
    }
};
