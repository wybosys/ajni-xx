#include "cross.hpp"
#include "str.hpp"
#include <sstream>
#include <regex>
#include <cctype>
#include <algorithm>

CROSS_BEGIN

strings explode(string const &str, string const &delimeter, bool skipempty) {
    strings ret;
    size_t sid = 0, eid = 0;
    while ((eid = str.find(delimeter, sid)) < str.size()) {
        string val = str.substr(sid, eid - sid);
        if (!skipempty || val.length())
            ret.push_back(val);
        sid = eid + delimeter.size();
    }
    if (sid < str.size()) {
        string val = str.substr(sid);
        if (!skipempty || val.length())
            ret.push_back(val);
    }
    return ret;
}

string implode(strings const &str, string const &delimeter) {
    const size_t l = str.size();
    if (l) {
        string r = str[0];
        for (auto i = str.begin() + 1; i != str.end(); ++i)
            r += delimeter + *i;
        return r;
    }
    return "";
}

bool beginwith(string const &str, string const &tgt) {
    if (str.length() < tgt.length())
        return false;
    return str.substr(0, tgt.length()) == tgt;
}

bool endwith(string const &str, string const &tgt) {
    if (str.length() < tgt.length())
        return false;
    return str.substr(str.length() - tgt.length(), tgt.length()) == tgt;
}

template<typename T>
inline T fromstr(string const &str) {
    ::std::istringstream iss(str);
    T v;
    iss >> v;
    return v;
}

int toint(string const &str) {
    return fromstr<int>(str);
}

float tofloat(string const &str) {
    return fromstr<float>(str);
}

double todouble(string const &str) {
    return fromstr<double>(str);
}

template<typename T>
inline string tostr(T v) {
    ::std::ostringstream oss;
    oss.setf(::std::ios::fixed);
    oss << v;
    return oss.str();
}

string tostr(int v) {
    return tostr<int>(v);
}

string tostr(unsigned int v) {
    return tostr<unsigned int>(v);
}

string trim_decimal_string(string const& str)
{
    auto dotpos = str.find('.');
    const size_t lr = str.length();
    size_t dels = 0;
    for (size_t p = lr - 1; p > dotpos; --p) {
        if (str.at(p) == '0') {
            ++dels;
        }
        else {
            break;
        }
    }
    if (dels) {
        // 如果删除的和dotpos加起来等于总长，则需要删掉dot的位置
        if (dotpos + dels + 1 == lr) {
            ++dels;
        }
        return str.substr(0, lr - dels);
    }
    return str;
}

string tostr(float v, bool trim) {
    auto r = tostr<float>(v);    
    return trim ? trim_decimal_string(r) : r;
}

string tostr(double v, bool trim) {
    auto r = tostr<double>(v);
    return trim ? trim_decimal_string(r) : r;
}

string tostr(unsigned long long v) {
    return tostr<unsigned long long>(v);
}

string replace(string const &str, string const &pat, string const &tgt) {
    return ::std::regex_replace(str, ::std::regex(pat), tgt);
}

string toupper(string const& str)
{
    string s = str;
    ::std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

string tolower(string const& str)
{
    string s = str;
    ::std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}


CROSS_END
