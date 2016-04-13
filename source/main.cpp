//========================================================================================
//  File Name:
//      main.cpp
//
//  Product:
//      Converts arabic numerals To roman numerals
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
    // should be CXXXIII

    Result = Ac.ConvertToRoman(3777);
    std::cout << "3777 converted to roman numerals is : " << Result << std::endl;
    // should be MMMDCCLXXVII

    Result = Ac.ConvertToRoman(521);
    std::cout << "521 converted to roman numerals is : " << Result << std::endl;
    // should be DXXI

    Result = Ac.ConvertToRoman(42);
    std::cout << "42 converted to roman numerals is : " << Result << std::endl;
    // should be XLII

    unsigned int IntResult;
    IntResult = Ac.ConvertToAarabic("DXXI");
    assert(IntResult == 521);



}
