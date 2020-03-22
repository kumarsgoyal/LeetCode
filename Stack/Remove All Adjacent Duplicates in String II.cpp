class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> stkfreq;
        stack<char> stk;
        
        stk.push('-');
        stkfreq.push(0);
        
        for(int i = 0; i < s.length(); i++) {
            // if character is not same as prev freq is 0
            // else freq is increment of preq freq
            if(stk.top() != s[i]) {
                stk.push(s[i]);
                stkfreq.push(1);
            }
            else {
                stk.push(s[i]);
                stkfreq.push(stkfreq.top() + 1);
            }
            
            
            // if freq of current char is reach k value
            // delete it
            if(stkfreq.top() == k) {
                int count = k;
                while(count--) {
                    stk.pop();
                    stkfreq.pop();
                }
            }
        }
        
        string res; // string to return
        int size = stk.size();
        while(size > 1) {
            res.push_back(stk.top());
            stk.pop();
            // stkfreq.pop();
            size--;
        }
        
        // reverse string 
        int i = 0;
        int j = res.length() - 1;
        char temp;
        while(i < j) {
            temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            i++;
            j--;
        }
        
        return res;
    }
};
