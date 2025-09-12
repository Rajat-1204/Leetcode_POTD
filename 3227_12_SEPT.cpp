class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                return true;
            }
        }
        return false;
    }
};

// Alice ko jitne k liye 1 vowel chahiye hooga

// "Apple" - 2 Vowel
// Appl   e - alice wins
// Eagle - 3 vowel
// Alice wins

// "bbfg" - 0 vowel
// Bob wins
