#include "v.h"
#include <cctype>
#include <algorithm>

//function to set the key 
void Vigenere::setKey(string k){
    //found this here https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    std::transform(k.begin(),k.end(),k.begin(), ::toupper);
    //this above works by getting the pointer to the begining of the string and the end and checks that they are not ==
    //if they are then it will end if they are not == then it incrimant by one and apply the "toupper()" to that char 
    //the third paramater is using the same pointer and will change the value of that string at that location 
    key=k;

}
Vigenere::Vigenere(){
    key="ABC";
}
//default constructfor 
Vigenere::Vigenere(string k){
    setKey(k);
}



//function that will encrypt the word
string Vigenere::encrypt(string word)
{
    string output;
        for (int i = 0, j = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
            j = (j + 1) % key.length();
            }
return output;
}
//function to decyrpt the word 
string Vigenere::decrypt(string word)
{
string output;
    for (int i = 0, j = 0; i < word.length(); ++i) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
    continue;
        output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
    j = (j + 1) % key.length();
    }
return output;
}
