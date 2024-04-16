#pragma once


class investment{
    double S;
    int n;
    double * w;
    double * r;

    double V;
    double rate_of_return;
public:
    investment();

    void print();
    ~investment();

};
