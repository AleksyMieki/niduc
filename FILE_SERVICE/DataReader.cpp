
#include "DataReader.h"




std::string DataReader::SeedsToString() {

    /**
     * return std::string
     *
     * function returns the insides of btc_value.txt as one string that is later on modulated
     * in apropriate form to create 5 separate numbers
     */
    std::string line;
    std::string str1;
    std::ifstream myfile ("btc_value.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            str1 += line;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return str1;

}
std::string DataReader::GetPrimeNumbers() {

    std::string line;
    std::string str1;
    std::ifstream myfile ("primes.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            str1 += line;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return str1;

}

void DataReader::seedToFile(std::string binary_seed) {


    /**
     * return void
     *
     * function puts our seed in binary into a string that is later used in tests
     */
    std::ofstream out("seeds.txt");
    out << binary_seed;
    out.close();

}


DataReader::DataReader() {

    /**
     * constructor
     * sets numbers as values stored in btc_value.txt to be modulated later on into values that are needed to generate a seed
     * also puts the sum of numbers as a seed into seeds.txt
     */

    this->num1 = SeedsToString();
    this->num2 = SeedsToString();
    this->num3 = SeedsToString();
    this->num4 = SeedsToString();
    this->num5 = SeedsToString();
    this->num6 = SeedsToString();
    this->num7 = SeedsToString();
    this->num8 = SeedsToString();
    this->num9 = SeedsToString();
    this->num10 = SeedsToString();

    this->num1 = StringAdjustments1(this->num1);
    this->num2 = StringAdjustments2(this->num2);
    this->num3 = StringAdjustments3(this->num3);
    this->num4 = StringAdjustments4(this->num4);
    this->num5 = StringAdjustments5(this->num5);
    this->num6 = StringAdjustments1(this->num6);
    this->num7 = StringAdjustments2(this->num7);
    this->num8 = StringAdjustments3(this->num8);
    this->num9 = StringAdjustments4(this->num9);
    this->num10 = StringAdjustments5(this->num10);


   std::string str = BBS::multiply(num1+num2+num3+num4+num5+num6+num7+num8+num9+num10,num1+num2+num3+num4+num5+num6+num7+num8+num9+num10);

    this->seed = BBS::multiply(str,str);

    seedToFile(Encryption::TextToBinaryString(seed));

}

//functions to adjust the strings

std::string DataReader::StringAdjustments1(std::string str1) {


    str1.erase(0, str1.find("BTC")+18);
    str1.erase(0,str1.find('.'));
    str1.erase(str1.find(' '));

    str1.erase(remove(str1.begin(),str1.end(),' '),str1.end());

    str1.erase(remove(str1.begin(),str1.end(),'.'),str1.end());

    return str1;
}

std::string DataReader::StringAdjustments2(std::string str2)
{
    str2.erase(0, str2.find("ETH")+18);
    str2.erase(0,str2.find('.'));
    str2.erase(str2.find(' '));
    str2.erase(remove(str2.begin(),str2.end(),' '),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),'.'),str2.end());
    return str2;
}

std::string DataReader::StringAdjustments3(std::string str3) {

    str3.erase(0, str3.find("USDT")+18);
    str3.erase(0,str3.find('.'));
    str3.erase(str3.find(' '));

    str3.erase(remove(str3.begin(),str3.end(),' '),str3.end());
    str3.erase(remove(str3.begin(),str3.end(),'.'),str3.end());

    return str3;
}

std::string DataReader::StringAdjustments4(std::string str4) {

    str4.erase(0, str4.find("USDC")+18);
    str4.erase(0,str4.find('.'));
    str4.erase(str4.find(' '));

    str4.erase(remove(str4.begin(),str4.end(),' '),str4.end());
    str4.erase(remove(str4.begin(),str4.end(),'.'),str4.end());

    return str4;
}

std::string DataReader::StringAdjustments5(std::string str5) {

    str5.erase(0, str5.find("BNB")+18);
    str5.erase(0,str5.find('.'));
    str5.erase(str5.find(' '));

    str5.erase(remove(str5.begin(),str5.end(),' '),str5.end());
    str5.erase(remove(str5.begin(),str5.end(),'.'),str5.end());

    return str5;
}
std::string DataReader::StringAdjustments6(std::string str6) {

    str6.erase(0, str6.find("ADA")+18);
    str6.erase(0,str6.find('.'));
    str6.erase(str6.find(' '));

    str6.erase(remove(str6.begin(),str6.end(),' '),str6.end());
    str6.erase(remove(str6.begin(),str6.end(),'.'),str6.end());

    return str6;
}
std::string DataReader::StringAdjustments7(std::string str7) {

    str7.erase(0, str7.find("BUSD")+18);
    str7.erase(0,str7.find('.'));
    str7.erase(str7.find(' '));

    str7.erase(remove(str7.begin(),str7.end(),' '),str7.end());
    str7.erase(remove(str7.begin(),str7.end(),'.'),str7.end());

    return str7;
}
std::string DataReader::StringAdjustments8(std::string str7) {

    str7.erase(0, str7.find("XRP")+18);
    str7.erase(0,str7.find('.'));
    str7.erase(str7.find(' '));

    str7.erase(remove(str7.begin(),str7.end(),' '),str7.end());
    str7.erase(remove(str7.begin(),str7.end(),'.'),str7.end());

    return str7;
}
std::string DataReader::StringAdjustments9(std::string str7) {

    str7.erase(0, str7.find("SOL")+18);
    str7.erase(0,str7.find('.'));
    str7.erase(str7.find(' '));

    str7.erase(remove(str7.begin(),str7.end(),' '),str7.end());
    str7.erase(remove(str7.begin(),str7.end(),'.'),str7.end());

    return str7;
}
std::string DataReader::StringAdjustments10(std::string str7) {

    str7.erase(0, str7.find("DOGE")+18);
    str7.erase(0,str7.find('.'));
    str7.erase(str7.find(' '));

    str7.erase(remove(str7.begin(),str7.end(),' '),str7.end());
    str7.erase(remove(str7.begin(),str7.end(),'.'),str7.end());

    return str7;
}

const std::string &DataReader::getNum1() const {

    return num1;
}

const std::string &DataReader::getNum2() const {

    return num2;
}

const std::string &DataReader::getNum3() const {

    return num3;

}

const std::string &DataReader::getNum4() const {

    return num4;

}

const std::string &DataReader::getNum5() const {

    return num5;

}

const std::string &DataReader::getSeed() const {

    return this->seed;

}





