#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    string encoded_message = "Ftq nak imxwqp paiz ftq efdqqf uz m omdqrdqq imk, bxmkuzs iuftagf zafuoq ar itmf ime mnagf tuy. Tq pupz'f tqmd ftq eagzp ar ftq omd me tue nmxx omdqqzqp uzfa ftq damp. Tq faaw m efqb faimdp uf, mzp uz pauzs ea eqmxqp tue rmfq.";
    string encoded_messageBruteForce = encoded_message;
    // vector<char> notNumAlpha = {
    //     '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '<', '>', '[', ']', ' ', ',', '.', '?', '/', '\'', '\"', '|', '{', '}', ':', ';'
    // };
    vector<int> countLetters(26);
    const double mostFrequent[26] = {8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03,
                                     5.92, 7.31, 0.1, 0.69, 3.98, 2.61, 6.95,
                                     7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 2.88,
                                     1.11, 2.09, 0.17, 2.11, 0.08};
    int asciiChar;

    for (unsigned int i = 0; i < encoded_message.size(); i++)
    {
        asciiChar = encoded_message[i];
        if (asciiChar >= static_cast<int>('a') &&
            asciiChar <= static_cast<int>('z'))
        {
            countLetters[asciiChar - static_cast<int>('a')] += 1;
        }
        if (asciiChar >= static_cast<int>('A') &&
            asciiChar <= static_cast<int>('Z'))
        {
            countLetters[asciiChar - static_cast<int>('A')] += 1;
        }
    }

    for (unsigned int i = 0; i < 26; i++)
    {
        cout << static_cast<char>(97 + i) << " " << countLetters.at(i) << endl;
    }

    int mostFreqLetter = 0;
    int maxLetterCount = countLetters.at(0);

    for (unsigned int i = 0; i < 26; i++)
    {
        if (maxLetterCount < countLetters.at(i))
        {
            maxLetterCount = countLetters.at(i);
            mostFreqLetter = i;
        }
        cout << i << " " << static_cast<char>(97 + i) << " " << countLetters.at(i) << " " << maxLetterCount << endl;
    }

    // for (unsigned int i = 0; i < notNumAlpha.size(); i++) {
    //     for (unsigned int j = 0; j < encoded_message.size(); j++) {
    //         if (notNumAlpha[i] == encoded_message[j]) {
    //             encoded_message[j] = '|';
    //         }
    //     }
    // }

    int shift = (mostFreqLetter + 1) - 5;

    for (unsigned int i = 0; i < encoded_message.size(); i++)
    {
        int numChar = encoded_message[i];
        if (isalpha(encoded_message[i]))
        {
            if (numChar - shift < static_cast<int>('a'))
            {
                int diff = static_cast<int>('a') - (numChar - shift) - 1;
                encoded_message[i] = static_cast<char>(static_cast<int>('z') - diff);
            }
            else if (numChar - shift < static_cast<int>('A'))
            {
                int diff = static_cast<int>('A') - (numChar - shift) - 1;
                encoded_message[i] = static_cast<char>(static_cast<int>('Z') - diff);
            }
            else
            {
                encoded_message[i] = static_cast<char>(numChar - shift);
            }
        }
    }

    cout << encoded_message << endl;

    cout << "Is that message correct? (y/n)" << endl;

    char userResponse;

    cin >> userResponse;

    if (userResponse == 'y')
    {
        cout << "Thank you for using our project!" << endl;
    }
    else if (userResponse == 'n')
    {
        cout << "BRUTE FORCE SOLUTION" << endl;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < encoded_messageBruteForce.size(); j++)
            {
                int numChar = encoded_messageBruteForce[j];
                if (isalpha(encoded_messageBruteForce[j]))
                {
                    if (numChar - i < static_cast<int>('a'))
                    {
                        int diff = static_cast<int>('a') - (numChar - i) - 1;
                        encoded_messageBruteForce[j] = static_cast<char>(static_cast<int>('z') - diff);
                    }
                    else if (numChar - i < static_cast<int>('A'))
                    {
                        int diff = static_cast<int>('A') - (numChar - i) - 1;
                        encoded_messageBruteForce[j] = static_cast<char>(static_cast<int>('Z') - diff);
                    }
                    else
                    {
                        encoded_messageBruteForce[j] = static_cast<char>(numChar - i);
                    }
                }
            }
            cout << "shift = " << i << " : " << encoded_messageBruteForce << endl;
            cout << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < encoded_messageBruteForce.size(); j++)
            {
                int numChar = encoded_messageBruteForce[j];
                if (isalpha(encoded_messageBruteForce[j]))
                {
                    if (numChar + i < static_cast<int>('a'))
                    {
                        int diff = static_cast<int>('a') + (numChar + i) + 1;
                        encoded_messageBruteForce[j] = static_cast<char>(static_cast<int>('z') + diff);
                    }
                    else if (numChar + i < static_cast<int>('A'))
                    {
                        int diff = static_cast<int>('A') + (numChar + i) + 1;
                        encoded_messageBruteForce[j] = static_cast<char>(static_cast<int>('Z') + diff);
                    }
                    else
                    {
                        encoded_messageBruteForce[j] = static_cast<char>(numChar + i);
                    }
                }
            }
            cout << "shift = -" << i << " : " << encoded_messageBruteForce << endl;
            cout << endl;
        }
    }

    return 0;
}