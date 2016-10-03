//========================================================================================
//  File Name:
//      arabic_toroman.cpp
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
#include <cstdlib>
#include <array>
#include <regex>
#include <iostream>

#include "arabic_toroman.hpp"

//----------------------------------------------------------------------------------------
// Values used for comparison and division of value to convert. The quotient and
// remainder are both used. The quotient determines how many times the roman numeral is
// appended to the resulting string and the remainder is assigned to the value so that
// the rest of the value is converted.
//----------------------------------------------------------------------------------------
namespace
{
   std::array<unsigned int,13> sRomanValueKeys = {
       1000,
       900,
       500,
       400,
       100,
       90,
       50,
       40,
       10,
       9,
       5,
       4,
       1
   };

   using RomanPair = std::pair<std::string, unsigned int>;
   std::array<RomanPair, 13> sRomanLetters = {
       std::make_pair("M", 1000), //0
       std::make_pair("CM", 900), //1
       std::make_pair("D", 500), // 2
       std::make_pair("CD", 400), // 3
       std::make_pair("C", 100), // 4
       std::make_pair("XC", 90), // 5
       std::make_pair("L", 50),
       std::make_pair("XL", 40),
       std::make_pair("X", 10),
       std::make_pair("IX", 9),
       std::make_pair("V", 5),
       std::make_pair("IV", 4),
       std::make_pair("I", 1)

   };

   // Used for validating Roman Numerials to Arabic numbers
   std::regex sRomanNum("^M?M?M?(CM|CD|D?C?C?C?)(XC|XL|L?X?X?X?)(IX|IV|V?I?I?I?)$");

   std::regex sThousands("^M?M?M?");

   std::regex sHundreds("^C?C?C?");

   std::regex sTens("^X?X?X?");

   std::regex sOnes("^I?I?I?");

}

//----------------------------------------------------------------------------------------
//  Member Function:
//      ArabicConverter()
//
//  Summary:
//      Default constructor
//
//----------------------------------------------------------------------------------------
//
ArabicConverter::ArabicConverter()
{
    BuildMap();
}

//----------------------------------------------------------------------------------------
//  Member Function:
//      ConvertToRoman()
//
//  Summary:
//      Converts the unsigned integer to a string of roman numerials.
//
//
//  Parameters:
//      Value -
//          [in] The value to be converted to roman numerals.
//
//  Returns:
//      String containing the value converted to its roman numeral equivalent.
//
//  Remarks:
//      This algorithm cannot convert values greater than 4999.
//
//----------------------------------------------------------------------------------------
//
std::string
ArabicConverter::ConvertToRoman(unsigned int Value)
{
    std::string RomanResult;

    if (Value > 4999)
    {
        RomanResult = "Sorry algorithm cannot convert values greater than 4999.";
        return RomanResult;
    }

    std::div_t result;
    unsigned int i = 0;

    for (; i < sRomanValueKeys.size() && Value > 0; ++i)
    {
        int Key = sRomanValueKeys[i];

        if (Value >= Key)
        {
            auto Itr = mMap.find(Key);
            result = std::div(Value, Key);
            for (int i = 0; i < result.quot; ++i)
            {
                RomanResult.append(Itr->second);
            }

            Value = result.rem;
        }
    }

    return RomanResult;
}

//----------------------------------------------------------------------------------------
//  Member Function:
//      ConvertToAarabic()
//
//  Summary:
//      Converts a set of Roman Numerals to Arabic numbers
//
//
//  Parameters:
//      RomanNumerial -
//          [in] Immutable string to be converted
//
//  Returns:
//      A value of -1 is returned if the input string fails validation (not a Roman Numeral)
//      or the proper Arabic representation of the Roman Numeral.
//
//  Remarks:
//     Regular expression matching is performed to ensue that the input string is entirely
//     comprised of Roman Numerals.
//
//----------------------------------------------------------------------------------------
//
int
ArabicConverter::ConvertToAarabic(std::string const& RomanNumerial)
{
    int Result = -1;

    if (std::regex_match(RomanNumerial,sRomanNum ))
    {
        std::string InputStr(RomanNumerial);
        Result = 0;


        for (std::size_t i = 0; i < sRomanLetters.size() && !InputStr.empty(); ++i)
        {

            if (i % 2 == 1)
            {
                std::string vMatchStr(InputStr.substr(0, 2));

                if (vMatchStr == sRomanLetters[i].first)
                {
                    Result += sRomanLetters[i].second;
                    InputStr.erase(0, 2);
                }
           }
           else
           {
                std::string Target = sRomanLetters[i].first;

                if (Target[0] == InputStr[0] &&
                        (Target == "M" || Target == "C" || Target == "X" || Target == "I") )
                {
                    Result += HandleSpecialRepeating( InputStr, Target[0] );

                }
                else
                {
                    std::string vMatchStr(InputStr.substr(0, 1));

                    if (vMatchStr == sRomanLetters[i].first)
                    {
                        Result += sRomanLetters[i].second;
                        InputStr.erase(0, 1);
                    }
                }

            }

        } //- For loop

    }

    return Result;
}

//----------------------------------------------------------------------------------------
//  Member Function:
//      BuildMap()
//
//  Summary:
//      Builds the standard map that houses the roman numerals used for the conversion.
//
//
//----------------------------------------------------------------------------------------
//
void
ArabicConverter::BuildMap()
{
    mMap.insert(std::make_pair(1000, "M"));
    mMap.insert(std::make_pair(900, "CM"));
    mMap.insert(std::make_pair(500, "D"));
    mMap.insert(std::make_pair(400, "CD"));
    mMap.insert(std::make_pair(100, "C"));
    mMap.insert(std::make_pair(90, "XC"));
    mMap.insert(std::make_pair(50, "L"));
    mMap.insert(std::make_pair(40, "XL"));
    mMap.insert(std::make_pair(10, "X"));
    mMap.insert(std::make_pair(9, "IX"));
    mMap.insert(std::make_pair(5, "V"));
    mMap.insert(std::make_pair(4, "IV"));
    mMap.insert(std::make_pair(1, "I"));
}


//----------------------------------------------------------------------------------------
//  Member Function:
//      HandleSpecialRepeating()
//
//  Summary:
//      Handles those special roman characters that are allowed to repeat.
//
//  Parameters:
//      vStr -
//          [in, out] mutable string to be converted, parsed characters are stripped
//      vRomanLetter -
//          [in] Roman Letter to be converted
//
//  Returns:
//      The sum of numeric representation of one or more the repeatable roman numerals
//
//----------------------------------------------------------------------------------------
//
unsigned int
ArabicConverter::HandleSpecialRepeating(std::string &vStr, char vRomanLetter)
{
    unsigned int Sum = 0;

    unsigned int Value = 0;
    std::sregex_iterator begin_itr;
    std::sregex_iterator end_itr;

    if (vRomanLetter == 'M')
    {
        begin_itr = std::sregex_iterator(vStr.begin(), vStr.end(), sThousands);
        Value = 1000;
    }
    else if (vRomanLetter == 'C')
    {
        begin_itr = std::sregex_iterator(vStr.begin(), vStr.end(), sHundreds);
        Value = 100;
    }
    else if (vRomanLetter == 'X')
    {
        begin_itr = std::sregex_iterator(vStr.begin(), vStr.end(), sTens);
        Value = 10;
    }
    else if (vRomanLetter == 'I')
    {
        begin_itr = std::sregex_iterator(vStr.begin(), vStr.end(), sOnes);
        Value = 1;
    }


    if (begin_itr != end_itr)
    {

        std::smatch vMatch = *begin_itr;
        std::string vMatchStr(vMatch.str());

        for (std::size_t i = 0; i < vMatchStr.size(); ++i)
        {
            Sum += Value;
            vStr.erase(0,1);
        }
    }

    return Sum;
}
