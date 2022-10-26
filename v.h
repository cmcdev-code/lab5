#pragma once

#include <string>//library to return string

using std::string;


class Vigenere{
    public:
    //function that will take in a string and return it encrypted using the password
    string encrypt(string word);

    //function that will take in an encrypted word and return the decrypted word
    string decrypt(string word);

    //constructor to set the key
    Vigenere(string k);
    //default consructor 
    Vigenere();

    //function to set the key
    void setKey(string k);
    
    //function that will make the key upper case 
    void upperCaseKey(string k);

    private:
        string key;
};
