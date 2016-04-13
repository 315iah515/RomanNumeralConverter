//========================================================================================
//  File Name:
//      arabic_toroman.hpp
//
//  Product:
//
//
//  Interface Header:
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

class ArabicConverter
{
public:
    ArabicConverter();

    std::string ConvertToRoman(unsigned int Value);
    unsigned int ConvertToAarabic(std::string const& RomanNumerial);


    ArabicConverter(ArabicConverter const& vSrc) = delete;
    ArabicConverter& operator= (ArabicConverter const& vRhs) = delete;

private:
    using ConversionMap = std::map<unsigned int, std::string>;
    ConversionMap mMap;

    void BuildMap();
    unsigned int HandleSpecialRepeating(std::string& vStr, char vRomanLetter);




};

#endif // ARABIC_TOROMAN_HPP_DEFINED
