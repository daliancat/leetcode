#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:    
    #if 1
      int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ret = 0;
        while(!q.empty()){
            ret++;
            for(int i = q.size()-1; i>=0; i--){
                string word = q.front();
                q.pop();
                for(int j = 0; j<word.size(); j++){
                    string tmp = word;
                    for(int k = 'a'; k<='z';k++){
                        tmp[j] = k;
                        if(dict.find(tmp)!=dict.end()){
                            if(tmp == endWord) return ret+1;
                            //dict.erase(tmp);
                            q.push(tmp);
                        }
                    }
                }
            }
        }
      }
    #else
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> map;
        queue<string> q;
        q.push(beginWord);
        map[beginWord] = 1;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            for(int i = 0; i< cur.size(); i++){
                string tmp(cur);
                for(int j = 'a'; j<='z'; j++){
                    tmp[i] = j;
                    if(dict.find(tmp) != dict.end() && map.find(tmp)==map.end()){
                        if(tmp == endWord){
                            return map[cur] +1;
                        }
                        //dict.erase(tmp);
                        map[tmp] = map[cur] + 1;
                        q.push(tmp);
                    }
                }    
            }
        }
        return 0;
    }
    #endif
};
int main(int argc, char** argv){
    Solution solution;
    string arr[]={"hot","dot","dog","lot","log"};
    //string arr[]={"a","b","c"};
    vector<string> vec(arr,arr+5);
    //vector<string> vec(arr,arr+3);
    solution.ladderLength("hit","cog",vec);
    //solution.ladderLength("a","c",vec);
    return 0;
}
