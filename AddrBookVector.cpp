#include "AddressBookInterface.h"

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <memory>

using namespace std;

/// SAMPLE FILE:
// FaceTruck, +3567897654, IT, USA445, Shmukeberg
// Apple, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg
// ASDFGH, +3567897654, IT, USA445, Shmukeberg

struct AddrBookVector : AddressBookInterface {

    virtual void fill_from(std::vector<Company> && veccom) override {
        cout << __PRETTY_FUNCTION__ <<endl;
        companies_ = std::move(veccom);
    }

    const Company& search_by_name(std::string const& na) const override {
        cout << __PRETTY_FUNCTION__ <<endl;
#if 1
        for(auto&co:companies_){
            if(co.name == na)
                return co;
        }
        throw std::runtime_error("no such company");
#else
        auto it = find_if(companies_.begin(), companies_.end(), [&](Company&co){
            return co.name == na;
        });
        if(it != end(companies_by_name))
            return *it->second;
        else
            throw std::runtime_error("no such company");
#endif
    }

    const Company& search_by_tel(std::string const& te) const override{
        cout << "!~!!!!!!!!!!!!!!!!!!" << __PRETTY_FUNCTION__ <<endl;
        for(auto&co:companies_){
            if(co.tel == te)
                return co;
        }
        throw std::runtime_error("no such company");
//        throw std::runtime_error("not implemented yet!");
//        auto it = find_if(companies_.begin(), companies_.end(), [&](Company&co){
//            return co.tel == te;
//        });
//        if(it != end(companies_by_name))
//            return *it->second;
//        else
//            throw std::runtime_error("no such company");
    }

    virtual int size() override {return 23;}

protected:
    std::vector<Company> companies_;  // MUST filled by read_from_file()

};

struct AddrBookMap : AddrBookVector {

    virtual void fill_from(std::vector<Company> && veccom) override {
        cout << __PRETTY_FUNCTION__ <<endl;
        companies_ = std::move(veccom);
        index();
    }
    const Company& search_by_name(std::string const& na) const override {
        cout << "AddrBookMap"<< __func__ <<endl;
        auto it = companies_by_name.find(na);
        if(it != end(companies_by_name))
            return *it->second;
        else
            throw std::runtime_error("no such company with name NAME");
    }
//    const Company& search_by_tel(std::string const& te) const override{
//        cout << "AddrBookMap"<< __func__ <<endl;
//        auto it = companies_by_tel.find(te);
//        if(it != end(companies_by_tel))
//            return *it->second;
//        else
//            throw std::runtime_error("no such company");
//    }

private:
    void index(){
        companies_by_name.clear();
        companies_by_tel.clear();
        for(auto &com : companies_){
            companies_by_name.insert({com.name, &com});
            companies_by_tel.insert({com.tel, &com});
        }
    }

    std::map<string,Company*> companies_by_name;
    std::map<string,Company*> companies_by_tel;
};


double foo() {
    return 2 * 3;
}

int main(){
    shared_ptr<AddressBookInterface> ab;

//        ab = make_shared<AddrBookVector>();
//        ab->search_by_name("ApplesCom");
        ab = make_shared<AddrBookMap>();
//        ab->search_by_name();

    ab->fill_from(
        std::vector<Company>{
            {"ApplesCom",   "A123", "CaliforniaJabs" },
            {"Yahoos.org",  "B456", "Urengoy" },
            {"Mozila.corp", "C765", "Fantamisia" }
        } //compamies
    );


    cout << ab->search_by_name("ApplesCom").tel <<endl;
    cout << ab->search_by_name("Yahoos.org").tel << endl;
    cout << ab->search_by_name("Mozila.corp").tel << endl;


    cout << ab->search_by_tel("A123").tel <<endl;
    cout << ab->search_by_tel("C765").tel << endl;
    cout << ab->search_by_tel("B456").tel << endl;

    cout << ab->search_by_address("CaliforniaJabs").tel << endl;

    //search_by_tel("123456");
    ab->search_by_name("asd");
}
