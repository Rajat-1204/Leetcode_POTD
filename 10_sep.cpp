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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int up = 0;
        int down = m - 1;
        int l = 0;
        int r = n - 1;

        int dir = 0;
        int i = up;
        int j = 0;
        while (head != NULL)
        {
            if (dir == 0)
            {
                ans[i][j] = head->val;
                if (j == r)
                {
                    dir = 1;
                    up = up + 1;
                    i = up;
                    j = r - 1;
                }
                j++;
            }
            else if (dir == 1)
            {
                ans[i][j] = head->val;
                if (i == down)
                {
                    dir = 2;
                    r = r - 1;
                    j = r;
                    i = down - 1;
                }
                i++;
            }
            else if (dir == 2)
            {
                ans[i][j] = head->val;
                if (j == l)
                {
                    dir = 3;
                    down = down - 1;
                    i = down;
                    j = l + 1;
                }
                j--;
            }
            else if (dir == 3)
            {
                ans[i][j] = head->val;
                if (i == up)
                {
                    dir = 0;
                    l = l + 1;
                    j = l;
                    i = up + 1;
                }
                i--;
            }
            head = head->next;
        }
        return ans;
    }
};