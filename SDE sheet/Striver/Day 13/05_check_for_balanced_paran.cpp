class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (stk.size() == 0)
                {
                    return false;
                }
                else if (stk.top() == '{' && '}' == s[i])
                {
                }
                else if (stk.top() == '[' && ']' == s[i])
                {
                }
                else if (stk.top() == '(' && ')' == s[i])
                {
                }
                else
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        if (stk.size() != 0)
            return false;
        return true;
    }
};