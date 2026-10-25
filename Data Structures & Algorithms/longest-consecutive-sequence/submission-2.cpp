class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       map<int, int> mp;
       for(auto& num:nums) {
            mp[num]++;
       }
       int seq_len=0, cur_seq = 0, prev_item=0;
       auto temp = mp.begin();
       prev_item = temp->first;
       for(auto& item:mp) {
            //cout<<item.first<<" "<<prev_item<<" "<<cur_seq<<endl;
            if(item.first == prev_item + 1)
            {
                cur_seq += 1;
            }
            else {
                if(cur_seq > seq_len)
                    seq_len = cur_seq;
                cur_seq = 0;
            }
            prev_item = item.first;
       }
       if(cur_seq > seq_len)
            seq_len = cur_seq;
       return nums.size()>0?seq_len +1:0; 
    }
};
