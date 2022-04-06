#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

/// SAMPLE FILE:
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
};

struct Facebook {
    std::vector<Company> companies_;  // MUST filled by read_from_file()

    const Company& search_by_name(std::string const& na){
        auto it = find_if(companies_.begin(), companies_.end(), [&](Company&co){
            return co.name == na;
        });
        if(it != end(companies_by_name))
            return *it->second;
        else
            throw std::runtime_error("no such company");
    }
    Company& search_by_tel(std::string const& te){
        auto it = find_if(companies_.begin(), companies_.end(), [&](Company&co){
            return co.tel == te;
        });
        if(it != end(companies_by_name))
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
        } //compamies
    };
    cout << fb.search_by_name("ApplesCom").tel <<endl;
    cout << fb.search_by_name("Yahoos.org").tel << endl;
    cout << fb.search_by_name("Mozila.corp").tel << endl;
    //search_by_tel("123456");
    fb.search_by_name("asd");
}
