class Solution {
public:
    //function used for finding the element from i to last
    static int getmax(string s, int i) {
        int max = i;
        for (int j = i; j < s.length(); j++) {
            if (s[max] <= s[j])
                max = j;
        }
        return max;
    }
    int maximumSwap(int num) {
        // coverting number into string
        string s = to_string(num);
        string s1 = s;
        //this is used to swap the number with the maximum one
        for (int i = 0; i < s.length(); i++) {
            int temp = getmax(s, i);
            swap(s[i], s[temp]);
            // if after swapping the number we obtained is different
            // then we should break it off; 
            if (s1 != s)   
                break;
        }
        // conerting string to integer again
        int number = stoi(s);
        return number;
    }
};
