#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;


/// TODO 1. Make just one flag using enum
/// TODO 2. Protect members
/// TODO 3. Operator +=(unsigned) -=(unsigned) += -=(Number const&) ++N, N++, N--, --N
/// ToDO 4. assign() ~ operator=
/// ToDo 5. write tests with assert(); flags, numbers overflow, underflow.
/// ToDo 6. fix operator+ as friend without get [const]
/// ToDO 7. fix operator- as member [const]
/// ToDo 8. ADVANCED optional operator *, /, *=, /=
/// ToDO 9. Rewrite operator<<(clog) to non-friend outside.

struct Number {
private:
    unsigned num = 0;
    bool underflow_flag = false, overflow_flag = false;


public:
    Number(){}
    Number(unsigned n) : num(n){}
    Number(const Number& other):num(other.num){}

    bool is_valid() const {
        return !underflow_flag and not overflow_flag;
    }

    unsigned get()const{
        return num;
    }
    bool is_underflow()const{
        return underflow_flag;
    }
    bool is_overflow()const{
        return overflow_flag;
    }

#if 0
    void set_underflow(){
        underflow_flag = true;
    }
    void set_overflow(){
        overflow_flag = true;
    }
#endif

    Number& reset(){
        return *this = {};
    }

    Number& operator=(unsigned x){
        num = x;
        underflow_flag = overflow_flag =false;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream&os, Number const& n){
        if(n.underflow_flag)
            return os<<"UF";
        if(n.overflow_flag)
            return os<<"OF";
        return os<<n.num;
    }

//    Number operator+(const Number& other){
//
//    }

    friend Number operator+(const Number a, Number const b) {
        if(not a.is_valid())
            return a;
        if(! b.is_valid())
            return b;
        auto c = a.get() + b.get();
        if( c < a.get() ) {
            Number x{UINT_MAX};
            x.overflow_flag = true;
            return x;
        }
        return {c};
    }
};
//
//Number operator+(const Number a, Number const b) {
//    if(not a.is_valid())
//        return a;
//    if(! b.is_valid())
//        return b;
//    auto c = a.get() + b.get();
//    if( c < a.get() ) {
//        Number x{UINT_MAX};
//        x.set_overflow();
//        return x;
//    }
//    return {c};
//}
auto operator-(Number a, Number b) ->Number {
    if(not a.is_valid())
        return a;
    if(! b.is_valid())
        return b;
    auto c = a.get() - b.get();
    if( c > a.get() ) {
        Number x{0};
//        x.set_underflow();
        return x;
    }
    return {c};
}

int main() {
    Number a{5}, b{3}, c{UINT_MAX - 2};
    clog << (a-b) << endl;
    clog << (b-a) << endl; // 'undeflow'
    clog << (a+b) << endl;
    clog << (c+a) << endl; // overflow

    auto OF = c+a;
    clog << OF << endl; // 'overflow'
    clog << boolalpha << "OF.is_valid() : "<< OF.is_valid() << endl; // 'overflow'
    clog << (OF+Number{1}) << endl;
    clog << (OF-Number{10000}) << endl;

    OF = 66;
    clog << "66 : " << OF << '\n';

    OF.reset();
    clog << OF.is_valid() << endl;

    clog << OF << endl; // << \n << flush;
    auto x = 4 + OF;
    clog << "x" << x << endl;

    // ToDo OF+=2;
}
