#include<vector>
#include<string>
using namespace std;
class TrieNode{
public:    
    TrieNode* child[26];
    string word;
    TrieNode():word(""){
        for(int i = 0;i<26; i++){
            child[i] = nullptr;
        }
    }
};
class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string& word){
        TrieNode* p = root;
        for(int i =0 ;i <word.size(); i++){
            if(p->child[word[i] - 'a'] == nullptr){
                p->child[word[i] - 'a'] = new TrieNode();
            }
            p = p->child[word[i] - 'a'];
        }
        p->word = word;
        return;
    }
    TrieNode *root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if(board.empty()||board[0].empty()) return ret;
        Trie trie;
        for(int i = 0; i<words.size(); i++){
            trie.insert(words[i]);
        }
        
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                dfs(board, i, j, trie.root->child[board[i][j] - 'a'],visited,ret);
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& board,int x, int y, TrieNode* p, vector<vector<bool>>& visited, vector<string>& ret){
        if(p == nullptr) return;
        if(x <0 || x>= board.size() || y<0 || y>=board[0].size()) return;
        if(visited[x][y] == true) return;
        if(!p->word.empty()){
            ret.push_back(p->word);
            p->word.clear();
        }
        visited[x][y] = true;
        if(x+1 < board.size()) dfs(board, x+1, y, p->child[board[x+1][y] - 'a'],visited,ret);
        if(x-1>=0) dfs(board, x-1, y, p->child[board[x-1][y] - 'a'],visited,ret);
        if(y+1 < board[0].size()) dfs(board, x, y+1, p->child[board[x][y+1] - 'a'],visited,ret);
        if(y-1>=0) dfs(board, x, y-1, p->child[board[x][y-1] - 'a'],visited,ret);
        visited[x][y] = false;
        return;
    }
};
int main(int argc, char** argv){
    Solution solution;
    vector<vector<char>> board;
    board.push_back({'a'}); 
    board.push_back({'b'});
    vector<string> words;
    words.push_back("ab"); 
    solution.findWords(board, words);
    return 0;
}
