class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        //INITIALIZE VARIABLES
        int i = 0, j = 0, sum = 0, ans = 0;

        // CREATING VECTOR OF FIXED SIZE(10001) ALL CONTAINING FALSE INITIALLY
        vector<int> exist(10001,false);
        
        // TRAVERSING THRU THE VECTOR
        while(j<n){

            // IF EXIST THEN REMOVING THE STARTING ELEMENTS TILL THE DUPLICATE VALUE
            while(exist[nums[j]]){
                sum -= nums[i];
                exist[nums[i]] = false;
                i++;
            }
            
            // CONTINOUSLY ADDING VALUE TO SUM
            sum += nums[j];
            exist[nums[j]] = true;

            // CONSTINOUSLY UPDATING ANS VARIABLE WHEN NEEDED
            ans = max(ans,sum);
            j++;
        }

        // RETURN ANS
        return ans;
    }
};
