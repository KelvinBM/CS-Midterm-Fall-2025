#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    int shift;

    string message = "The boy walked down the street in a carefree way, playing without notice of what was about him. He didn't hear the sound of the car as his ball careened into the road. He took a step toward it, and in doing so sealed his fate.";

    cout
        << "By how much would you like to shift?" << endl;

    cin >> shift;

    if (shift > 26)
    {
        shift = shift - 26;
    }
    if (shift < -26)
    {
        shift = shift + 26;
    }

    for (unsigned int i = 0; i < message.size(); i++)
    {
        int numChar = message[i];
        if (isalpha(message[i]))
        {
            if (numChar + shift < static_cast<int>('a'))
            {
                int diff = static_cast<int>('a') - (numChar + shift);
                message[i] = static_cast<char>(static_cast<int>('z') - diff);
            }
            else if (numChar + shift < static_cast<int>('A'))
            {
                int diff = static_cast<int>('A') - (numChar + shift);
                message[i] = static_cast<char>(static_cast<int>('Z') - diff);
            }
            else
            {
                message[i] = static_cast<char>(static_cast<int>(message[i]) + shift);
            }
            cout << static_cast<int>(message[i]) << endl;
        }
    }

    cout << message << endl;

    return 0;
}