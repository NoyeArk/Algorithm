/**
 * @file 142.环形链表II.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-04-30
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int cnt = 0;
        unordered_map<ListNode*, int> hash;
        while (head != NULL)
        {
            if (hash.find(head) == hash.end())
            {
                hash[head] = 1;
            }
            else return head;
            head = head->next;
        }
        return NULL;
    }
};

// 集合做法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};