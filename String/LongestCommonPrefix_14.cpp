class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if(0 == strs.size())
            return ret;
                
        const string &str1 = strs[0];
        for(int i = 0; i < str1.size(); ++i)
        {
            char ch = str1[i];
            int j = 1;
            for(; j < strs.size(); ++j)
            {
                if(i >= strs[j].size() || ch != strs[j][i])
                    return ret;
            }
            
            ret += ch;
        }
        
        return ret;
    }
};
