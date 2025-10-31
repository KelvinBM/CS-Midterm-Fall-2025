#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    string encoded_message = "Jyv nrekvu irzesfn yrzi. Kyrk'j nyrk jyv kfcu kyv yrziuivjjvi. Zk jyflcu sv uvvg irzesfn tfcfij, kff. Jyv nrje'k zekvivjkvu ze grjkvc irzesfn yrzi. Jyv nrekvu zk uvvg reu mzsirek jf kyviv nrj ef uflsk kyrk jyv yru ufev kyzj fe gligfjv.";
    string encoded_messageBruteForce = encoded_message;

    vector<int> countLetters(26);
    const double mostFrequent[26] = {8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03,
                                     5.92, 7.31, 0.1, 0.69, 3.98, 2.61, 6.95,
                                     7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 2.88,
                                     1.11, 2.09, 0.17, 2.11, 0.08};
    int asciiChar;

    for (int i = 0; i < encoded_message.size(); i++)
    {
        encoded_message[i] = tolower(encoded_message[i]);
    }

    cout << encoded_message << endl;

    for (unsigned int i = 0; i < encoded_message.size(); i++)
    {
        asciiChar = encoded_message[i];
        if (isalpha(asciiChar))
        {
            countLetters[asciiChar - static_cast<int>('a')] += 1;
        }
    }

    for (unsigned int i = 0; i < 26; i++)
    {
        cout << static_cast<char>(97 + i) << ": " << countLetters.at(i) << ", ";
    }
    cout << endl;

    int mostFreqLetter = 0;
    int maxLetterCount = countLetters.at(0);

    for (unsigned int i = 0; i < 26; i++)
    {
        if (maxLetterCount < countLetters.at(i))
        {
            maxLetterCount = countLetters.at(i);
            mostFreqLetter = i;
        }
    }

    int shift = ((mostFreqLetter + 1) - 5);

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
            else{
                encoded_message[i] = static_cast<char>((numChar - shift));
            }
        }
    }

    cout << encoded_message << endl;
    cout << "Shift = " << shift;

    return 0;
}