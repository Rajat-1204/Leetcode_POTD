class Solution
{
public:
    static bool cmp(int a, int b)
    {   /// this is the custom comparator which is used to
        // find whether "2" + "20" is greater or "20"+"2"
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp); // sort the vector according to this comparator
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += to_string(nums[i]);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};