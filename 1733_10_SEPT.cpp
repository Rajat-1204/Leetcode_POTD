class Solution {
public:
    // Function for checking user is problematic or not
    bool check(vector<int>& a,vector<int>& b){
        for(int i = 0;i<a.size();i++){
            for(int j = 0;j<b.size();j++){
                if(a[i] == b[j]){
                    return true;
                }
            }
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // intialize variables
        set<int> prob;
        unordered_map<int,int> comm;
        int maxFreq = 0;

        // find user who cannot communicate
        for(int i = 0;i<friendships.size();i++){
            int u = friendships[i][0]-1;
            int v = friendships[i][1]-1;

            if(!check(languages[u],languages[v])){
                prob.insert(u);
                prob.insert(v);
            }
        }

        // count most common lang. among problamatic users
        for(auto user: prob){
            for(int lang : languages[user]){
                comm[lang]++;
                maxFreq = max(maxFreq,comm[lang]);
            }
        }

        // ans return
        return prob.size()-maxFreq;
    }
};

// n = 2
// l = [[1],[2],[1,2]]
// f = [[1,2],[1,3],[2,3]]

// problematic = {1,2}

// common language = 1 -> 1:1
//                   2 -> 2:1

// problematic - maxfreq = ans
// ans = 2 - 1 -> 1

// n = 3
// l = [[2],[1,3],[1,2],[3]]
// f = [[1,4],[1,2],[3,4],[2,3]]

// p(set) = {1,4,2,3}

// common language: 2:2 3:2 1:2 maxfreq = 2

// ans = 4 - 2 = 2
