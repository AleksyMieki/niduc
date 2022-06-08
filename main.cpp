
#include <iostream>
#include <fstream>
#include <string>
#include "bitset"
#include "algorithm"
#include "ios"
#include "BBS.h"
#include "FILE_SERVICE/DataReader.h"



int main () {

    DataReader dataReader;
    //std::cout << dataReader.getSeed();
    BBS* bbs = new BBS(dataReader.GetPrimeNumbers().substr(0,dataReader.GetPrimeNumbers().length()/2),dataReader.GetPrimeNumbers().substr(dataReader.GetPrimeNumbers().length()/2),dataReader.getSeed()) ;


delete bbs;


    return 0;
}