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
    map<TreeNode*,bool> isBST;
    map<TreeNode*,int> smallest;
    map<TreeNode*,int> largest;
    map<TreeNode*,int> sum;
    int ans;
    
    void initialise(TreeNode *node){
        sum[node] = node->val;
        isBST[node] = true;
        smallest[node] = node->val;
        largest[node] = node->val;
        if(node->left != NULL){
            initialise(node->left);
            smallest[node] = min(smallest[node], smallest[node->left]);
            largest[node] = max(largest[node], largest[node->left]);
            sum[node] += sum[node->left];
        }
        if(node->right != NULL){
            initialise(node->right);
            smallest[node] = min(smallest[node], smallest[node->right]);
            largest[node] = max(largest[node], largest[node->right]);
            sum[node] += sum[node->right];
        }
    }
    
    void check(TreeNode *node){
        if(node->left != NULL){
            check(node->left);
            if(!isBST[node->left]) isBST[node] = false;
            else{
                if(largest[node->left] >= node->val) isBST[node] = false;
            }
        }
        if(node->right != NULL){
            check(node->right);
            if(!isBST[node->right]) isBST[node] = false;
            else{
                if(smallest[node->right] <= node->val) isBST[node] = false;
            }
        }
        if(isBST[node]){
            ans = max(ans, sum[node]);
        }
    }
    
    int maxSumBST(TreeNode* root) {
        if(root == NULL) return 0;
        ans = 0;
    	initialise(root);
    	check(root);
    	return ans;
    }
};