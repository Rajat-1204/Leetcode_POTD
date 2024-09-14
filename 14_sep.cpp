class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, cnt = 0;
        for (auto &x : nums)
        {
            // increase the count by 1 if it is same as the max number
            if (x == mx)
                cnt += 1;
            // else reset it
            else
                cnt = 0;
            // update ans
            ans = max(ans, cnt);
        }
        return ans;
    }
};