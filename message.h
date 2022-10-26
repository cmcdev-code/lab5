#pragma once
#include <iostream>//library for output 
#include <vector>//library for the vector 
#include "v.h"//header file for the Vigenere class 
#include <fstream>//library to create file objects 

using std::string;

class message{
    
    public:

    //function that will encrypt the word and use the vector pushback to store it in the vector 
    void encryptWord(string word);
    //function that will decrypt the word and use the vector pushback to store it in the vector 
    void decryptWord(string word);

    //one argument constructor  
    message(string k);
    //zero argument constructor 
    message();

    
    

    //function that will return the word at a specific index in the vector 
    string getWordAtIndex(int index) const;
    //function that will take in a string and will use the vector.pushback()
    void vecWordsPushBack(string word);

    //clears the vector             
    void clearVecOfWords();

    //will return the length of the vector 
    int getLengthVector() const;//done

    //function that will output to the terminal 
    void showWords() const;

    //function that will output the the file that is passed in and will print what it is outputting to the terminal 
    void showWords(std::ofstream& out) const;


    private:
        Vigenere v;//creating obj instance 
        std::vector<string> vecWords;//done 
};
