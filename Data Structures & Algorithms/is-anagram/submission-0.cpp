class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
            return false;
        map<char, int> mp_s,mp_t;
        for(int i=0; i<s.size(); i++)
        {
            mp_s[s[i]]++;
            mp_t[t[i]]++;
        }
        if(mp_s == mp_t)
            return true;
        else return false;
    }
};
