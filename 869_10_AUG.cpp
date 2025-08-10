class Solution {
public:
    // function for frequency finding
    vector<int> getDigitFrequency(int n){
        // vector of 10 values initially containing 0s.
        vector<int> freq(10,0);

        // jbb tkk num zero(0) naah ho jaaye tbb tkk usme se values nikalenge
        while(n > 0){
            // modulo -> last digit
            int digit = n % 10;
            // division -> removving last digit
            n = n / 10;
            // increase that frequency
            freq[digit]++;
        }
        // return vector
        return freq;
    }
    
    bool reorderedPowerOf2(int n) {
        // find the frequency vector of n
        vector<int> targetFreq = getDigitFrequency(n);

        // traverse krenge 2 ki powers k liye 2^0 se 2^31 tkk
        for(int i = 0;i<31;i++){
            // power of 2
            int digit = pow(2,i);
            // frequency vector of that value/digit
            vector<int> currFreq = getDigitFrequency(digit);

            // compare both the frequency vector return true if same
            if(targetFreq == currFreq){
                return true;
            }
        }
        // otherwise false
        return false;
    }
};
