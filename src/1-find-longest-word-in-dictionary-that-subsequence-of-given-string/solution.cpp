#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
    string Run(const std::string S, const vector<string>& D)
    {
        string ans ="";
        map<uint32_t, vector<int> > char_to_pos_list_mp;
        for(size_t i = 0;  i < S.length() ;++i)
        {
            uint32_t c = (uint32_t)S.at(i);
            char_to_pos_list_mp[c].push_back(i);
        }

        for(auto d: D)
        {
            if(d.length() > ans.length() && isSubSeqOfS(d,char_to_pos_list_mp))
            {
                ans = d;
            }
        }

        return ans;
    }
private:
    bool isSubSeqOfS(const string& s, const map<uint32_t, vector<int> >& char_to_pos_list_mp)
    {
        int last_pos = -1;
        for(auto c : s)
        {
            uint32_t i_c = uint32_t(c);
            auto iter = char_to_pos_list_mp.find(i_c);
            if(iter == char_to_pos_list_mp.end())
            {
                return false;
            }
            else
            {
                last_pos = getNextPosBiggerThanPos(last_pos, iter->second);
                if(last_pos == -1)
                    return false;
            }
        }
        return true;
    }

    int getNextPosBiggerThanPos(int pos, const vector<int> pos_list)
    {
        int l = 0;
        int r = pos_list.size() -1;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + ( (r-l)>>1);
            if(pos_list[mid] > pos)
            {
                ans = pos_list[mid];
                r = mid -1;
            }
            else
            {
                l = mid +1;
            }
        }
        return ans;
    }
};

int main()
{
    string S = "abppplee";
    vector<string> D;
    //{string("able"), string("ale"), string("apple"), string("bale"), string("kangaroo")};
    
    D.push_back("able");
    D.push_back("ale");
    D.push_back("apple");
    D.push_back("bale");
    D.push_back("kangaroo");
    cout << Solution().Run(S, D) << endl;
    return 0;
}
