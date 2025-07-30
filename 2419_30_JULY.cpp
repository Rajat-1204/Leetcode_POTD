class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // initialize variables
        int maxi = 0;
        int ans = 0;


        // calculate max value of a array
        for(auto i : nums){
            maxi = max(maxi,i);
        }

        // check for continous maximum value subarray length
        int cnt = 0;
        for(auto i : nums){
            if(i == maxi) cnt++;

            else cnt = 0;

            ans = max(ans,cnt);
        }

        return ans;
    }
};
