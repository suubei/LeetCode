// Reverse Linked List

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* next = head->next;
    ListNode* newHead = reverseList(next);
    next->next = head;
    head->next = nullptr;
    return newHead;
  }
};