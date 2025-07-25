class Solution {
public:
    int maxSum(vector<int>& nums) {
        //intializing variable
        int ans = 0;
        unordered_set<int> st;

        // adding positives to set
        for(auto i: nums){
            if(i>0) st.insert(i);
        }

        // if set is empty --> koi bhi >0 element present nhi hh
        if(st.empty()){
            int result = INT_MIN;
            for(auto i : nums){
                result = max(result,i);
            }
            return result;
        }

        // else (set is not empty) ---> array k andr positives present hh
        else{
            for(auto s: st){
                ans += s;
            }
        }

        return ans;
    }
};
