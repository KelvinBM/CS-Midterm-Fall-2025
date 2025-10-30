/*
 *  Resorted to:
 *      - Week 7's resource replit file for encrypting using Ceaser's cypher
 *      - c++ file I made that includes notes from Zybooks(eg. methods and data types)
 *      - Video on polyalphabetic cypher: https://www.youtube.com/watch?v=BgFJD7oCmDE&list=PLSQl0a2vh4HA50QhFIirlEZRXG4yjcoGM&index=7
 *      - w3schools page for instructions on gathering content from text files: https://www.w3schools.com/cpp/cpp_files.asp
 *      - I searched "c++ file not found when trying to read text file" to figure out why the text file wasn't
 *        being read and AI told me to use the absolute path to the file
 *          - From another search result, one tying to a stackOverflow thread I got the logic for veryfying if
 *            the given 'keys.txt' file was opened or not(NEED TO IMPLEMENT): https://stackoverflow.com/questions/30221785/reading-from-text-file-is-not-working-c
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
    string newSentence;
    string decryptedText;
    string decryptedTextLowered;
    bool isDecrypted = false;

    vector<int> keyShifts;
    vector<char> letters;
    vector<int> letterRate;

    char currLetter;
    int currLetterCounter;
    int currRate;

    char shiftedLetter;
    int keyToShiftBy;

    int i;
    int j;
    int k;

    // key;
    // getline(cin, sentence);
    cout << endl;
    encryptedText = "TMXE EMLR AIHT PVZG BUEM TWEA PKLT JGWZ ANLD HFMI MQRM VOWB KZZA MLAS RXYU NZPT HTRU AWAH TJOI IIED UOBA SNFO HYDJ KMKF OILR KHVD UTVH";// +
                // "NKHP CAWT UAQR WZEB NAIY AEJZ OIVW JKSW MNMP CNIE KUNZ HNDT RRXY MPCF EVVX AMPO SLSI FRNA HXBX JBRH CISV IZET HHSX BWKG SBUM FDME SAOH " +
                // "IQTF CQWA HTBX EIQA EYEF WCRO QNHI SMIU IIMO TMXE EMLR AIHT PVZG BUEB XEMQ STSG JUVR UCIH TYXV EEJN ZTFL XYQJ TJQZ TVUX OHTW JTZV EFEV " +
                // "WJKW RZDE LAAX W";

    for (i = 0; i < encryptedText.size(); i++) {
        if (isalpha(encryptedText[i])) {
            if (newSentence.find(encryptedText.at(i)) == string::npos) {
                newSentence.push_back(encryptedText.at(i));
                letters.push_back(encryptedText.at(i));
            }
        }
    }

    // letter comparisons
    // DECRYPTING //
    cout << "Letter Rates:" << endl;
    for (i = 0; i < letters.size(); i++) {
        currLetter = letters.at(i);
        currLetterCounter = 0;

        for (j = 0; j < encryptedText.size(); j++) {
            if (currLetter == encryptedText.at(j)) {
                currLetterCounter++;
            }
        }
        currRate = currLetterCounter; /// (double)sentence.length();
        if (newSentence.find(letters.at(i)) == string::npos) {
            letterRate.push_back(currRate);
        }

        cout << "  " << currLetter << ": " << currRate << endl;
    }
    cout << endl;

    cout << "Would you like to input the key or read multiple keys from a text file?" << endl;
    cout << "Enter [I] to input key or [R] to read keys: ";
    cin >>decision;

    if (islower(decision)) {
        decision = toupper(decision);
    } else {
        if (decision == 'R') {
            string lineText;
            ifstream keysFile("C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\keys.txt");

            while (getline(keysFile, lineText))
            {
                // cout << lineText << '\n';
                keys.push_back(lineText);
            }
            keysFile.close();

            for (k = 0; k < keys.size(); k++) {
                key = keys.at(k);

                keyShifts.resize(key.size());
                for (i = 0; i < key.size(); i++) {
                    if (islower(key.at(i))) {
                        keyShifts.at(i) = (toupper(key.at(i)));
                    } else {
                        keyShifts.push_back(key.at(i));
                    }
                    //cout << keyShifts.at(i) << " ";
                }
                cout << endl;

                // WORK ON DECRYPTING //
                decryptedText = "";
                for (i = 0; i < newSentence.size(); i++) {
                    currLetter = newSentence.at(i);
                    if (!isalpha(currLetter)) {
                        continue;
                    }
                    keyToShiftBy = keyShifts.at(i % key.size());

                    if (isalpha(currLetter)) {
                        shiftedLetter = (((newSentence.at(i) - 'A') + keyToShiftBy) % 26) + 'A';
                        cout << shiftedLetter;
                    } else {
                        cout << currLetter;
                    }
                    //cout << keyToShiftByIndex << endl;
                }
                cout << endl << endl;
            }
        } else if (decision == 'I') {
            cout << "Enter key or enter 'E' to END program: ";
            cin >> key;

            while (key != "E") {
                keyShifts.resize(key.size());
                for (i = 0; i < key.size(); i++) {
                    if (islower(key.at(i))) {
                        keyShifts.at(i) = (toupper(key.at(i)));
                    } else {
                        keyShifts.push_back(key.at(i));
                    }
                    //cout << keyShifts.at(i) << " ";
                }
                cout << endl;

                // WORK ON DECRYPTING //
                decryptedText = "";
                for (i = 0; i < newSentence.size(); i++) {
                    currLetter = newSentence.at(i);
                    if (!isalpha(currLetter)) {
                        continue;
                    }
                    keyToShiftBy = keyShifts.at(i % key.size());

                    if (isalpha(currLetter)) {
                        shiftedLetter = (((newSentence.at(i) - 'A') + keyToShiftBy) % 26) + 'A';
                        cout << shiftedLetter;
                    } else {
                        cout << currLetter;
                    }
                    //cout << keyToShiftByIndex << endl;
                }
                cout << endl << endl;
                cout << "Enter key:";
                cin >> key;
            }
        }
    }

    return 0;
}