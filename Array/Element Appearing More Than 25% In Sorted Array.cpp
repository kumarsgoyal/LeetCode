class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ele = arr[0];
        int max = 0;
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            int j = i+1;
            int freq = 1;
            while(j < size && arr[i] == arr[j]) {
                freq++;
                j++;
            }
            if(freq > max) {
                max = freq;
                ele = arr[i];
            }
            i = j;
        }
        return ele;
    }
};
