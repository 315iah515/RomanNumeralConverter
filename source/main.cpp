//========================================================================================
//  File Name:
//      main.cpp
//
//      driver for Converting arabic numbers To roman numerals
//
//  Authors:
//      Ian Heaton
//
//
//========================================================================================
//

#include <iostream>
#include <cassert>
#include "arabic_toroman.hpp"

int main(int argc, char *argv[])
{

    ArabicConverter Ac;

    std::string Result = Ac.ConvertToRoman(133);
    std::cout << "133 converted to roman numerals is : " << Result << std::endl;
    assert("CXXXIII" == Result);

    Result = Ac.ConvertToRoman(3777);
    std::cout << "3777 converted to roman numerals is : " << Result << std::endl;
    assert("MMMDCCLXXVII" == Result);

    Result = Ac.ConvertToRoman(521);
    std::cout << "521 converted to roman numerals is : " << Result << std::endl;
    assert("DXXI" == Result);

    Result = Ac.ConvertToRoman(42);
    std::cout << "42 converted to roman numerals is : " << Result << std::endl;
    assert("XLII" == Result);

    unsigned int IntResult;
    IntResult = Ac.ConvertToAarabic("DXXI");
    assert(IntResult == 521);
    std::cout << "DXXI converted to arabic numbers is : " << IntResult << std::endl;

    IntResult = Ac.ConvertToAarabic("CXXXIII");
    assert(IntResult == 133);
    std::cout << "CXXXIII converted to arabic numbers is : " << IntResult << std::endl;

    IntResult = Ac.ConvertToAarabic("MMMDCCLXXVII");
    assert(IntResult == 3777);
    std::cout << "MMMDCCLXXVII converted to arabic numbers is : " << IntResult << std::endl;

    IntResult = Ac.ConvertToAarabic("XLII");
    assert(IntResult == 42);
    std::cout << "XLII converted to arabic numbers is : " << IntResult << std::endl;

}
