#include "message.h"
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

//function that will get the input from the file and store it in the char array
void fInput(ifstream& in, char a[]);

//function that will ask for the name of the file and then will get the input from the file and encrypt it 
void uncryptedFile_encryptedFile(message& localObj, char a[]);

//function that will ask for the name of the encrypted file and then will preformm the encryption and ask for the storage of the file 
void encryptedFile_uncryptedFile_(message& localObj, char a[]);

//function that has the menu 
void menu();

//function that will ask for the menu choice and will error check it 
int menuChoice();

//function that will ask for the password 
string password();

//will ask for the name of the file and error check opening it if it can open it then it will write to it s
void outOf_file(message& localObj);

//will take in a string and return it uppercased 
string upper(string);

//will take in the char array and will tokinize it and encrypt it 
void encryptFromFile(message& localObj, char a[]);
//will take in the char array and will tokinize it and decrpyt it 
void decryptFromFile(message& localObj, char a[]);

int main(void) {

    cout << "Collin McDevitt Lab 5 \n";
    char char_array[1000];

    menu();

    string key = password();//asking for the password

    message Object(key);
    while (true) {
        int i = -1;
        Object.clearVecOfWords();
        menu();
        i = menuChoice();
        if (i == 1) {
            uncryptedFile_encryptedFile(Object, char_array);

        }
        else if (i == 2) {
            encryptedFile_uncryptedFile_(Object, char_array);

        }
        else break;
    }
}

void fInput(ifstream& in, char a[]) {

    string localStr = "";
    string localStr2 = "";
    while (!in.eof()) {
        getline(in, localStr2);
        localStr = localStr + localStr2;
    }
    for (int i = 0; i < localStr.length(); i++) {
        a[i] = localStr[i];
    }
}

void uncryptedFile_encryptedFile(message& localObj, char a[]) {
    cout << "What is the name of the file that you would like to encrypt?\n";
    string input = "";
    cin.ignore();

    getline(cin, input);

    ifstream in;
    in.open(input);
    if (in.is_open()) {
        fInput(in, a);
        encryptFromFile(localObj, a);
        outOf_file(localObj);
    }
    else {
        cout << "Error in opening file \n";
    }
    in.close();
}

void encryptedFile_uncryptedFile_(message& localObj, char a[]) {
    cout << "What is the name of the file that you would like to decrypt?\n";
    string input = "";
    cin.ignore();
    getline(cin, input);

    ifstream in;
    in.open(input);
    if (in.is_open()) {
        fInput(in, a);
        decryptFromFile(localObj, a);
        outOf_file(localObj);
    }
    else {
        cout << "Error in opening file \n";
    }

    in.close();
}

void menu() {
    cout << "    Vigener Cyper\n\n       Main Menu\n\n    1 - Encrypt File\n    2 - Decrypt File\n    3 - Quit\n";
}

int menuChoice() {//will ask for what choice they want and then error check and return it 
    int x = 0;//local variable to store what they  enter 

    while (true) {
        cout << "Please select your menu choice :\n";
        cin >> x;//asks for user input
        if ((x > 0) && (x < 4) && !(cin.fail())) {//checks wheather they stream is in a fial state and that the number the user entered is correct 
            break;//breaks out of loop 
        }
        else {//will clear stream and let the user know that they entered a wrong number 
            cout << "Error please select from one the options: Enter an int from 1-3 \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return x;//returns the value 
}

string password() {

    string localStr = "";

    cout << "What do you want your password to be? Only enter all caps and only letters\n";
    while (true) {
        getline(cin, localStr);
        localStr = upper(localStr);
        //variables to find the highest value and lowest value of the char as a int value 
        int min = localStr[0];
        int stepMin = localStr[0];

        int max = localStr[0];
        int stepMax = localStr[0];

        for (int i = 0; i < localStr.length(); i++) {//finds max and min char values 
            if (min > stepMin) {
                min = stepMin;
                stepMin = localStr[i];
            }

            if (max < stepMax) {
                max = stepMax;
                stepMax = localStr[i];
            }

        }if (max <= 90 && min >= 65) {//if the max or min is greater or less then the numbers there respectivly then it will not be char in the range 
            break;
        }
        else
        {
            cout << "Please only enter letters. \n";
        }
    }

    cout << "Your password is " + localStr + '\n';
    return localStr;

}
//function to write to the file
void outOf_file(message& localObj) {
    cout << "What is the name of the file that you would like to store the message in?\n";
    string localStr = "";
    getline(cin, localStr);

    ofstream out;
    out.open(localStr);
    if (out.is_open()) {//checks that the file is open
        localObj.showWords(out);//if the file is open it will output to the file 
    }
    else {
        cout << "Error opening file. \n";
        out.clear();
    }
    out.close();
}


//function to turn the string to all upper case 
string upper(string str) {

    //found this here https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    //this above works by getting the pointer to the begining of the string and the end and checks that they are not ==
    //if they are then it will end if they are != then it incrimant by one and apply the "toupper()" to that char 
    //the third paramater is using the same pointer and will change the value of that string at that location 
    return str;
}

//Function to tokenize the items in the char array and encrypt it and store it in the vector
void encryptFromFile(message& localObj, char a[]) {
    char seps[] = " .,\t\n\r";//separaters
    char* token1 = NULL;
    char* next_token1 = NULL;

    token1 = strtok_s(a, seps, &next_token1);
    while (token1 != NULL) {
        localObj.encryptWord(upper(token1));
        token1 = strtok_s(NULL, seps, &next_token1);
    }

}

//Function to tokenize the items in the char array and decrypt it and store it in the vector
void decryptFromFile(message& localObj, char a[]) {
    char seps[] = " .,\t\n\r";
    char* token1 = NULL;
    char* next_token1 = NULL;
    token1 = strtok_s(a, seps, &next_token1);
    while (token1 != NULL) {
        localObj.decryptWord(token1);
        token1 = strtok_s(NULL, seps, &next_token1);
    }
}
