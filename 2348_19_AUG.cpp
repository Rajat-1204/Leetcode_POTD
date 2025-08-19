class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // intialize variables
        long long ans = 0;
        long long count = 0;

        // traverse the vector
        for(int x : nums){
            // if consecutive zeroes are present thn increase the counter
            if(x == 0){
                count++;
                ans += count;
            }
            // if anytime non zero value comes then counter becomes zero and restarts
            else{
                count = 0;
            }
        }
        // return ans
        return ans;
    }
};
