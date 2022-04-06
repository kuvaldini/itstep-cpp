#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;




// FaceTruck, +3567897654, IT, USA445, Shmukeberg
// Apple, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg

struct Company {
    string name;
    string tel;
    string rod;
    string address;
    string owner;

//    /// for std::set<Company>
//    bool operator<(Company const &other) const {
//        return this->name < other.name;
//    }
};

struct Facebook {
    //std::set<Company> companies_;
    std::vector<Company> companies_;  // MUST filled by read_from_file()
    std::map<string,Company*> companies_by_name;
    std::map<string,Company*> companies_by_tel;

    void index(){
        companies_by_name.clear();
        companies_by_tel.clear();
        for(auto &com : companies_){
            companies_by_name.insert({com.name, &com});
            companies_by_tel.insert({com.tel, &com});
        }
    }

    const Company& search_by_name(std::string const& na){
//        auto it = find_if(companies_.begin(), companies_.end(), [&](Company&co){
//            return co.name == na;
//        });
#if  0
        auto it = companies_.find(Company{na});
        if(it != end(companies_))
            return *it;
        else
            throw std::runtime_error("no such company");
#endif
        auto it = companies_by_name.find(na);
        if(it != end(companies_by_name))
            return *it->second;
        else
            throw std::runtime_error("no such company");
    }
    Company& search_by_tel(std::string const& te){
        auto it = companies_by_tel.find(te);
        if(it != end(companies_by_tel))
            return *it->second;
        else
            throw std::runtime_error("no such company");
    }
    Company& search_by_address();
};

int main(){
    //TODO Facebook.read_from_file("file_path.txt");
    Facebook fb {
        {
            {"ApplesCom","A123"},
            {"Yahoos.org", "B456"},
            {"Mozila.corp", "C765"}
        } //compamies_
    };
    fb.index();
    cout << fb.search_by_name("ApplesCom").tel <<endl;
    cout << fb.search_by_name("Yahoos.org").tel << endl;
    cout << fb.search_by_name("Mozila.corp").tel << endl;
    fb.search_by_name("asd");

}

vector
ApplesCom A123
Yahoo B456
Mozila C765

by name
Apple    -> vec[0]
Mozila   -> vec[2]
Yahoo    -> vec[1]

by tel
A123     -> vec[0]
B456
C765
