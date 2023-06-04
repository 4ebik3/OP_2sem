#include <iostream>
#include "funtion.h"
#include <vector>

int main(){
std::vector<int> a;
a.push_back(-1);
a.push_back(0);
a.push_back(1);
a.push_back(2);
std::string myString = "12321";
std::cout << "allof: " <<  allof<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateBelowZero) << '\n';
std::cout << "anyof: "<< anyof<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateAboveZero) << '\n';
std::cout << "noneof: " << noneof<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateZero) << '\n';
std::cout << "oneof: " << oneof<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateBelowZero) << '\n';
std::cout << "issorted: "<< issorted<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateSorted) << '\n';
std::cout << "ispartitioned: "<< ispartitioned<std::vector<int>::iterator, int>(a.begin(), a.end(), predicateIsPartitioned) << '\n';
std::cout << "findnot: " << findnot<std::vector<int>::iterator, int>(a.begin(), a.end(), 2,predicateFindNot) << '\n';
std::cout << "findbackward: " << findbackward<std::vector<int>::iterator, int>(a.begin(), a.end(), 2,predicateFindBackward) << '\n';
std::cout << "ispalindrome: " << ispalindrom<std::string::iterator , int>(myString.begin(), myString.end(), predicateIsPalindrome) << '\n';

return 0;
}