
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        
        for (const std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        
        std::vector<std::vector<std::string>> ret;
        ret.reserve(mp.size());
        for (auto& [key, group] : mp) {
            ret.push_back(std::move(group));
        }
        
        return ret;
    }
};
