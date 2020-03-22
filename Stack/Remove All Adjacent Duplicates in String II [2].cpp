class Solution {
public:
    string removeDuplicates(string s, int k) {
        char ans[s.size()];
        int i=0;
        int freq[s.size()];
        memset(freq, 0, sizeof(freq));
        for(char ch: s){
            ans[i]=ch;

            if(i>0 && ans[i]==ans[i-1]) {
                freq[i] = freq[i-1] + 1;
            }
            else {
                freq[i]=1;
            }
            
            if(freq[i] == k) {
                i = i - k + 1;
            }
            else {
                i++;
            }
            
        }
        
        string res(ans, i);
        return res;
    }
};
