//
// Created by sultansoy on 29.10.17.
//

#ifndef PROJECT_CURRENCYTYPE_HPP
#define PROJECT_CURRENCYTYPE_HPP

#include <iostream>

typedef unsigned long long INT;

class CurrencyType {

    INT val;

    CurrencyType(INT _val) {
        val = _val;
    }

public:

    CurrencyType() {
        val = 0;
    }

    CurrencyType(INT intUnit, INT fractUnit) {
        val = intUnit * 100 + fractUnit;
    }

    CurrencyType(double _val) {
        INT intUnit = (INT)_val;
        INT fractUnit = ((INT)_val - intUnit);
        val = intUnit * 100 + fractUnit;
    }

    bool operator>(const CurrencyType& other) {
        return val > other.val;
    }
    bool operator<(const CurrencyType& other) {
        return val < other.val;
    }
    bool operator>=(const CurrencyType& other) {
        return val >= other.val;
    }
    bool operator<=(const CurrencyType& other) {
        return val <= other.val;
    }
    bool operator==(const CurrencyType& other) {
        return val == other.val;
    }
    bool operator!=(const CurrencyType& other) {
        return val != other.val;
    }
    CurrencyType operator=(const CurrencyType& other) {
        val = other.val;
        return CurrencyType(val);
    }
    CurrencyType operator+(const CurrencyType& other) {
        return CurrencyType(val + other.val);
    }
    CurrencyType operator-(const CurrencyType& other) {
        return CurrencyType(val - other.val);
    }
    CurrencyType operator*(const CurrencyType& other) {
        return CurrencyType(val * other.val);
    }
    CurrencyType operator/(const CurrencyType& other) {
        return CurrencyType(val / other.val);
    }
    CurrencyType operator+=(const CurrencyType& other) {
        val += other.val;
        return CurrencyType(val);
    }
    CurrencyType operator-=(const CurrencyType& other) {
        val -= other.val;
        return CurrencyType(val);
    }
    CurrencyType operator*=(const CurrencyType& other) {
        val *= other.val;
        return CurrencyType(val);
    }
    CurrencyType operator/=(const CurrencyType& other) {
        val /= other.val;
        return CurrencyType(val);
    }

    friend std::ostream& operator<<(std::ostream& os, const CurrencyType& c);
    friend std::istream& operator>>(std::istream& is, CurrencyType& c);

};

std::ostream& operator<<(std::ostream& os, const CurrencyType& c) {
    os << c.val / 100 << '.';
    int fractUnit = c.val % 100;
    if(fractUnit % 100 < 10) {
        os << 0;
    }
    os << fractUnit;
    return os;
}

std::istream& operator>>(std::istream& is, CurrencyType& c) {
    c.val = 0;
    INT intUnit, fractUnit;
    char dot;
    is >> intUnit >> dot >> fractUnit;
    if((dot == '.' || dot == ',') && fractUnit / 100 == 0) {
        if(fractUnit / 10 == 0) {
            fractUnit *= 10;
        }
        c.val = intUnit * 100 + fractUnit;
    }
    return is;
}

#endif //PROJECT_CURRENCYTYPE_HPP
