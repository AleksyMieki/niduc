//
// Created by aleks on 05.05.22.
//
#pragma once
#ifndef NIDUC_BBS_H
#define NIDUC_BBS_H
#include "cmath"
#include "iostream"
#include "FILE_SERVICE/DataReader.h"
#include "sstream"

class BBS{
/**
 * a class implementing blum blum shum algorithm used to generate random numbers
 */
private:
    //variables

    std::string  p, q, n, decryptionExp;
    std::string x0;
public:

    //constructos and destructor
    BBS(std::string p, std::string q, std::string seed);
    ~BBS();
    //getters
    std::string getN();

    //generator functions
    int getRandBit();
    std::string getRandNum();


    //number modulating functions
   static std::string multiply(std::string nums1, std::string nums2);
    std::string div(std::string a,std::string b);
    bool Compare(std::string first,std::string second);
    std::string sub(std::string num1,std::string num2);

};


#endif //NIDUC_BBS_H
