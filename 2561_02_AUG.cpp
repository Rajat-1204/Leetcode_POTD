class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Initialize variable
        map<int,int> freq;
        long long ans = 0;

        // update freq. map
        // add krne hh freq of b1
        for(auto b: basket1){
            freq[b]++;
        }

        // negate krna hh freq of b2
        for(auto b: basket2){
            freq[b]--;
        }

        // smallest element find krna hh
        long long m = freq.begin() -> first;

        //vectors ko create krna hh t1 and t2
        vector<long long> t1;
        vector<long long> t2;

        for(auto x: freq){
            if(x.second % 2 != 0){   /// not possible to equalize
                return -1;   
            }

            if(x.second > 0){   // b1 excess
                int temp = x.second/2;
                while(temp-- > 0){
                    t1.push_back(x.first);
                }
            }
            else if(x.second < 0){  // b2 excess
                int temp = (-x.second)/2;
                while(temp-- > 0){
                    t2.push_back(x.first);
                }
            }
        }

        // reverse 
        reverse(t2.begin(),t2.end());

        // find costing - direct or indirect
        for(int i = 0;i<t1.size();i++){
            long long direct = min(t1[i],t2[i]);
            long long indirect = 2 * m;

            ans += min(direct,indirect);
        }
        return ans;
    }
};
