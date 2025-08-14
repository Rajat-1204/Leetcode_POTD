class Solution {
public:
    string largestGoodInteger(string num) {
        // declare ans variable
        string ans;
        // loop jo traverse krega 1 -> n-2
        for(int i = 1;i<num.size()-1;i++){
            // check if previous, current, and next value is same or not
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                // if same then check if it is max or not, and update accordingly
                string integer = string(3,num[i]);
                ans = max(ans,integer);
            }
        }
        // return ans
        return ans;
    }
};
