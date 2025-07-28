class Solution {
public:

    int solve(vector<int>& nums, int maxOr, int currOr, int index){
        // base condition 
        if(index >= nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }

        // take
        int take = solve(nums,maxOr,(currOr | nums[index]),index+1);

        // skip
        int skip = solve(nums,maxOr,currOr,index+1);

        // return submission of take and skip
        return take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // calculate maxOR value

        int maxOr = 0;

        for(auto i : nums){
            maxOr = maxOr | i;
        }

        //  calculating the no.of subsets which equals maxOr value
        return solve(nums,maxOr,0,0);
    }
};
