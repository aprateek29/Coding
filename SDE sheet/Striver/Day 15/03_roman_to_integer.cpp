// leetcode

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int sum = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (i < n-1 && s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) {
                sum -= (2*m[s[i]]);
            } else if (i < n-1 && s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) {
                sum -= (2*m[s[i]]);
            } else if (i < n-1 && s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
                sum -= (2*m[s[i]]);
            }
            
           sum += m[s[i]];
        }
        return sum;
    }
};