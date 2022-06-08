//
// Created by aleks on 05.05.22.
//

#include "BBS.h"


//default constructor
BBS::BBS(std::string p, std::string q, std::string seed)
{
    //default insecure params

    this->p = p;//dataReader1->GetPrimeNumbers().substr(0,dataReader1->GetPrimeNumbers().length()/2);
    this->q = q;//dataReader1->GetPrimeNumbers().substr(dataReader1->GetPrimeNumbers().length()/2);
    //seed
    this->x0 = seed;//dataReader1->getSeed();

    //product of P & Q
    this->n = multiply(p,q);
}






/*
    Get next random number
*/

std::string BBS::getRandNum()
{
    std::string nextRandNum = div(multiply(this->x0, this->x0),this->n) ;//% this->n;
    this->x0 = nextRandNum;
    return nextRandNum;
}

/*
    Get next random bit
*/
//int BBS::getRandBit()
//{
////    return this->getRandNum() % 2;
//}



BBS::~BBS(){}

std::string BBS::multiply(std::string nums1, std::string nums2) {

    int a = nums1.size();
    int m = nums2.size();

    std::string ans(a + m, '0');

    for(int i = a - 1; i>=0; i--){
        for(int j = m - 1; j >= 0; j--){
            int l = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i+j+1] = l % 10 + '0';
            ans[i+j] += l / 10 ;
        }
    }
    for(int i = 0; i < m + a; i++){
        if(ans[i] !='0')return ans.substr(i);
    }
    return "0";
}

std::string BBS::getN() {
    return this->n;
}

std::string BBS::div(std::string a, std::string b) {
    //result is the quotient, s is the remainder
    std::string s;
    std::ostringstream result;
    int count,i;


    //This part of the code is to remove the character 0 at the beginning of the string
    {
        int index=0;
        while('0'==a[index])
            index++;
        //Remove the string prefix 0
        a.erase(0,index);
        index=0;
        while('0'==b[index])
            index++;
        //Remove the string prefix 0
        b.erase(0,index);
    }

    //If the dividend is less than the divisor, then the quotient is 0 and the remainder is the dividend
    if(!Compare(a,b))
    {
        return b;
    }
    int len=a.size();
    //simulate the division process
    for(int i=0;i<len;i++)
    {
        count=0;
        s.push_back(a[i]);
        while(Compare(s,b))
        {
            //Use the large number subtraction function to do division
            s=sub(s,b);
            //Count the number of subtraction
            count++;
        }

        //Because it is analog division, count will not be greater than 9
        if(count != 0)
            result<<count;    //s>b add the quotient obtained by each division or, add 0 when s<b
    }

    //cout<<"quotient: "<<result<<", remainder: "<<s<<endl;
    return s;
}


bool BBS::Compare(std::string first,std::string second)
{
    int len1=first.size();
    int len2=second.size();
    if(len1<len2)
        return false;
    else if(len1==len2 && first<second)
        return false;
    return true;
}

std::string BBS::sub(std::string num1,std::string num2)
{
    //fushu is used to determine whether the final result is a negative number
    bool fushu = false;
    //If the number of minus digits is less than the minus number, then the result is a negative number. At the same time, the two strings exchange order, the larger number decreases the number
    if(num1.size()<num2.size())
    {
        std::string temp = num1;
        num1 = num2;
        num2 = temp;
        fushu = true;
    }
        //The two numbers have the same length. At this time, you need to determine which number is greater. If the subtracted number is less than the subtracted number, the result is a negative number. At the same time, the two strings exchange order, and the larger number decreases the number
    else if(num1.size() == num2.size())
    {
        int len = num1.size();
        for(int i=0;i<len;++i)
        {
            if(num1[i] == num2[i])
                continue;
            if(num1[i]>num2[i])
                break;
            if(num1[i]<num2[i])
            {
                std::string temp = num1;
                num1 = num2;
                num2 = temp;
                fushu = true;
            }
        }
    }
    int lenNum1 = num1.size();
    int lenNum2 = num2.size();

    //Used to save the result
    int* result = new int[lenNum1];
    int index = 0;
    //num1 31 num2 29 result 1,3
    //Put the result of the dividend into the result first
    for(int i=lenNum1-1;i >=0;--i)
        result[index++]=num1[i]-'0';

    //Perform subtraction
    index = 0;
    for(int i=lenNum2-1;i>=0;--i)
    {
        int num = num2[i]-'0';
        //If the minus is greater than the minus, you need to abdicate
        if(num>result[index])
        {
            result[index+1] -=1;
            result[index] = 10+result[index] - num;
        }
            //Subtract directly
        else
            result[index] = result[index] - num;

        ++index;
    }
    //Clear the 0 at the end of the result, and traverse the index from right to left until the first one is not 0
    index = lenNum1-1;
    while(result[index] == 0)
        --index;


    //Use stringstream to facilitate the output of the array to the string
    std::ostringstream osstr;
    //Determine whether the result is a negative number
    if(fushu == true)
        osstr<<'-';
    for(int i=index;i>=0;--i)
        osstr<<result[i];
    delete result;
    return osstr.str();
}
