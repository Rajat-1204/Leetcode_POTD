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
class Solution
{
public:
    // function for calculating GCD
    int gcdcalc(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }

        if (a == 0)
        {
            return b;
        }
        return a;
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;
        // Traversing over the linked list until last element
        while (temp->next != NULL)
        {
            ListNode *nexi;
            if (temp->next)
            {
                nexi = temp->next;
                int val = gcdcalc(temp->val, nexi->val); // calculating the gcd of(temp->val,nexi->val)
                ListNode *ad = new ListNode(val);        // creating a new node of the value gcd
                temp->next = ad;                         // connecting ad in between
                ad->next = nexi;
            }
            temp = nexi;
        }
        return head; // returning head
    }
};