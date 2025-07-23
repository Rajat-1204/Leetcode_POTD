class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int n = s.length();
        int score = 0;

        // Always prioritize removing the substring that gives more points
        // If x > y, we prefer removing "ab" (worth x), else we prefer "ba" (worth y)
        if(x > y) {
            // Reverse the string and swap the values to treat "ba" as "ab"
            reverse(s.begin(), s.end());
            swap(x, y);
        }

        // First pass: Remove all instances of "ba" (since x <= y now)
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            // If top is 'b' and current char is 'a', we found "ba"
            else if(st.top() == 'b' && s[i] == 'a') {
                st.pop(); // Remove 'b'
                score += y; // Add y points for "ba"
            } else {
                st.push(s[i]); // No match, keep building stack
            }
        }

        // Build remaining string from the stack (in reverse order)
        string temp;
        while(!st.empty()) {
            temp += st.top();
            st.pop();
        }

        // Second pass: Now remove all instances of "ab" from the remaining string
        for(int i = 0; i < temp.length(); i++) {
            if(st.empty()) {
                st.push(temp[i]);
            }
            // If top is 'a' and current char is 'b', we found "ab"
            else if(st.top() == 'a' && temp[i] == 'b') {
                st.pop(); // Remove 'a'
                score += x; // Add x points for "ab"
            } else {
                st.push(temp[i]);
            }
        }

        return score; // Return total maximum score
    }
};
