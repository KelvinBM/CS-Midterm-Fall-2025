/*
 *  Resorted to:
 *      - Week 7's resource replit file for encrypting using Ceaser's cypher
 *
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    string sentence;

    vector<char> letters;
    vector<double> letterRate;

    char currLetter;
    int currLetterCounter;

    double currRate;
    double highestRate = 0.0;
    double secHighestRate = 0.0;

    char highestLetter = '\0';
    char secHighestLetter = '\0';
    int shift;

    int i;
    int j;

    //getline(cin, sentence);
    sentence = "TMXE EMLR AIHT PVZG BUEM TWEA PKLT JGWZ ANLD HFMI MQRM VOWB KZZA MLAS RXYU NZPT HTRU AWAH TJOI IIED UOBA SNFO HYDJ KMKF OILR KHVD UTVH";// +
                // "NKHP CAWT UAQR WZEB NAIY AEJZ OIVW JKSW MNMP CNIE KUNZ HNDT RRXY MPCF EVVX AMPO SLSI FRNA HXBX JBRH CISV IZET HHSX BWKG SBUM FDME SAOH " +
                // "IQTF CQWA HTBX EIQA EYEF WCRO QNHI SMIU IIMO TMXE EMLR AIHT PVZG BUEB XEMQ STSG JUVR UCIH TYXV EEJN ZTFL XYQJ TJQZ TVUX OHTW JTZV EFEV " +
                // "WJKW RZDE LAAX W";

    for (i = 0; i < sentence.size(); i++) {
        letters.push_back(sentence.at(i));
    }

    // letter comparisons
    cout << fixed << setprecision(3);

    // DECRYPTING //
    cout << "Letter Rates of: \n\t" << sentence << "\n\n";
    for (i = 0; i < sentence.size(); i++) {
        currLetter = sentence.at(i);
        currLetterCounter = 0;

        for (j = 0; j < sentence.size(); j++) {
            if (currLetter == sentence.at(j)) {
                currLetterCounter++;
            }
        }
        currRate = currLetterCounter / (double)sentence.length();
        letterRate.push_back(currRate);

        if (isalpha(currLetter)) {
            if (highestRate < currRate) {
                highestRate = currRate;
                highestLetter = letters.at(i);
                cout << "Highest Rate: " << highestRate << "\t" << letters.at(i) << "\n";


            } else if (currRate > secHighestRate && currRate < highestRate) {
                secHighestRate = currRate;
                secHighestLetter = letters.at(i);
                cout << "Sec Highest Rate: " << secHighestRate << "\t" << letters.at(i) << "\n";
            }
        }

        cout << currLetter << ": " << currRate << endl;
    }

    shift = highestLetter - secHighestLetter;

    for (i = 0; i < sentence.size(); i++) {
        currLetter = letters.at(i);
        for (j = 0; j < sentence.size(); j++) {
            if (isalpha(currLetter)) {
                if (isupper(currLetter)) {
                    letters.at(i) = currLetter = ((currLetter + 'A') + shift) % 26 + 'A';
                } else if (islower(currLetter)) {
                    letters.at(i) = ((currLetter + 'a') + shift) % 26 + 'a';
                } else {
                    letters.at(i) = currLetter;
                }
            }

            cout << letters.at(i);
        }
        cout << endl;
    }

    return 0;
}