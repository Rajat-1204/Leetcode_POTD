class Solution {
public:
    vector<int> sumZero(int n) {
        // Initializing Variables
        vector<int> ans;

        // odd hooga toh extra zero daal do
        if(n%2 != 0){
            ans.push_back(0);
        }

        // Traverse krna hh 
        for(int i = 1;i<=n/2;i++){
            ans.push_back(i);
            ans.push_back(-i);
        }

        // return vector
        return ans;
    }
};


// n = 5
// [-2,2,-1,1,0]

// odd -> zero(0)add krna pdega
// even -> necessary nhi hh

// n = 6
// [1,-1,2,-2,3,-3] sum = 0
// n = 7
// [1,-1,2,-2,3,-3,0] sum = 0
