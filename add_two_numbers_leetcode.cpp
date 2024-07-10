/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
                if (l3 != NULL) {
                    cout << "second itr" << l3->val;
                }
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* newNode;
            sum += carry;
            if (sum > 9) {
                // means carry is to be generated
                // if we modulo we get last term
                // if we divide we get first tem ex:10 %=0 /=1
                carry = sum / 10; // got 1
                sum = sum % 10;   // for 10 got 0
                cout << "carry" << carry;
                newNode = new ListNode(sum);
            } else {
                newNode = new ListNode(sum);
                carry = 0;
            }
            // check weather necessary to make carry as 0 //$no need
            if (l3 == NULL) {
                cout << "creating forst l3 node";
                // assigning l3 start to newNode
                l3 = newNode;
                head = l3; // l3 of that time

            } else {
                // means l3 has some previous data
                l3->next = newNode;
                l3 = l3->next;
                cout << "changed" << l3->val;
                // break;
            }
            cout << sum << " ";
        }
        cout << "at last carry" << carry;
        // might handle last carry remaining stage
        if (carry > 0) {
            cout<<"APPENDED";
            ListNode* last = new ListNode(carry);
            cout<<"lastval"<<last->val;
            l3->next = last;
            l3 = l3->next;
            // head=l3;
        }
        return head;
    }
};