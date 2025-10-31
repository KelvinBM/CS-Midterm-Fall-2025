#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
// https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int shift;
    unsigned long long int random;

    clock_t t = clock();
    random = abs((t - 3245679890856789121) / (t * 50)) % 26;

    string message = "She wanted rainbow hair. That's what she told the hairdresser. It should be deep rainbow colors, too. She wasn't interested in pastel rainbow hair. She wanted it deep and vibrant so there was no doubt that she had done this on purpose.";

    int charCount = 0;
    for (int i = 0; i < message.size(); i++)
    {
        if (isalpha(message[i]) || message[i] == '.')
        {
            charCount += 1;
        }
    }
    vector<int> randomNum(charCount);

    for (int i = 0; i < randomNum.size(); i++)
    {
        t = clock();
        random = abs((t - 3245679890856789121) / (t * 50)) % 26;
        randomNum.at(i) = random;
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    cout << endl;

    int count = 0;
    int charNum;

    for (int i = 0; i < message.size(); i++)
    {
        charNum = static_cast<int>(message[i]);
        shift = charNum + randomNum.at(count);

        if (isalpha(message[i]))
        {
            message[i] = static_cast<char>(((shift + 'a') % 26) + 'a');
            count += 1;
        }
    }

    cout << "Encrypted Message: " << message << endl << endl;

    // decryption

    cout << "Key: ";

    for (int i = 0; i < randomNum.size(); i++)
    {
        cout << randomNum.at(i) << " ";
    }

    cout << endl << endl;

    count = 0;
    for (int i = 0; i < message.size(); i++)
    {
        charNum = static_cast<int>(message[i]);
        shift = charNum - randomNum.at(count);

        if (isalpha(message[i]))
        {
            message[i] = static_cast<char>(((shift - 'a') % 26) + 'a');
            count += 1;
        }
    }

    cout << "Decrypted Message: " << message << endl;
}