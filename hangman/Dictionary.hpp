#ifndef DICTIONARY_H_
#define DICTIONARY_H_

// std
#include <string>

#include <Wt/WAny.h>

using namespace Wt;

enum Dictionary{
    DICT_EN = 0,
    DICT_NL = 1
};

extern std::wstring RandomWord(Dictionary dictionary);

#endif //DICTIONARY_H_