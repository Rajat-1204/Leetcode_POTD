class Solution {
public:
    // function for validation
    bool isValid(int left, int right, int startPos, int k){
        // agr left consider krna hh bss
        if(right <= startPos){
            return startPos - left <= k;
        }
        // agr sirf right consider krna ho tbb
        else if( left >= startPos){
            return right - startPos <= k;
        }
        else{
            int x = startPos - left;
            int y = right - startPos;

            return ((2*x + y <= k) || (2*y + x <= k));
        }
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // intialize Variables
        int n = fruits.size();
        int ans = 0;
        int sum = 0;
        int left = 0;

        // explanding window
        for(int right = 0;right<n;right++){
            // adding values
            sum += fruits[right][1];

            // checking if the range is valid or not
            while(left <= right && !isValid(fruits[left][0],fruits[right][0],startPos,k)){
                sum -= fruits[left++][1];
            }

            // ans = update if greater than previous answer   
            ans = max(ans,sum);
        }
        return ans;
    }
};
