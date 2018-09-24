#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    #if 0
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *parent = nullptr;
        while(root){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            if(parent && parent->val >= tmp->val){
                return false;
            }
            parent = tmp;
            tmp = tmp->right;
            while(tmp){
                s.push(tmp);
                tmp=tmp->left;
            }
        }
        return true;
    }
    #else
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        TreeNode *parent=nullptr, *cur = root;;
        while(cur){
            if(cur->left==nullptr){
                if(parent && parent->val >= cur->val){
                    return false;
                }
                parent = cur;
                cur = cur->right;
            }else{
                TreeNode *tmp = cur->left;
                while(tmp->right!=nullptr && tmp->right!=cur){
                    tmp = tmp->right;
                }
                if(tmp->right == nullptr){
                    tmp->right = cur;
                    cur = cur->left;
                }else{
                    if(parent && parent->val >= cur->val){
                        return false;
                    }
                    parent = cur;
                    tmp->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return true;
    }
    #endif
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
