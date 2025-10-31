#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    string key = "SNAKE";
    string message = "MEET ME AT THE ELEPHANT";

    vector<int> keyNums(key.size());

    cout << "Key: ";
    for (int i = 0; i < keyNums.size(); i++)
    {
        keyNums.at(i) = static_cast<int>(key[i] + 1) - static_cast<int>('A');
    }

    for (int i = 0; i < keyNums.size(); i++){
        cout << keyNums.at(i) << " ";
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < message.size(); i++){
        if (count >= keyNums.size() - 1){
            count = 0;
        }
        
        int numChar = static_cast<int>(message[i]);
        int shift = numChar + keyNums.at(count);

        if (isalpha(message[i]))
        {
            message[i] = static_cast<char>(((shift + 'A') % 26) + 'A');
        }
    }

    cout << "Encrypted message: " << message << endl;

    // Decryption

    count = 0;
    for (int i = 0; i < message.size(); i++)
    {
        if (count >= keyNums.size() - 1)
        {
            count = 0;
        }

        int numChar = static_cast<int>(message[i]);
        int shift = numChar - keyNums.at(count);

        if (isalpha(message[i]))
        {
            message[i] = static_cast<char>(((shift + 'A') % 26) + 'A');
        }
    }

    cout << "Decrypted message: " << message << endl;

    return 0;
}