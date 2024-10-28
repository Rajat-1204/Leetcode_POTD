class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // making unordered_set and pushing element in sorted manner
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxi = -1;
        // traversing the array
        for (int num : nums) {
            int count = 1;
            long long current = num;
            // searching for the square one
            while (numSet.find(current * current) != numSet.end()) {
                current *= current;
                count++;
                // if value goes beyond int_max then break
                if (current > INT_MAX) break;
            }

            if (count >= 2) {
                // storing the max of maxi and count
                maxi = max(maxi, count);
            }
        }

        // return maxi
        return maxi;
    }
};
