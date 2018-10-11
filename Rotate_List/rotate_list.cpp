#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    #if 1
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int len = 0;
        ListNode *cur = head, *p;
        while(cur){
            len++;
            p = cur;
            cur = cur->next;
        }
        p->next = head;

        k %= len;
        k = len - k -1;
        cur = head;
        while(k){
            k--;
            cur = cur->next;
        }
        head = cur->next; 
        cur->next = nullptr;
        
        return head;
        
    }

    #else
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len =0;
        ListNode *p = head, *prev;
        while(p){
            len++;
            prev= p;
            p = p->next;
        }
        prev->next = head;
        p = head;
        k %= len;
        k = len - k -1;
        while(k!=0){
            p=p->next;
            k--;
        }
        head = p->next;
        p->next = NULL;
        return head;    
    }
    #endif
};
ListNode* createList(vector<int>& nums){
    ListNode dummy(0), *p = &dummy;
    for(int i =0; i<nums.size(); i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return dummy.next;
}
int main(int argc, char** argv){
    Solution solution;
    int arr[]={1,2};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    ListNode *root = createList(vec);
    solution.rotateRight(root,0);
    return 0;
}
