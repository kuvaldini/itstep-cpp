#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

template<typename T>
std::ostream& operator<<(ostream&os, vector<T> const& v){
    for(auto &a : v){
        os<<setw(5)<<a<<" ";
    }
    return os;
}
template<typename T>
std::ostream& operator<<(ostream&os, vector<vector<T>> const& w){
    for(auto &v : w){
        os<<v<<"\n";
    }
    return os;
}

void Sort(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size()-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
//                cerr<<v<<endl;
            }
        }
    }
//auto n = v.size();
//auto&a=v;
//    int i = 0, j = 0, tmp;
//    for (i = 0; i < n; i++) {   // loop n times - 1 per element
//        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
//            if (a[j] > a[j + 1]) {  // swop if order is broken
//                tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }
}

int main ()
{
    vector<vector<int>> x;
    for(int i=1; i<=10; ++i){
        vector<int> y;
        for(int j=1; j<=20; ++j){
            y.push_back(i*j);
            cout << setw(5) << y.back() << " ";
        }
        x.push_back(move(y));
        cout << "\n";
    }
    cout << "\n-------------\n";

    std::random_device rd;
    std::mt19937 g(rd());
    for(auto&row:x)
        std::shuffle(row.begin(),row.end(),g);
    std::shuffle(x.begin(),x.end(),g);
    cout << x;

    cout<<"\n+++++++\n";
    Sort(x[0]);
    cout << x[0];
    cout<<"\n+++++++\n";

    cout << "\n-------------\n";
    for(auto&row:x)
        std::sort(row.begin(),row.end(),std::greater{});
    std::sort(x.begin(),x.end(),std::greater{});
    cout << x;
}


template<typename T>
struct Node{
        T data;
        Node<T>* left;
        Node<T>* right;
    };

template <typename T>
SortedList {
    //Node<T> nodes[];
    Node<T>* root;

    Node<T>* push(T x){
        if(root) {
            if (x < root.data) {
                if (root.left)
                    if(x < root.left->data){

                    }
                else{
                    root.left = new Node(x);
                }
            }
            x < root.left->data
        }else{
            return root = new Node<T>(x);
        }
    }
};
