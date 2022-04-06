#pragma once

#include <string>


struct Company {
    std::string name;
    std::string tel;
    std::string address;
    std::string rod;
    std::string owner;
};

struct AddressBookInterface {

    virtual void fill_from(std::vector<Company> &&) = 0;

    virtual const Company& search_by_name(std::string const&) const = 0;
    virtual const Company& search_by_tel(std::string const&) const = 0;
//    virtual const Company& search_by_address(std::string const&) const = 0;

    virtual const Company& search_by_address(std::string const& adr) const {
        throw std::runtime_error("not implemented yet!");
    }

    virtual int size(){ return 3555; }

    virtual ~AddressBookInterface(){}
};
