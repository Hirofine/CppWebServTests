// std
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

// Wt
#include <Wt/WApplication.h>
#include <Wt/WStringUtil.h>

// local
#include "Dictionary.hpp"

std::wstring RandomWord(Dictionary dictionary){
    std::ifstream dict;
    if(dictionary == DICT_NL){
        dict.open((WApplication::appRoot() + "dict-nl.txt").c_str());
    } else{
        dict.open((WApplication::appRoot() + "dict.txt").c_str());
    }

    std::string retval;
    int numwords = 0;
    while(dict){
        getline(dict, retval);
        numwords++;
    }
    dict.clear();
    dict.seekg(0);

    srand(time(0));
    int selection = rand() % numwords;

    while(selection--){
        getline(dict, retval);
    }
    getline(dict, retval);
    for(unsigned int i = 0; i< retval.size(); i++){
        if(retval[i] < 'A' || retval[i] > 'Z'){
            std::cout << "word " << retval << " contains illegal data at pas " << i << std::endl;
        }
    }
    return widen(retval);
}