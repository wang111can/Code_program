// please contact me by email(cc4096vwc@gmail) if there are any bugs or flows 
#include "librery.hpp" 



// class date
// begin 

stl::date stl::date::operator=(const date& d) {
    this->_year = d._year;
    this->_day = d._day;
    this->_month = d._month;

}

stl::date stl::date::operator+(int increasement) {
    if (increasement < 0) {
        return *this - abs(increasement);
    }
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

 stl::date& stl::date::operator+=(const int increasement) {

    if (increasement > 100000000) return *this;
    if (increasement < 0) 
        *this =  *this - abs(increasement);
    else 
        *this = *this + increasement;
    return *this;
}

stl::date stl::date::operator-(int decrease) {
    if (decrease < 0) {
        return *this + abs(decrease);
    }
    if (*this - date(1600, 1, 1) < decrease) return *this;
    date tmp = *this;
    int nt = 31;
    while (decrease -- ) {
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
    }
    return tmp;
}
stl::date& stl::date::operator--() {
    *this -= 1;
    return *this;
} 
stl::date stl::date::operator--(int) {
    date res (*this);
    *this -= 1;
    return res;
} 


stl::date& stl::date::operator++() {
    *this += 1;
    return *this;
}

stl::date stl::date::operator++(int) {
    date res(*this);
    *this += 1;
    return res;
}
int stl::date::operator-(const date& d) {
    date tmp = *this;
    date target = d;
    if (*this < d) {
        tmp = d, target = *this;
    }
    
    int res = 0;
    int nt = 31;
    while (tmp > target) {
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


stl::date& stl::date::operator-=(int decrease) {
    if (*this - date(1600, 1, 1) < decrease) return *this;
    if (decrease < 0) {
        *this = *this + abs(decrease);
    }
    else *this = *this - decrease;
    return *this;
}


bool stl::date::operator<(const date& d)const {
    if (this->_year < d._year) return true;
    else return false;
    if (this->_month < d._month) return true;
    else return false;
    if (this->_day < d._day) return true;
    else return false;
    return false;
}
bool stl::date::operator<=(const date& d) const{
    if (*this < d || *this == d) return true;
    return false;
} 
bool stl::date::operator==(const date& d) const{
    if (this->_year == d._year && this->_month == d._month && this->_day == d._day) return true;
    return false;
}
bool stl::date::operator>(const date& d) const{
    if (!(*this == d) && !(*this < d)) return true;
    return false;   
}
bool stl::date::operator>=(const date& d)const {
    if (*this == d || !(*this < d)) return true;
    return false;
}

std::ostream& stl::operator<<(std::ostream &os, const stl::date& d) {
    os << d._year << '-' << d._month << '-' << d._day;
    return os;
}

// end




// class string


stl::string stl::string::operator=(const string& str) {

}
stl::string stl::string::operator=(const char * str) {

}

stl::string stl::string::operator+(const string& str) {

}
stl::string stl::string::operator+(const char* str) {

}

stl::string& stl::string::operator+=(const string& str) {

}
stl::string& stl::string::operator+=(const char *str) {

}

char& back();
void pop();



// std::ostream& operator<<(std::ostream& os, const stl::string &str) {
 
//     os << str._str;
//     return os;

// }
std::istream& operator>>(std::istream& is, stl::string &str) {
}


const char& stl::string::operator[](const size_t _index)const {
    assert(_index >= 0 && _index < _size);
     return _str[_index];
}
char& stl::string::operator[](const size_t _index) {
    assert(_index >= 0 && _index < _size);
    return _str[_index];
}
const size_t stl::string::npos = 2147483647;

// end