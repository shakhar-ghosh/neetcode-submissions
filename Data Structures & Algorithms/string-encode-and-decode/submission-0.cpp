class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ret;
        ret<< strs.size()<<" ";
        for(const auto& str: strs) {
            ret<<str.size()<< " ";
        }
        ret<<'#';
        for(const auto& str: strs){
            ret<<str;
        }
        return ret.str();
    }

    vector<string> decode(string s) {
        stringstream ss(s);
        int len;
        ss>>len;
        
        vector<int> lens(len);
        vector<string> strs(len);

        for(int i=0; i<len; i++) {
            ss>>lens[i];
        }
        char c;
        ss>>c;
        
        for(int i=0; i<len; i++) {
            strs[i].resize(lens[i]);

            ss.read(&strs[i][0], lens[i]);

            strs[i].resize(ss.gcount());
        }
        return strs;
    }
};
