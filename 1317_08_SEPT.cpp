class Solution {
public:
    // Func to find no zero
    bool noZero(int x){
        while(x){
            if(x%10 == 0){
                return false;
            }
            x = x / 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        // Traverse from 1 to n-1
        for(int a = 1;a<n;a++){
            int b = n - a;
            // if both are no zero then return these  
            if(noZero(a) && noZero(b)){
                return {a,b};
            }
        }
        // return 
        return {};
    }
};


// // n = 11

// 2 + 9 = 11

// - 1 + (10)*
// - 2 + 9


// //  n = 1010
// - 1 + 1009*
// - 11  + 999
