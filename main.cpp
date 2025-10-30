/*
 *  Resorted to:
 *      - Week 7's resource replit file for encrypting using Ceaser's cypher
 *      - c++ file I made that includes notes from Zybooks(eg. methods and data types)
 *
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string sentence;
    string newSentence;
    string decryptedText;
    bool isDecrypted = false;

    vector<char> letters;
    vector<double> letterRate;

    char currLetter;
    int currLetterCounter;

    int currRate;
    int highestRate = 0.0;
    int secHighestRate = 0.0;

    char highestLetter = '\0';
    char secHighestLetter = '\0';
    int shift;

    int i;
    int j;

    //getline(cin, sentence);
    cout << endl;
    sentence = "TMXE EMLR AIHT PVZG BUEM TWEA PKLT JGWZ ANLD HFMI MQRM VOWB KZZA MLAS RXYU NZPT HTRU AWAH TJOI IIED UOBA SNFO HYDJ KMKF OILR KHVD UTVH";// +
                // "NKHP CAWT UAQR WZEB NAIY AEJZ OIVW JKSW MNMP CNIE KUNZ HNDT RRXY MPCF EVVX AMPO SLSI FRNA HXBX JBRH CISV IZET HHSX BWKG SBUM FDME SAOH " +
                // "IQTF CQWA HTBX EIQA EYEF WCRO QNHI SMIU IIMO TMXE EMLR AIHT PVZG BUEB XEMQ STSG JUVR UCIH TYXV EEJN ZTFL XYQJ TJQZ TVUX OHTW JTZV EFEV " +
                // "WJKW RZDE LAAX W";

    for (i = 0; i < sentence.size(); i++) {
        if (isalpha(sentence[i])) {
            if (newSentence.find(sentence.at(i)) == string::npos) {
                newSentence.push_back(sentence.at(i));
                letters.push_back(sentence.at(i));
            }
        }
    }

    // letter comparisons
    // DECRYPTING //
    cout << "Letter Rates of: \n\t" << sentence << "\n\n";
    for (i = 0; i < letters.size(); i++) {
        currLetter = letters.at(i);
        currLetterCounter = 0;

        for (j = 0; j < sentence.size(); j++) {
            if (currLetter == sentence.at(j)) {
                currLetterCounter++;
            }
        }
        currRate = currLetterCounter; /// (double)sentence.length();
        if (newSentence.find(letters.at(i)) == string::npos) {
            letterRate.push_back(currRate);
        }

        if (isalpha(currLetter)) {
            if (highestRate < currRate) {
                highestRate = currRate;
                highestLetter = letters.at(i);
                //cout << "Highest Rate: " << highestRate << "\t" << letters.at(i) << "\n";// remove to check if process working appropriately


            } else if (currRate > secHighestRate && currRate < highestRate) {
                secHighestRate = currRate;
                secHighestLetter = letters.at(i);
                //cout << "Sec Highest Rate: " << secHighestRate << "\t" << letters.at(i) << "\n";// remove to check if process working appropriately
            }
        }

        cout << "\t" << currLetter << ": " << currRate << endl;
    }
    cout << endl;
    cout << "Highest Rate:\t  " << highestLetter << ",\t" << highestRate << "\n";
    cout << "Sec Highest Rate: " << secHighestLetter << ",\t" << secHighestRate << "\n";
    cout << endl << endl;


    // WORK ON //
    shift = highestLetter - secHighestLetter;

    for (i = 0; i < letters.size(); i++) {
        currLetter = letters.at(i);
        decryptedText = "";
        for (j = 0; j < sentence.size(); j++) {
            if (isalpha(currLetter)) {
                if (isupper(currLetter)) {
                    //letters.at(i) = ((currLetter - 'A') + shift) % 26 + 'A';
                    currLetter = ((currLetter - 'A') + shift) % 26 + 'A';
                    decryptedText.push_back(currLetter);
                } else if (islower(currLetter)) {
                    //letters.at(i) = ((currLetter - 'a') + shift) % 26 + 'a';
                    currLetter = ((currLetter - 'a') + shift) % 26 + 'a';
                    decryptedText.push_back(currLetter);
                } else {
                    letters.at(i) = currLetter;
                }
            }

            //cout << letters.at(i);
            // if ((j + 1) % 4 == 0) {
            //     cout <<  " ";
            // }
        }
        if (decryptedText.find("utter") != string::npos) {
            isDecrypted = true;
        } else {
            isDecrypted = false;
        }
        cout << "Is Decrypted: " << isDecrypted << ",\t" << decryptedText << endl;
        cout << endl;
    }

    cout << 'T' - 'H' << endl;
    cout << 'T' - 'M' << endl;

    return 0;
}