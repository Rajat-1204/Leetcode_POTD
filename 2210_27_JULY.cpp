class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Intialize variables
        int count = 0;
        int j = 0;
        int n = nums.size();

        // loop thru the array
        for(int i = 1;i<n-1;i++){
            //condition check krni hh whether it's a hill or valley
            if((nums[j] < nums[i] && nums[i+1] < nums[i]) || 
                (nums[j] > nums[i] && nums[i+1] > nums[i])){
                    count++;
                // update j
                    j = i;
            }

        }
        // return count;
        return count;
    }
};
