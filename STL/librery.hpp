#include <iostream>
#include <cstring>
#include <string>
#include <queue>

namespace stl {
    std::string Creator_name = "Wanglaos";
    std::queue<int> q;
    template<class T>
    class DSU {
        private:
            
    };


// class date 
    class date {

    private:
        size_t _year, _month, _day;

    public: 
        
        date(size_t year = 1, size_t month = 1, size_t day = 1): _year(year), _month(month), _day(day) {}
        date(const date& d): _year(d._year),  _month(d._month), _day(d._day) { }
        
        void reset(size_t year = 1, size_t month = 1, size_t day = 1);

        void operator=(const date& d) {
            this->_year = d._year;
            this->_day = d._day;
            this->_month = d._month;

        }

        date operator+(int increasement) {
            if (increasement > 100000000) return *this;
            date tmp(*this);
            int mod = 31;
            while (increasement -- )
            {
                
                if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0) {
                    if (_month == 2) {
                        mod = 29;
                    }
                    else if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) mod = 31;
                    else mod = 30;
                }
                else {
                    if (_month == 2) mod = 28;
                    else if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) mod = 31;
                    else mod = 30;
                }
                _day ++ ;
                if (_day > mod) _month ++, _day = 1 ;
                if (_month > 12) _year ++ , _month = 1;
            }
            date res(*this);
            *this = tmp;
            return res;
        } 

        date& operator+=(int increasement) {
            if (increasement > 100000000) return *this;
            *this = *this + increasement;
        }


        date operator-(int decrease) {
            if (*this - date(1600, 1, 1) < decrease) return *this;
            int nt = 31;
            date tmp(*this);

            date res = *this;
            *this = tmp;
            return res;
        }
        int operator-(const date& d) {
            date tmp = *this;
            if (d._year > this->_year) return 0;
            else if (d._year == this->_year) {
                if (d._month > this->_month) return 0;
                if (d._month == this->_month) {
                    if (d._day > this->_day) return 0;
                }
            }
            int res = 0;
            int nt = 31;
            while (tmp._year != d._year || tmp._day != d._day || tmp._month != d._month) {
                if (tmp._year % 4 == 0 && tmp._year % 100 != 0 || tmp._year % 400 == 0) {
                    if (tmp._month - 1 == 2) {
                        nt = 29;
                    }
                    else if (tmp._month - 1 == 1 || tmp._month - 1 == 3 || tmp._month - 1 == 5 || tmp._month - 1 == 7 || tmp._month - 1 == 8 || tmp._month - 1 == 10 || tmp._month - 1 == 0) nt = 31;
                    else nt = 30;
                }
                else {
                    if (tmp._month - 1 == 2) nt = 28;
                    else if (tmp._month - 1 == 1 || tmp._month - 1 == 3 || tmp._month - 1 == 5 || tmp._month - 1 == 7 || tmp._month - 1 == 8 || tmp._month - 1 == 10 || tmp._month - 1 == 0) nt = 31;
                    else nt = 30;
                }
                tmp._day -- ;
                if (tmp._day == 0) tmp._day = nt, tmp._month -- ;
                if (tmp._month == 0) tmp._month = 12, tmp._year -- ;
                res ++ ;
            }
            return res;
        }
        date& operator-=(int decrease) {
            if (*this - date(1600, 1, 1) < decrease) return *this;
            *this = *this - decrease;
            return *this;
        }
        
        void print() {
            std::cout << _year << ' ' << _month << ' ' << _day << std::endl;
        }

        
        bool operator<(const date& d) {
            if (this->_year < d._year) return true;
            if (this->_month < d._month) return true;
            if (this->_day < d._day) return true;

    return false;
        }
        bool operator<=(const date& d) {
            if (*this < d || *this == d) return true;
        }
        bool operator==(const date& d) {
            if (this->_year == d._year && this->_month == d._month && this->_day == d._day) return true;
            return false;
        }
        bool operator>(const date& d) {
            if (!(*this == d) && !(*this < d)) return true;
            return false;   
        }
        bool operator>=(const date& d) {
            if (*this == d || !(*this < d)) return true;
            return false;
        }
        ~date() {}
    };
// class date end
}