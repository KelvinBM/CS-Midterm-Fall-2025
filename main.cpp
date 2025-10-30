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
 *
 *      - This video helped me further understand the mathematics behind the Vigenere Cypher: https://www.youtube.com/watch?v=RCkGauRMs2A
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char decision;

    string key;
    string encryptedText;

    vector<char> uniqueLetters;
    vector<char> encryptedTextLetters;
    string strUniqueLetters;
    string currWord;

    vector<int> keyShifts;
    vector<int> letterRate;
    vector<int> freqDistrOfIntervals;
    vector<string> wordsOfEncryptedText;

    char currLetter;
    int currLetterCounter;
    int currRate;
    int currFrequency;
    int currFreqDistr;// subtract from text as if key//  ciphertext.at(i) = ((plaintext.at(i) - 'A') - currFreqDistr) % 26 + 'A';


    int i;
    int j;
    int k;

    // FILE WITH ENCRYPTED TEXT //
    string lineText;
    ifstream EncryptedTextFile("C:\\Users\\Kelvi\\Desktop\\CCNY\\CSC 103 - Computer Science\\Projects\\Cryptography\\text\\Decrypt-Team-8.txt");

    while (getline(EncryptedTextFile, lineText)) {
        encryptedText.append(lineText + " ");
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
            encryptedTextLetters.push_back(encryptedText.at(i));
        }
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

    /////////////////////////////////////////////////////
    // figure out difference between rates and use     //
    // such difference to determine length of key word //
    /////////////////////////////////////////////////////

    for (i = 0; i < letterRate.size(); i++) {
        for (j = 0; j < letterRate.size(); j++) {
            if (letterRate.at(i) - letterRate.at(j) != 0) {
                freqDistrOfIntervals.push_back(abs(letterRate.at(i) - letterRate.at(j)));
                cout << abs(letterRate.at(i) - letterRate.at(j)) << ", ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;

    for (i = 0; i < encryptedTextLetters.size(); i++) {
        for (k = 'A'; k < 'Z'; k++) {
            cout << char(((encryptedTextLetters.at(i) - k) + 'A') % 26 + 'A');
        }
        cout << endl << endl;
    }
    cout << endl;




    return 0;
}