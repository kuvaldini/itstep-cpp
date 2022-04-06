#include <iostream>
using namespace std;

class Number {
    //2
    enum class State {
        OK,
        UNDRFLOW,
        OVRFLOW
    };

    unsigned num;
    State state = State::OK;
    //2


public:
    Number() {
        num = 0;
    }
    Number(unsigned numb) {
        num = numb;
    }

    unsigned getNum() {
        return num;
    }

    void underflowSet() {
        state = State::UNDRFLOW;
    }

    void assign(long numb) {
        if (numb < 0) {
            state = State::UNDRFLOW;
            num = 0;
        }
        else if (numb > UINT_MAX) {
            state = State::OVRFLOW;
            num = UINT_MAX;
        }
        else {
            state = State::OK;
            num = numb;
        }
    }

    friend Number operator+(Number a, Number b);

    friend ostream& operator <<(ostream& os, Number const& obj) {
        if (obj.state == Number::State::OVRFLOW) {
            cout << "Value is too high" << endl;
            return os << UINT_MAX << endl;
        }
        else if (obj.state == Number::State::UNDRFLOW) {
            cout << "Value is too low" << endl;
            return os << 0 << endl;
        }
        else
            return os << obj.num << endl;
    }

    Number operator+= (unsigned val) {
        num += val;
        if (num < val) {
            num = UINT_MAX;
            state = Number::State::OVRFLOW;
        }
        return *this;
    }
    Number operator-= (unsigned val) {
        if (num < val) {
            num = 0;
            state = Number::State::UNDRFLOW;
        }
        else num -= val;
        return *this;
    }
    Number operator+= (Number obj) {
        num += obj.num;
        if (num < obj.num) {
            num = UINT_MAX;
            state = Number::State::OVRFLOW;
        }
        return *this;
    }
    Number operator-= (Number obj) {
        if (num < obj.num) {
            num = 0;
            state = Number::State::UNDRFLOW;
        }
        else num -= obj.num;
        return *this;
    }
    Number operator++(int) {
        Number c = *this;
        num++;
        return c;
    }
    Number operator++() {
        num++;
        return *this;
    }
    Number operator--(int) {
        Number c = *this;
        num--;
        return c;
    }
    Number operator--() {
        num--;
        return *this;
    }
};

//6
Number operator+(Number a, Number b) {
    Number c = a.num + b.num;
    if (c.num > UINT_MAX || c.num < a.num) {
        c.state = Number::State::OVRFLOW;
        c.num = UINT_MAX;
    }
    return c;
}
//6

//7
Number operator-(Number a, Number b) {
    Number c = a.getNum() - b.getNum();
    if ((b.getNum() > a.getNum())) {
        c.underflowSet();
        c.assign(0);
    }
    return c;
}
//7

/// TODO 1. Make just one flag using enum
/// TODO 2. Protect members
/// TODO 3. Operator +=(unsigned) -=(unsigned) += -=(Number const&) ++N, N++, N--, --N
/// ToDO 4. assign()
/// ToDo 5. write tests with assert(); flags, numbers overflow, underflow.
/// ToDo 6. fix operator+ as friend without get [const]
/// ToDO 7. fix operator- as member [const]
/// ToDo 8. ADVANCED optional operator *, /, *=, /=
/// ToDO 9. Rewrite operator<<(clog) to non-friend outside.


int main() {
    Number a(4294967295);
    Number b(1);

    //1
    cout << "a + b = " << a + b;
    cout << "b-a = " << b - a;
    //1

    //3
    unsigned value = 100;
    b += value;
    cout << "b += " << value << " = " << b;

    b -= value;
    cout << "b -= " << value << " = " << b;

    a += b;
    cout << "a += b = " << a;

    a -= b;
    cout << "a -= b = " << a;

    cout << "++b = " << ++b;
    cout << "b++ = " << b++;

    cout << "--b = " << --b;
    cout << "b-- = " << b--;
    //3

    //4
    b.assign(-1);
    cout << "b.assign " << b;
    //4
}
