#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

std::string trim_right(const std::string& source, const std::string& whitespaces) {
    std::string str(source);
    return str.erase(str.find_last_not_of(whitespaces) + 1);
}

std::string trim_left(const std::string& source, const std::string& whitespaces) {
    std::string str(source);
    return str.erase(0, str.find_first_not_of(whitespaces));
}

std::string trim(const std::string& source) {
    std::string str(source);
    std::string whitespaces = " \t\r\n\v";
    return trim_left(trim_right(str, whitespaces), whitespaces);
}

static bool checkPurgeAgeInput(std::string& input){
    if(input.empty()) return false;

    std::string str = trim(input);
    if(str.empty()) return false;

    set<std::string> type_map = {
            {"seconds"}, {"minutes"}, {"hours"},
            {"days"}, {"weeks"}, {"months"}
    };


    auto pos = str.find(' ');
    auto start = str.substr(0, pos);
    auto last = str.substr(pos);

    // 띄어쓰기 전까지는 정수이여야함
    bool check_int = true;
    for(auto val : start){
        check_int = std::isdigit(val);
        if(!check_int) return false;
    }

    // 그 이후 위 값중 하나
    last = trim(last);

    set<std::string>::iterator iter;
    iter = type_map.find(last);

    if(iter != type_map.end()){
        return true;
    }else{
        return false;
    }
};

int main() {
    string str1 = "2d5 hours";

    string str2 = " 76546 hours ";

    cout << checkPurgeAgeInput(str1) << endl;
    cout << checkPurgeAgeInput(str2) << endl;


    return 0;
}
