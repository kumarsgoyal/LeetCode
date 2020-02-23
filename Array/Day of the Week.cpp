class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1600-1699 = 6
        // 1700-1799 = 4
        // 1800-1899 = 2
        // 1900-1999 = 0
        // 2000-2099 = 6
        
        int monthcodeord[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6}; 
        int monthcodeleap[] = {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6}; 
        string daycode[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        
        map<int, int> mapp;
        mapp.insert({19, 0});
        mapp.insert({20, 6});
        // day + mon + year + year/4 +year(code)
        
        // leapyear
        if((year%4 == 0) && (year%100 != 0)) {
            int index = (day + monthcodeleap[month-1] + year%100 + (year%100)/4 + mapp.find(year/100)->second) % 7;
            return daycode[index ];
        }
        // leapyear and also century year
        else if((year%4 == 0) && (year%100 == 0) && (year%400 == 0)) {
            int index = (day + monthcodeleap[month-1] + year%100 + (year%100)/4 + mapp.find(year/100)->second) % 7;
            return daycode[index];
        }
        else {
            int index = (day + monthcodeord[month-1] + year%100 + (year%100)/4 + mapp.find(year/100)->second) % 7; 
            return daycode[index];
        }
        
    }
};
