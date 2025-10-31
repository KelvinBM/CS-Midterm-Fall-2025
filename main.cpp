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
 *
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char decision;
    string key;
    vector<string> keys;
    string encryptedText;
    string strUniqueLetters;
    string decryptedTextLowered;
    string currWord;
    bool isDecrypted = false;

    vector<int> keyShiftLetters;
    vector<char> uniqueLetters;
    vector<char> lettersToDecryptOnly;
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


    // FILE WITH ENCRYPTED TEXT //
    string lineText;
    ifstream EncryptedTextFile("C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\Decrypt-Team-8.txt");// path to where my file is

    while (getline(EncryptedTextFile, lineText)) {
        encryptedText.append(lineText + " ");
        //cout << lineText << endl;
    }
    EncryptedTextFile.close();

    // key;
    // getline(cin, sentence);
    cout << endl;
    //encryptedText = "TMXE EMLR AIHT PVZG BUEM TWEA PKLT JGWZ ANLD HFMI MQRM VOWB KZZA MLAS RXYU NZPT HTRU AWAH TJOI IIED UOBA SNFO HYDJ KMKF OILR KHVD UTVH";// +
                // "NKHP CAWT UAQR WZEB NAIY AEJZ OIVW JKSW MNMP CNIE KUNZ HNDT RRXY MPCF EVVX AMPO SLSI FRNA HXBX JBRH CISV IZET HHSX BWKG SBUM FDME SAOH " +
                // "IQTF CQWA HTBX EIQA EYEF WCRO QNHI SMIU IIMO TMXE EMLR AIHT PVZG BUEB XEMQ STSG JUVR UCIH TYXV EEJN ZTFL XYQJ TJQZ TVUX OHTW JTZV EFEV " +
                // "WJKW RZDE LAAX W";

    for (i = 0; i < encryptedText.size(); i++) {
        if (isalpha(encryptedText.at(i))) {
            if (strUniqueLetters.find(encryptedText.at(i)) == string::npos) {
                uniqueLetters.push_back(encryptedText.at(i));
                strUniqueLetters.push_back(encryptedText.at(i));
            }
        }
        if (isalpha(encryptedText.at(i)) || encryptedText.at(i) == '\n') {
            lettersToDecryptOnly.push_back(encryptedText.at(i));
        }
    }

    for (i = 0, j = 'A'; j <= 'Z'; i++, j++) {
        alphabet.push_back(j);
        alphabetCorrespondingShift.push_back(i);

        // cout << alphabet.at(i) << "  " << alphabetCorrespondingShift.at(i);
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
        currRate = currLetterCounter; /// (double)sentence.length();
        letterRate.push_back(currRate);

        cout << "  " << currLetter << ": " << letterRate.at(i) << endl;
    }
    cout << endl;


    //////////////////////////////////////////////////////////////////////////////////////////
    ///                                     DECRPYTING                                     ///
    //////////////////////////////////////////////////////////////////////////////////////////

    cout << "Would you like to input the key or read multiple keys from a text file?" << endl;
    cout << "Enter [I] to input key or [R] to read keys: ";
    cin >>decision;

    if (islower(decision)) {
        decision = toupper(decision);
    }

    if (decision == 'R') {
        ifstream keysFile("C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\keys.txt");// path to where my file is

        // getting the keys to try out //
        while (getline(keysFile, lineText))
        {
            // cout << lineText << '\n';
            keys.push_back(lineText);
        }
        keysFile.close();
        cout << endl << endl << keys.size() << endl << endl;

        for (k = 0; k < keys.size(); k++) {
            key = keys.at(k);

            keyShiftLetters.resize(key.size());
            for (i = 0; i < key.size(); i++) {
                if (islower(key.at(i))) {
                    keyShiftLetters.at(i) = (toupper(key.at(i)));
                } else {
                    keyShiftLetters.at(i) = key.at(i);
                }
                cout << (char)keyShiftLetters.at(i) << " ";
            }
            cout << endl;
            cout << "Current Key:  " << key << endl;
            // WORK ON DECRYPTING //
            for (i = 0; i < lettersToDecryptOnly.size(); i++) {
                currLetter = lettersToDecryptOnly.at(i);
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
                cout << (char)keyShiftLetters.at(i) << " ";
            }
            cout << endl;
            cout << "Current Key:  " << key << endl;
            // WORK ON DECRYPTING //
            for (i = 0; i < lettersToDecryptOnly.size(); i++) {
                currLetter = lettersToDecryptOnly.at(i);
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
            //cout << endl << endl;
            cout << "Enter key:";
            cin >> key;
        }
    }

    return 0;
}