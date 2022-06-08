//
// Created by aleks on 15.04.2022.
//
#pragma once
#include "../BBS.h"
#include "iostream"
#include "bitset"
#include "fstream"
#include "string"
#include "algorithm"
#include "Encryption.h"

#ifndef NIDUC_DATAREADER_H
#define NIDUC_DATAREADER_H

//class for getting data from a txt file to a string and moduling the string to fit our needs, also transforming it into binary
class DataReader : public Encryption
        {

private:
            //variables
            std::string num1;
            std::string num2;
            std::string num3;
            std::string num4;
            std::string num5;
            std::string num6;
            std::string num7;
            std::string num8;
            std::string num9;
            std::string num10;
            std::string seed;

public:
            //constructor
            DataReader();

            //functions to get data from files
            std::string SeedsToString();
            std::string GetPrimeNumbers();

            //string modulation functions
            std::string StringAdjustments1(std::string str1);
             std::string StringAdjustments2(std::string str2);
             std::string StringAdjustments3(std::string str3);
             std::string StringAdjustments4(std::string str4);
            std::string StringAdjustments5(std::string str5);
            std::string StringAdjustments6(std::string str6);
             std::string StringAdjustments7(std::string str7);
             std::string StringAdjustments8(std::string str8);
             std::string StringAdjustments9(std::string str9);
             std::string StringAdjustments10(std::string str10);

            //get data into file function
            static void seedToFile(std::string binary_seed);

            //getters and setters
            const std::string &getNum1() const;
            const std::string &getNum2() const;
            const std::string &getNum3() const;
            const std::string &getNum4() const;
            const std::string &getNum5() const;
            const std::string &getSeed() const;


};


#endif //NIDUC_DATAREADER_H
