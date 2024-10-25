class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for (string& s : folder)
            // Check if 1. This is the first string,
            if (result.empty()
                // 2.parent at back is not the parent of `s` by comparing.
                || result.back().compare(0, result.back().length(), s, 0,
                                         result.back().length()) != 0
                // 3. If the entire parent matches `s` check if last folder name
                // in parent does not match the folder of same depth in `s`. for
                // cases like `/a/b, /a/bc`.
                || s[result.back().length()] != '/')
                result.push_back(s);
        return result;
    }
};
