class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> m;
        stringstream one(s1);
        stringstream two(s2);
        string word;
        while (one >> word)
        {
            m[word]++;
        }
        while (two >> word)
        {
            m[word]++;
        }
        vector<string> ans;
        for (auto i : m)
        {
            if (i.second == 1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};