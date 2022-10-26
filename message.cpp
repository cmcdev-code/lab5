#include "message.h"//header file 
#include <iostream>//io 

using std::cout;
using std::string;

//constructor that will set the key in the v class
message::message(string k){
    v.setKey(k);
}
//default constructor 
message::message(){

   v.setKey("ABC");
    cout<<"The key is \"ABC\"\n";
}

//will take in string and use the pushback
void message::vecWordsPushBack(string word){
    vecWords.push_back(word);
}
//will return the word at a specific index
std::string message::getWordAtIndex(int index) const{
    string loclStr;
    if(vecWords.size()>=index) loclStr = vecWords.at(index);
    else loclStr="out of bounds";
    return loclStr;
}
//clears the vector 
void message::clearVecOfWords(){
    vecWords.clear();
}

//will take in word and then use the v.encrypt and then use the vec pushback 
void message::encryptWord(string word){
    vecWordsPushBack(v.encrypt(word));
}
//will take in word and then use the v.decrypt and then use the vec pushback
void message::decryptWord(string word){
    vecWordsPushBack(v.decrypt(word));
}
//will return the size of the vectror 
int message::getLengthVector() const{
    return vecWords.size();
}
//will output all the words to the terminal 
void message::showWords() const{
    for(int i=0;i<getLengthVector();i++){
        cout<<getWordAtIndex(i)<<' ';
    }
}
//will write the the file 
void message::showWords(std::ofstream& out) const{
showWords();
cout<<"\n";
for(int i=0;i<getLengthVector();i++){
        out<<getWordAtIndex(i)<<' ';
    }
}
