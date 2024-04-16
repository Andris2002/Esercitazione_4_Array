#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


investment::investment(){
    ifstream data("data.csv");
    char delimiter = ';';
    string s;
    stringstream ss;

    if (data.is_open()){

        data >> s;
        s = s.substr(s.find(delimiter) +1, s.size());
        ss << s;
        ss >> S;
        ss.str(std::string());

        n;
        data >> s;
        s = s.substr(s.find(delimiter) +1, s.size());
        n = stoi(s);

        data >> s;
        w = new double[n];
        r = new double[n];
        for (int i = 0; i < n; i++){
            data >> s;
            w[i] = stod(s.substr(0,s.find(delimiter)));
            r[i] = stod(s.substr(s.find(delimiter)+1, s.size()));
        }

    }

    rate_of_return = 0;
    for (int i = 0; i<n; i++){
        rate_of_return += r[i]*w[i];
    }
    V = (1+ rate_of_return)*S;


}

investment::~investment(){
    delete [] w;
    delete [] r;
}



void investment::print(){

    ofstream of("result.txt");

    if (of.is_open()){
        of<< "S = " << S << ", n = "<< n<< endl;
        of << "w = [ ";
        for (int i = 0; i<n; i++){
            of <<w[i] << " ";
        }
        of << "]" << endl;

        of << "r = [ ";
        for (int i = 0; i<n; i++){
            of <<r[i] << " ";
        }
        of << "]" << endl;
        of << "Rate of return of the portfolio: "<< rate_of_return<< endl;
        of<< "V: "<< V << endl;

    }
    ifstream result("result.txt");
    if (result.is_open()){
        string line;
        while(getline(result,line)){
            cout <<line<< endl;
        }
    }
}
