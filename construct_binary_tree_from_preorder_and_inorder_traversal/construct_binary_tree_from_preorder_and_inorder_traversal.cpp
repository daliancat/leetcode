#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    
    TreeNode* buildTree(vector<int>::iterator pre_first,vector<int>::iterator pre_last, vector<int>::iterator in_first,vector<int>::iterator in_last){
        if(pre_first == pre_last) return NULL;
        if(in_first == in_last) return NULL;
        TreeNode* root = new TreeNode(*pre_first);
        vector<int>::iterator rootPos = find(in_first, in_last, *pre_first);
        int leftSize = distance(in_first, rootPos);
        root->left = buildTree(next(pre_first), next(pre_first, leftSize+1), in_first, next(in_first,leftSize));
        root->right = buildTree(next(pre_first, leftSize+1), pre_last, next(rootPos), in_last);
        return root;
    }
    
};
int main(int argc, char** argv){
    Solution solution;
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,25,10,7};
    vector<int> preorder_vec(preorder, preorder + sizeof(preorder)/sizeof(preorder[0]));
    vector<int> inorder_vec(inorder, inorder + sizeof(inorder)/sizeof(inorder[0]));
    solution.buildTree(preorder_vec,inorder_vec);
    return 0;
}
