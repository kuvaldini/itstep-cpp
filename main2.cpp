#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <fstream>
#include <iostream>

using namespace std;


struct A {
    string name;
    int age;
    ostream& toBinStream(ostream& os)const{
        return os<<name<<" "<<age;
    }
    istream& fromBinStream(istream&is){
        return is>>name>>age;
    }
    friend ostream& operator<<(ostream& os, A const& a){
        return os << "{ \"name\":\""<<a.name<<"\", \"age\":"<<a.age<<" }";
    }
};

int main(){
//    A a1{"vasya",123}, a2{"ivora",66};
//    cout<<a1<<endl<<a2<<endl;
//
//    {
//        ofstream fs("tre");//,  ios::out | ios::app | ios::trunc);
//        a1.toBinStream(fs);
//        a2.toBinStream(fs);
//    }

    {
        vector<A> vec;
        std::vector<double> kva;
        ifstream ff("tre");
        while(ff){
            A x;
            x.fromBinStream(ff);
            vec.push_back(x);
            cout << x <<endl;
        }
        assert(vec.size() >= 12);
        for(int j=0; j<4; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += vec[i*j].age;
            }
            kva.push_back(sum * 0.05);
        }
        for(int i=0; i<kva.size(); i++)
            cout <<"k"<<(i+1)<<" "<<kva[i]<<endl;
    }

}

#if 0
int main(int argc, char*argv[]){
//    cout<<"HELLO"<<endl;
    auto args = argv;
    while(*argv){
        cout << argv << " " << *argv << endl;
        argv++;
    }
//    if(argc<3) {
//        cout << "expected 3 args. exit with error" << endl;
//        return 2;
//    }
//    ofstream file_stream (args[1]);
//    file_stream<<args[2]<<endl;


    ifstream fin(args[1]);
    int sum=1;
    while(fin.good()){
        int x=11;
        fin>>x;
        if(fin.good()) {
            cout << "--!-- " << x << endl;
            sum *= x;
        }
    }
    cout<<"---"<<endl;
    cout <<sum;

//    string sss;
////    fin >> sss;
//    cout << "FIN contents:" << endl;
////    cout << sss;
//    while(fin.good()){
//        getline(fin,sss);
//        cout<<sss<<endl;
//    }
}
#endif
