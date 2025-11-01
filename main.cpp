/*
 *  Resorted to:
 *      - Week 7's resource replit file for encrypting using Ceaser's cypher
 *      - c++ file I made that includes notes from Zybooks(e.g. methods and data types)
 *      - Video on polyalphabetic cypher: https://www.youtube.com/watch?v=BgFJD7oCmDE&list=PLSQl0a2vh4HA50QhFIirlEZRXG4yjcoGM&index=7
 *      - w3schools page for instructions on gathering content from text files: https://www.w3schools.com/cpp/cpp_files.asp
 *      - I searched "c++ file not found when trying to read text file" to figure out why the text file wasn't
 *        being read and AI told me to use the absolute path to the file
 *          - From another search result, one tying to a stackOverflow thread I got the logic for veryfying if
 *            the given 'keys.txt' file was opened or not(NEED TO IMPLEMENT): https://stackoverflow.com/questions/30221785/reading-from-text-file-is-not-working-c
 *
 *      - This video helped me further understand the mathematics behind the Vigenere Cypher: https://www.youtube.com/watch?v=RCkGauRMs2A
 *      - This video helped me understand that the alphabet's letters will not be directly used to shift rather than
 *        their corresponding value: https://www.youtube.com/watch?v=T3r-3twsG8s
 *          - Ex: A -> 0 | B -> 1 (a maps to zero; b maps to 1; and so on...)
 *
 *      - This website that decrypts vigenere ciphered text so that I can figure out what it should look like at least so that I can
 *        try and figure out what is wrong with my program's logic: https://www.boxentriq.com/code-breaking/vigenere-cipher
 *
 *      - This site to get real english words to compare with the decrypted text
 *      - This stackOverflow thread helps use the sleep() function: https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include<cctype>


using namespace std;

int main() {
    int decisionOfProgram;
    bool isChoice = false;

    while (!isChoice) {
        cout << "What would you like to do today:" << endl;
        cout << "\tEnter [1] to Encrypt" << endl;
        cout << "\tEnter [2] to Decrypt provided plaintext" << endl;

        cout << endl << "Your Choice: ";
        cin >> decisionOfProgram;

        if (decisionOfProgram == 1 || decisionOfProgram == 2) {
            isChoice = true;
        } else {
            cout << "* Please enter a valid choice." << endl;
        }
    }

    cout << endl;

    if (decisionOfProgram == 1) {
        /*1.2 mode for de or en
        * 2.creater vector to store content of encryption
        * 3.only for letter if is not letter, no change
        * 4.randkey create based on length of plaintext also only for letter, it could exactly match we don't even need to use loop to perform key multiple times * 5.key point is convert everything in uppercase letter even key and char enchar *6.using multiple way to encryption
        */
        int choice;
        bool isDecision;

        while (!isDecision) {
            cout << "If you want to perform Encryption type [1] and if you want to perform Decryption type [2]:";
            cin >> choice;
            cin.ignore(); //learn this from zybook just in order to aviod get " " when I use getline next

            if (choice == 1 || choice == 2) {
                isDecision = true;
            } else {
                cout << "* Please enter a valid choice." << endl;
            }
        }

        vector<string> keytext;
        vector<char> ciphertext;
        vector<int> letterfre(26, 0);
        if (choice == 1) {
            string plaintext;
            string randkey = "";
            char k, c;
            int userseed;
            cout << "Please enter the content you want to perform Encryption on:" << endl;
            getline(cin, plaintext);
            cout << "Please enter the seed you want to use:";
            cin >> userseed;
            srand(time(0) + userseed);
            int textlength = plaintext.size();
            vector<char> encrytiontext;
            for (int i = 0; i < textlength; i++) {
                if (isalpha(plaintext[i])) {
                    //only get the key for letter
                    k = ((textlength * 8 + (rand() % 26) * i * i)) % 26 + 'A';
                    randkey += k;
                }
            }
            cout << "key is " << randkey << endl;
            int keyindex = 0;
            for (int i = 0; i < textlength; i++) {
                if (isalpha(plaintext[i])) {
                    //only encrypto for letter
                    if (isupper(plaintext[i])) {
                        char enchar = ((plaintext[i] - 'A') + (randkey[keyindex] - 'A')) % 26 + 'A';
                        //if the plaintext is not letter we could preserve it self
                        encrytiontext.push_back(enchar);
                        keyindex++;
                    } else {
                        char enchar = ((plaintext[i] - 'a') + (randkey[keyindex] -
                                                               'A')) % 26 + 'a';
                        //if the plaintext is not letter we could preserve it self
                        encrytiontext.push_back(enchar);
                        keyindex++;
                    }
                } else {
                    encrytiontext.push_back(plaintext[i]);
                }
            }
            int n = userseed % encrytiontext.size();
            if (n == 0) {
                n = 1;
            }
            int N = encrytiontext.size();
            char temp1 = encrytiontext.at(n);
            //store the value to decryption just in case

            char temp2 = encrytiontext.at(n - 1);
            encrytiontext.at(n) = '@'; //we would like use symbol to make it more complexand hard to decryption
            if (encrytiontext.size() >= 2) {
                encrytiontext.at(n - 1) = '*';
            }
            for (int i = 0; i < N / 2; i++) {
                //reverse the sequence to make it more complex
                int temp3 = encrytiontext.at(i);
                encrytiontext.at(i) = encrytiontext.at(N - i - 1);
                encrytiontext.at(N - 1 - i) = temp3;
            }
            cout << "Encryption content would be : ";
            for (int i = 0; i < textlength; i++) {
                cout << encrytiontext.at(i);
            }
            cout << endl;
            cout << "Do you want to get the original text? If you want to input [1] and provided key, else input [2]:";
            int choice2;
            string key;
            cin >> choice2;
            if (choice2 == 1) {
                cout << "please tell me the key " << endl;
                cin >> key;
                int keyindex = 0;
                if (key == randkey) {
                    vector<char> deencrytiontext;
                    for (size_t i = 0; i < encrytiontext.size(); i++) {
                        deencrytiontext.push_back(encrytiontext.at(i));
                    }
                    int P = deencrytiontext.size();
                    for (size_t i = 0; i < P / 2; i++) {
                        //reverse the sequence to make it more complex
                        int temp4 = deencrytiontext.at(i);
                        deencrytiontext.at(i) = deencrytiontext.at(P - i - 1);
                        deencrytiontext.at(P - 1 - i) = temp4;
                    }
                    for (size_t i = 0; i < deencrytiontext.size(); i++) {
                        if (deencrytiontext.at(i) == '@') {
                            deencrytiontext.at(i) = temp1;
                        }
                        if (deencrytiontext.at(i) ==
                            '*' && deencrytiontext.size() > 0) {
                            deencrytiontext.at(n - 1) = temp2;
                        }
                    }
                    for (size_t i = 0; i < deencrytiontext.size(); i++) {
                        if (isalpha(deencrytiontext[i])) {
                            if (isupper(deencrytiontext[i])) {
                                //direct substitute them get the answer back
                                deencrytiontext[i] = ((deencrytiontext[i] - 'A') - (randkey[keyindex] - 'A') + 26) % 26 + 'A';
                                keyindex++;
                            } else {
                                deencrytiontext[i] = ((deencrytiontext[i] - 'a') - (randkey[keyindex] - 'A') + 26) % 26 + 'a';
                                keyindex++;
                            }
                        }
                    }
                    cout << "Decrypted text: ";
                    for (size_t i = 0; i < deencrytiontext.size(); i++) {
                        cout << deencrytiontext.at(i);
                    }
                } else {
                    cout << "It's not right key dude, you are not THE Bob" << endl;
                }
            }
            return 0;
        }
    } else if (decisionOfProgram == 2) {
        char decision;
        string key;
        vector<string> keys;
        string encryptedText;
        string strUniqueLetters;
        string currWord;

        vector<int> keyShiftLetters;
        vector<char> uniqueLetters;
        vector<char> lettersToDecrypt;
        vector<int> letterRate;
        vector<string> wordsOfEncryptedText;

        char currLetter;
        int currLetterCounter;
        int currRate;

        char shiftedLetter;
        char keyLetterToShiftBy;
        int keyLetterCorrespondingShift;
        int keyLetterAssignedNum;
        int currLetterAssignedNum;
        int indexOfShiftedLetter;

        int i;
        int j;
        int k;

        string alphabet;
        vector<int> alphabetCorrespondingShift;

        vector<string> realEnglishWords;
        vector<int> gradesOfEachKey;
        int gradeCount;
        int highestGrade;
        int highestGradeIndex;


        // FILE WITH ENCRYPTED TEXT //
        string lineText;
        ifstream EncryptedTextFile(
            "C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\Decrypt-Team-8.txt");
        // path to my file with encrypted text
        while (getline(EncryptedTextFile, lineText)) {
            encryptedText.append(lineText + " ");
            //cout << lineText << endl; // for testing
        }
        EncryptedTextFile.close();


        // ENGLISH WORDS //
        ifstream RealEnglishWordsFile(
            "C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\EnglishWords.txt");
        // path to english words text file
        while (getline(RealEnglishWordsFile, lineText)) {
            for (i = 0; i < lineText.length(); i++) {
                lineText[i] = toupper(lineText[i]);
            }
            realEnglishWords.push_back(lineText);
            //cout << lineText << endl; // for testing
        }
        RealEnglishWordsFile.close();
        // cout << endl;


        for (i = 0; i < encryptedText.size(); i++) {
            if (isalpha(encryptedText.at(i))) {
                if (strUniqueLetters.find(encryptedText.at(i)) == string::npos) {
                    uniqueLetters.push_back(encryptedText.at(i));
                    strUniqueLetters.push_back(encryptedText.at(i));
                }
                lettersToDecrypt.push_back(encryptedText.at(i));
            }
        }

        for (i = 0, j = 'A'; j <= 'Z'; i++, j++) {
            alphabet.push_back(j);
            alphabetCorrespondingShift.push_back(i);
            // cout << alphabet.at(i) << "  " << alphabetCorrespondingShift.at(i); // for testing
            // cout << endl;
        }

        // letter comparisons
        // DECRYPTING //
        cout << "Letter Rates:" << endl;
        for (i = 0; i < uniqueLetters.size(); i++) {
            currLetter = uniqueLetters.at(i);
            currLetterCounter = 0;

            for (j = 0; j < encryptedText.size(); j++) {
                if (currLetter == encryptedText.at(j)) {
                    currLetterCounter++;
                }
            }
            currRate = currLetterCounter; /// (double)sentence.length(); // for testing
            letterRate.push_back(currRate);

            cout << "  " << currLetter << ": " << letterRate.at(i) << endl;
        }
        cout << endl;

        //////////////////////////////////////////////////////////////////////////////////////////
        ///                                     DECRPYTING                                     ///
        //////////////////////////////////////////////////////////////////////////////////////////

        isChoice = false;
        while (!isChoice) {
            cout << "Would you like to input the key or read multiple keys from a text file?" << endl;
            cout << "Enter [I] to input key or [R] to read keys: ";
            cin >> decision;

            if (islower(decision)) {
                decision = toupper(decision);
            }

            if (decision == 'I' || decision == 'R') {
                isChoice = true;
            } else {
                cout << "* Please enter a valid choice." << endl;
            }
        }

        if (decision == 'R') {
            ifstream keysFile(
                "C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\keys.txt");
            // path to where my file is
            while (getline(keysFile, lineText)) {
                keys.push_back(lineText);
            }
            keysFile.close();


            for (k = 0; k < keys.size(); k++) {
                string decryptedText = ""; // reset decrypted text every iteration
                key = keys.at(k); // get currently selected key

                keyShiftLetters.resize(key.size());
                for (i = 0; i < key.size(); i++) {
                    if (islower(key.at(i))) {
                        keyShiftLetters.at(i) = (toupper(key.at(i)));
                    } else {
                        keyShiftLetters.at(i) = key.at(i);
                    }
                }
                //cout << endl << "Current Key:  " << key << endl;// for testing

                // WORK ON DECRYPTING //
                for (i = 0; i < lettersToDecrypt.size(); i++) {
                    // works
                    currLetter = lettersToDecrypt.at(i); // get letter to decrypt
                    currLetterAssignedNum = alphabet.find(currLetter); //

                    keyLetterToShiftBy = keyShiftLetters.at(i % key.size());
                    keyLetterAssignedNum = alphabet.find(toupper(keyLetterToShiftBy));

                    keyLetterCorrespondingShift = alphabetCorrespondingShift.at(keyLetterAssignedNum);
                    //cout << "" << indexOfKeyLetter << ", "; // for testing

                    shiftedLetter = ((currLetter - keyLetterCorrespondingShift + 'A') % 26) + 'A';
                    //cout << shiftedLetter;
                    decryptedText.push_back(shiftedLetter);
                    //cout << keyLetterAssignedNum; // for testing
                }
                // cout << endl << endl; // separates decrypted text of each key attempted and is used with for loop above

                gradeCount = 0;
                for (i = 0; i < realEnglishWords.size(); i++) {
                    if (decryptedText.find(realEnglishWords.at(i)) != string::npos) {
                        gradeCount++;
                        // cout << gradeCount << ", ";
                    }
                }
                //cout << endl << endl;// used to display gradeCount as it inceases and sections out depending on keyword
                gradesOfEachKey.push_back(gradeCount);
            }

            highestGrade = 0;
            for (i = 0; i < gradesOfEachKey.size(); i++) {
                //cout << "Grade Of Key: " << keys.at(i) << ", " << gradesOfEachKey.at(i) << endl << endl; // for testing
                if (gradesOfEachKey.at(i) > highestGrade) {
                    highestGrade = gradesOfEachKey.at(i);
                    highestGradeIndex = i;
                }
            }

            if (highestGradeIndex > 0) {
                cout << "Key Found: " << keys.at(highestGradeIndex) << endl;
            } else {
                cout << "Key Not Found" << endl;
            }
        } else if (decision == 'I') {
            cout << "Enter key or enter 'E' to END program: ";
            cin >> key;

            while (key != "E") {
                keyShiftLetters.resize(key.size());
                for (i = 0; i < key.size(); i++) {
                    if (islower(key.at(i))) {
                        keyShiftLetters.at(i) = (toupper(key.at(i)));
                    } else {
                        keyShiftLetters.at(i) = key.at(i);
                    }
                    //cout << (char)keyShiftLetters.at(i) << " ";
                }
                //cout << endl;
                //cout << "Current Key:  " << key << endl;
                // WORK ON DECRYPTING //
                for (i = 0; i < encryptedText.size(); i++) {
                    currLetter = encryptedText.at(i);
                    currLetterAssignedNum = alphabet.find(currLetter);

                    keyLetterToShiftBy = keyShiftLetters.at(i % key.size());
                    keyLetterAssignedNum = alphabet.find(keyLetterToShiftBy);

                    keyLetterCorrespondingShift = alphabetCorrespondingShift.at(keyLetterAssignedNum);
                    //cout << "" << indexOfKeyLetter << ", ";

                    shiftedLetter = (((currLetter - keyLetterCorrespondingShift) + 'A') % 26) + 'A';
                    cout << shiftedLetter;
                    //cout << keyLetterAssignedNum << endl;
                }
                cout << endl << endl;
                cout << "Enter key:";
                cin >> key;
            }
        }
    }


    return 0;
}
