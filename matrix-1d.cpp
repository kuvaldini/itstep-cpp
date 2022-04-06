#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



template<typename T>
class Matrix {
private:
    vector<T> storage_;

public:
    Matrix() = default;
    Matrix(initializer_list<T> il) : storage_(std::move(il)) {}

    size_t size()const{ return storage_.size(); }

    void push_back(T v){
        storage_.push_back(v);
    }

    friend Matrix<T> operator+(Matrix<T> const& m1, Matrix<T> const& m2){
        Matrix<T> x;
        size_t i=0;
        for(;i<m1.size() and i<m2.size(); ++i ){
            x.push_back(m1.storage_[i] + m2.storage_.at(i));
        }
        // at this point i = size of smaller matrix
        for(; i<m1.size(); i++){
            x.push_back(m1.storage_[i]);
        }
        for(;i<m2.size(); i++){
            x.push_back(m2.storage_[i]);
        }
        return x;
    }
    Matrix<T> operator-(Matrix<T> const& m2) const; // m3=m1-m2;

    friend Matrix<T> operator*(Matrix<T> const& m1, Matrix<T> const& m2){

    }
    Matrix<T> operator/(Matrix<T> const& m2) const{
    }

    T max()const{
        if(storage_.empty())
            throw runtime_error("empty!");
        T m = storage_[0];
        for(auto & elem : storage_)
            if( m < elem )
                m = elem;
        return m;
    }
    T const* maxi()const{
        T*m = nullptr;
        for(auto & elem : storage_)
            if( *m < elem )
                m = &elem;
        return m;
    }

    T min()const;

    /// (cout<<m1)<<m2 ;
    friend std::ostream& operator<<(std::ostream&os, Matrix<T> const& m1){
        for(auto& v : m1.storage_)
            os << v << " ";
        return os;
    }

    void reverse(){ std::reverse(storage_.begin(), storage_.end()); }
};


int main(){

    Matrix<int> m1 { 1,5,7,2,3,4,5,7,8 };
    cout << "Matrix1: " << m1 << endl;

    Matrix<int> mi;
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    for(int i=0; i<5; i++){
        mi.push_back(std::rand() % 100);
    }
    cout<<"mi: "<<mi <<endl;

    auto m3 = m1+mi;
    //{1+x,5+y,7+z}
    cout<<"m3=m1+m2: "<<m3 <<endl;

    m3.reverse();
    cout<< "revere:" << m3 << endl;

    Matrix<double> k1 = {1,2,3,4}, k2 = {5,6,7,8};
    cout << "k2 / k1 : " << k2 / k1 <<endl;

#if  0
    Matrix<double> m4;
    cout << "enter array: ";
    string str;
    while(std::getline(cin, str)){
        if(str.empty())
            break;
        m4.push_back(stod(str));
    }
    cout<<"m4: "<<m4<<endl;
#endif

    return 0;
}
