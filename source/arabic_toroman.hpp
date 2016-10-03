//========================================================================================
//  File Name:
//      arabic_toroman.hpp
//
//
//  Authors:
//      Ian Heaton
//
//========================================================================================
//
#ifndef ARABIC_TOROMAN_HPP_DEFINED
#define ARABIC_TOROMAN_HPP_DEFINED

#include <string>
#include <map>

//--------------------------------------------------------------------------------------------------
//  Class:
//      ArabicConverter
//
//  Summary:
//      Converts Arabic numbers to their Roman Numeral equivalent.
//
//
//  Remarks:
//      Also converts a set of Roman Numerals to the proper Arabic numbers.
//
//--------------------------------------------------------------------------------------------------
//
class ArabicConverter
{
public:
    ArabicConverter();

    std::string ConvertToRoman(unsigned int Value);
    int ConvertToAarabic(std::string const& RomanNumerial);


    ArabicConverter(ArabicConverter const& vSrc) = delete;
    ArabicConverter& operator= (ArabicConverter const& vRhs) = delete;

private:
    using ConversionMap = std::map<unsigned int, std::string>;
    ConversionMap mMap;

    void BuildMap();
    unsigned int HandleSpecialRepeating(std::string& vStr, char vRomanLetter);

};

#endif // ARABIC_TOROMAN_HPP_DEFINED
