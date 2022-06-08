//
// Created by aleks on 15.04.22.
//

#include <algorithm>
#include "Encryption.h"




std::string Encryption::TextToBinaryString(std::string s) {

    std::string binaryString;
    for (char &_char: s) {
        binaryString += std::bitset<1>(_char).to_string();
    }
    return binaryString;

}