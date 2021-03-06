#include "function.h"
#include <iostream>
#include <set>

namespace oj{

    void insert(std::map<int,String> &ma,int key,const std::string &str){
        std::string tmp;
        if(ma.find(key) != ma.end()) {
            tmp = str +ma.find(key)->second.str;
            ma.erase(ma.find(key));
        } else {
            tmp = str;
        }
        ma.insert(std::pair<int,String>(key,String(tmp)));
    }

    void output(const std::map<int,String> &ma,int begin,int end){
        for(auto &i :ma) {
            if(i.first >= begin && i.first<=end) {
                std::cout << i.second << std::endl;
            }
        }
    }

    void erase(std::map<int,String> &ma,int begin,int end){
        std::set<int> eraseKeys;
        for (auto &i:ma){
            if(i.first>=begin&&i.first<=end)
                eraseKeys.insert(i.first);
        }

        for(auto key:eraseKeys){
            ma.erase(key);
        }
    }

    std::ostream& operator<<(std::ostream &o,const std::map<int,String> &ma){
        for (auto &i:ma){
            o<<i.second<<' ';
        }
        return o;

    }
    

}




