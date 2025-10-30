// Video on the Vigenere Cipher: https://www.youtube.com/watch?v=SkJcmCaHqS0
// Video on message encryption(general): https://www.youtube.com/watch?v=FFhpvirLKSA I used this to gain an understanding of implementing for loops; they're problematic for me.
// Light use of gpt for finding how to use keys.txt, as well as google for that portion.
// Video on Caesar Cipher: https://www.youtube.com/watch?v=0ZxqLybllNQ An extension of understanding forloops and implementing a proper system
// Week 7 Zybooks brushup
// Caesar shift encryption: https://replit.com/@mab253/ceaser-encrypt#main.cpp
// Caesar shift decryption: https://replit.com/@mab253/caesar-decrypt#main.cpp used for understanding the math behind decryption








#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

long long value; 
long long randVal(){ //psuedorand generator for encryption/decryption
    value = 1103515245 * value + 12345;
    return value;
}
int main(){

    cout << "Choose an option: " << endl;
    cout << "1 - Decrypt and analyze ciphertext" << endl;
    cout << "2 - Custom encryptionn/decryption" << endl;
    int usersChoiceValueForEitherOneOrTwo; // lol
    cin >> usersChoiceValueForEitherOneOrTwo; // already regretting it
    if(usersChoiceValueForEitherOneOrTwo == 1){
        string cipherText = 
        "TMXE EMLR AIHT PVZG BUEM TWEA PKLT JGWZ ANLD HFMI MQRM VOWB KZZA MLAS RXYU NZPT HTRU AWAH"
        "TJOI IIED UOBA SNFO HYDJ KMKF OILR KHVD UTVH NKHP CAWT UAQR WZEB NAIY AEJZ OIVW JKSW MNMP CNIE "
        "KUNZ HNDT RRXY MPCF EVVX AMPO SLSI FRNA HXBX JBRH CISV IZET HHSX BWKG SBUM FDME SAOH IQTF CQWA HTBX "
        "EIQA EYEF WCRO QNHI SMIU IIMO TMXE EMLR AIHT PVZG BUEB XEMQ STSG JUVR UCIH TYXV EEJN ZTFL XYQJ TJQZ TVUX OHTW JTZV EFEV WJKW RZDE LAAX W";

        string cleanedCipher = "";

        for(int i = 0; i < cipherText.length(); i++){
            if(isalpha(cipherText[i])){ // Doing this to confirm that it is a letter!
                char upperCase = toupper(cipherText[i]); // Converts it to uppercase
               cleanedCipher += upperCase; // Transfers the cleaned up cipher text to the cleanedCipher variable
           }

        }

        int alphabet[26]; // From letters A-Z

        for(int i = 0; i < 26; i++){
          alphabet[i] = 0;
        }

        for(int i = 0; i < cleanedCipher.length(); i++){
         int scope = cleanedCipher[i] - 'A'; // Keeps our values within the alphabet
         if(0 <= scope && scope < 26){
                alphabet[scope]++;
            }
        }

        cout << "Letter Frequency(A-Z): " << endl;
        for(int i = 0; i < 26; i++){
           char letter = char(i + 'A');
          cout << letter << ": " << alphabet[i];
             if(i % 6 == 5){ // To ensure there are around 6 letters per row; Formatting!
              cout << endl;
            }else{
                cout << "\t";
            }
        }
        cout << endl;

        ifstream keyFile("keys.txt"); //Using to directly get keys from the text file!; Searched on google "Is there a way to implement txt files in zybooks?" Leading me to finding out about ifstreams at around 8:35 pm on Oct. 28th.
        string keys[83]; //this shows the list of text values in keys.txt, letting us test each word with our ciphertext
        int numKeys = 0;

        while(keyFile >> keys[numKeys]){ //an extension of what i learned through ifstream
            numKeys++;
        }
        keyFile.close();
        int bestScore = -1; //starting low just in case 
        string bestKey = "";
        string bestPlain = "";

        for(int j = 0; j < numKeys; j++){
            string key = keys[j];

            for(int k = 0; k < key.length(); k++){ //making keys uppercase :D
                  key[k] = toupper(key[k]);
                }

            string plainText = "";
            int kl = key.length();

            for(int t = 0; t < cleanedCipher.length(); t++){
               int cV = cleanedCipher[t] - 'A';
               int kV = key[t % kl] - 'A';
               int pV = (cV - kV + 26) % 26;
               plainText += char('A' + pV);

             }

            int score = 0; //Implementation of the score system and counting how many times THE appears instead of vowels. Seems a bit cleaner!
             for(int i = 0; i < plainText.length() - 2; i++){
                if(plainText[i] == 'T' && plainText[i + 1] == 'H' && plainText[i + 2] == 'E'){ 
                    score++;
                }
        }

        if(score > bestScore){
            bestScore = score;
            bestKey = key;
            bestPlain = plainText;
        }

        cout << "\nKey " << key << endl;
        cout << "Preview: ";
        for(int y = 0; y < 80 && y < plainText.length(); y++){
            cout << plainText[y];
        } 
        cout << "... \n";

        //cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        //cout << "<<<<<<<Correct Key: " << bestKey << ">>>>>>>" << endl;
        //cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

        //cout << "Decrypted Plaintext: " << endl;
        //cout << bestPlain << endl;
        }
    
        cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "<<<<<<<Correct Key: " << bestKey << ">>>>>>>" << endl;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

        cout << "Decrypted Plaintext: " << endl;
        cout << bestPlain << endl;
    } else if(usersChoiceValueForEitherOneOrTwo == 2){
        cout << "Enter 1 to encrypt or 2 to decrypt: ";
        int valueTwo;
        cin >> valueTwo;

        cout << "Enter your message: ";
        string message;
        getline(cin, message); // This first is the eat the input buffer than cin >> valueTwo leaves behind
        getline(cin, message); // This second ensures that it doesn't end at whitepscae, letting the user make spaces when entering their message

        cout << "Enter any numeric key: ";
        long long seed;
        cin >> seed;
        value = seed;

        string result = "";
        for(int i = 0; i < message.length(); i++){
            char c = message[i];
            if(isalpha(c)){
                char base;
                if(isupper(c)){
                    base = 'A';
                }else{
                    base = 'a';
                }
                int val = c - base;
                int d = randVal() % 26;
                if(valueTwo == 1){
                    val = (val + d) % 26; //Encryption!!!
                }else if(valueTwo == 2){
                    val = (val - d + 26) % 26; //Decryption!!!

                }
                result += char(base + val);
            }else{
                result += c;
            }
        }

        if(valueTwo == 1){
            cout << "Encrypted text: " << result << endl;
        }else if (valueTwo == 2){
            cout << "Decrypted text: " << result << endl;
        }else{
            cout << "Invalid Choice" << endl;
        }

    }
    
    return 0;
}