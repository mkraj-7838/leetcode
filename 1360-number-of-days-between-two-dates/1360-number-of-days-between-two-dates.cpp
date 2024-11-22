class Solution {
public:
    vector<int>months={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int>leapMonths={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    int convert(string& date){
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int days = 0;

        // Add days for all years before the given year
        for (int i = 1900; i < year; i++) {
            days += isLeapYear(i) ? 366 : 365;
        }

        // Add days for all months before the given month in the current year
        for (int i = 1; i < month; i++) {
            days += isLeapYear(year) ? leapMonths[i] : months[i];
        }

        // Add the days of the current month
        days += day;

        return days;
    }
    int daysBetweenDates(string date1, string date2) {
        int d1=convert(date1);
        int d2=convert(date2);

        return abs(d1-d2);
    }
};
