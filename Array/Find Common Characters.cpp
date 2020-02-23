class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int ch[26] = {0};
        map<char, int> mapp;
        string temp;
        int len = 0 ;
        auto i = A.begin();
        vector<string> res;
        
        temp = *i; // store first string in temp
        len = temp.size();
        
        // cal frequency of first string
        for(int j = 0; j < len; j++) {
            mapp[temp[j]]++;
        }
        
        
        
        
        // store frequncy of string
        for(auto z = mapp.begin(); z != mapp.end(); z++) {
            ch[z->first - 'a'] = z->second;
        }
        mapp.clear(); // clear data of map
        i++;
        
        for(; i != A.end(); i++) {
            temp = *i; // store first string in temp
            len = temp.size();

            // cal frequency of string
            for(int j = 0; j < len; j++) {
                mapp[temp[j]]++;
            }
    

            
            for(int j = 0; j < 26; j++) {
                int x = (mapp.find(('a'+j))->first == ('a'+j)) ? mapp.find(('a'+j))->second : 0;
                ch[j] = min(ch[j], x);
            }
            mapp.clear(); // clear map data
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < ch[i]; j++) {
                 string tempp;
                 tempp.push_back(('a'+i));
                cout<<tempp;
                res.push_back(tempp);
                
            }
        }
        
        return res;
    }
    
};
