class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        stack<int> st;
        ListNode* temp = head;

        // Push all values into stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Pop values back into nodes (reverses values, not links)
        temp = head;
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};
