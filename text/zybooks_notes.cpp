// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <cstdlib> // for rand() - random numbers
// #include <cmath> // for regular math functions
// #include <ctime> // for time(0) function
// #include <vector>
// //#inlcude <unistd.h> // for usleep(time in nanoseconds) --> to make program wait
//
// using namespace std;
//
// /*****     EULER problems     *****/
//
// int zybooks_notes() {
//     std::cout << "Hello World" << endl;// without std namespace
//     std::abs(-15);// works with floats and ints, use fabs() function to make the operation clear
//     cout << "Hello World2" << endl;
//
//     int numA, numB, numC;
//     cin >> numA >> numB >> numC;// inputting all at once
//
//     string name = "My Name";
//     char a = 'a';
//     cout << name + a << endl;
//
//     //at(): The notation someString.at(x) accesses the character at index x of a string.
//     name.at(0);
//     name.size();// length of string
//     name.length();
//     name.push_back('?');// appends char to end of str
//     name.append("fgh");// appends to en string, using '+' operator returns a new string
//
//
//     // string.find(item) returns the index of the first occurrence of item in string. If no occurrence is found, then the function returns string::npos.
//     // str.replace(indx, n, "") replaces the n characters starting at index indx of str with an empty string.
//     // The insert() function inserts text into a string. Ex: s1.insert(startIndex, newText) inserts newText into s1 before the character at index startIndex.
//     // The replace() function replaces text in a string. Ex: s1.replace(startIndex, numCharacters, newText) replaces the substring of s1 starting at index startIndex and having numCharacters characters with newText.
//     // substr() function is used to get a substring of a string. Ex: Given a string s1, s1.substr(startIndex, numCharacters)
//     // find() function is used to find a string or character inside a string. Ex: Given a string s1, s1.find(textToFind) returns the index of the first occurrence of textToFind within s1, or string:npos if not found. textToFind can be a string or character. string::npos is a special value representing "no position".
//
//
//     double number = 2.5;
//     cout << fixed << setprecision(2) << number << endl;// set floating-point precision
//
//     cout << M_PI << endl;// #include <corecrt_math_defines.h> // pie value
//
//     cout << fabs(-20.34) << " " << abs(-20.2) << endl;// absolute value of floating point
//
//     cout << 2.0 + 3 << endl;// implicit casting // the value on the left is used to convert to attributed type
//     cout << static_cast<double>(3 + 4) << endl;// type cast // explicit conversion
//
//     int two = 2;
//     cout << static_cast<double>(two + 3) << endl;
//
//     string name2;
//     cout << "Enter Name: ";
//     getline(cin, name2); // gets entire line until '\n' character
//
//
//     // combining cin and getline(cin, varName)
//     string listName;
//     string listItem1;
//     string listItem2;
//     string listItem3;
//
//     getline(cin, listName);
//     cin >> listItem1;
//     cin >> listItem2;
//     cin >> listItem3;
//
//     cout << listName << ":" << endl;
// 	cout << listItem1 << endl;
// 	cout << listItem2 << endl;
// 	cout << listItem3 << endl;
//
//     // generating random numbers with <cstdlib> //
//     /*
//         rand() function generates "pseudo-random" sequence of values because of its default
//         seed(srand(1)), changing this seed each iteration results in unique sequences of values
//
//         although the rand() function returns a random number, because of the default seed(1) it starts
//         with it can provide the same sequence of values every time the program is ran.
//
//             - change its seed using srand(int value) ::::: ex -> srand(2)
//                 - changing the seed before each program run results in unique random number sequences
//
//             - making seed equal to current time(value in seconds) always gives unique sequence
//                 - time(0) // time since jan 1, 1970
//                     - srand(time(0));
//
//     */
//     // generating random numbers with <random> //
//     /*
//
//         The <random> number library provides greater control of the random-number generation.
//         Using the library, a programmer may specify the engine used to produce the numbers and
//         the distribution of the numbers. Trivial random-number sequences may still be generated
//         using <cstdlib> library functions srand() and rand().
//
//     */
//
//     // comparing floating point numbers //
//     /*
//         avoid using '==' operator and instead use approximation (close enough values)
//         - Ex: If (x - y) < 0.0001, x and y are deemed equal.
//               Because the difference may be negative, the absolute value is used: fabs(x - y) < 0.0001.
//               fabs() is a function in the math library. The difference threshold indicating that
//               floating-point numbers are equal is often called the epsilon
//
//         - subtract each value from each other and use a threshold close to zero(0.0001) to see if their subtraction is close to it
//             fabs(num1 - num2) < 0.0001
//                 order of subtraction doesn't mnatter
//                 this compares if values are the same
//
//     */
//
//
//
//     int randNum1 = rand();// random number using RAND_MAX from library imported
//     int randNum2 = rand() % 10;//  generates 10 random numbers // 0 - 9
//     // random number within range // range is MaxVal - MinVal + 1 [15 - 10 + 1 = 6] // starts at 10
//     int randNum3 = (rand() % 6) + 10;// adding 10 to (rand() % 6) makes range start at 10
//
//     int minVal, maxVal;
//     cin >> minVal;// enter minimum value of range
//     cin >> maxVal;// enter maximum value of range
//     int numRange = maxVal - minVal + 1;
//     int randNum4 = (rand() % (numRange)) + minVal;
//
//     // changing seed(first stored value within rand() function)
//     // having a unique seed for each program run makes it so that
//     srand(2);// seed changed to 2
//     srand(time(0));// always gives unique seed
//
//
//     /*
//
//         #include <string>  ---> string myString = "asdads";
//         #include <cstring> ---> char myString[] = "asdasd";
//         //
//             char nameArr[5];
//
//             nameArr[0] = 'A';
//             nameArr[1] = 'l';
//             nameArr[2] = 'a';
//             nameArr[3] = 'n';
//             nameArr[4] = '\0'; // Null character
//
//         //
//
//
//         strcpy() --> for copying string char array to another variable
//
//         Arrays: declared as int myList[10], accessed as myList[i].
//         Vectors: declared as vector<int> myList(10), accessed as myList.at(i).
//
//         Arrays have a simpler syntax than vectors, but vectors are safer to use. Thus, using vectors rather than arrays is good practice.
//
//         Char arrays were the only kinds of strings in C++'s predecessor language C, and thus are sometimes called C strings to distinguish them from C++'s string type.
//         --> An example is: char movieTitle[20] = "Star Wars";.
//         --> Because a string can be shorter than the character array,
//         --> a string in a char array must end with a special character known as a null character, written as '\0'.
//         // Given a string literal like "Star Wars", the compiler automatically appends a null character.
//
//
//         a char array is initialized when declared, then the char array's size may be omitted, as in char userName[] = "Hellen"; . The compiler determines the size from the string literal, in this case 6 + 1 (for the null character), or 7
//
//         // An array of characters ending with a null character is known as a null-terminated string
//         --> A programmer can traverse a string using a loop that stops when reaching the null character.
//         --> **** A common error is to loop for the string's array size rather than stopping at the null character. ****
//     */
//     // vectors (lists) //
//     /*
//         a vector is an ordered list of items of a given data type.
//         Each item in a vector is called an element
//             Each element is a variable
//             and can be read and assigned
//             like any other variables. 'numList.at(0) = 1'
//
//         1) push_back() --> appends a new element to the end of an existing vector.
//         2) at() --> accesses a vector element at the index specified within the parentheses.
//
//         vector<dataType> vectorName;
//
//         A vector can also be initialized by specifying the initial values in braces {} separated by commas. Ex: vector<int> carSales = {5, 7, 11};
//
//         vector<int> gameScores(4); declares a vector gameScores with 4 integer elements// each element equals to zero unless reassigned
//
//         size() --> returns the number of vector elements
//
//         resize(#num) --> setting vector's size or changing it while a program executes using resize(N).
//                         Ex: highScore.resize(10) resizes the highScores vector to have 10 elements.
//
//
//         back() --> returns las element of a vector(vector remains unchanged)
//
//         pop_back() --> removes last element
//
//         vector copy operation ---> = operator conveniently performs an element-by-element copy of a vector
//         // list1 = list2;
//
//
//         vector equality operation -->  == operator conveniently compares vectors element-by-element
//     */
//     vector<string> stringList;// declares an empty vector capable of storing an unspecified number of elements
//     vector<int> numbers;
//     vector<int> carSales = {5, 7, 11}; // declared with initially given values
//     vector<int> withLength(4);
//
//     stringList.push_back("Hello");
//     numbers.push_back(1);
//
//     stringList.at(0);
//     numbers.at(0);
//     numbers.size();
//
//     // #include <cctype> //  common functions for working with characters // ctype is short for "character type".
//     //--- http://www.cplusplus.com/reference/cctype/ ---//
//     /*
//
//         isalpha(char) ---> returns true if char is 'a-z' or 'A-Z' --> alphabetic
//         isdigit(char) ---> returns true if char is numeric digit '0-9'
//         isalnum(char) ---> returns true if char is alphabetic or numeric digit
//         isspace(char) ---> returns true if char is whitespace
//         islower(char) ---> returns true if char is lowercase letter 'a-z'
//         isupper(char) ---> returns true if char is uppercase letter 'A-Z'
//         isblank(char) ---> returns true if char is blank character(tabs, spaces, etc.)
//         isxdigit(char) --> returns true if char is hexadecimal digit: 0-9, a-f, A-F.
//         ispunct(char) ---> returns true if char is punchtion character (Punctuation characters include: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
//         isprint(char) ---> returns true if char is printable character. Printable characters include alphanumeric, punctuation, and space characters.
//         iscntrl(char) ---> returns true if char is control character. Control characters are all characters that are not printable.
//
//
//         toupper(char) ---> If c is a lowercase alphabetic character (a-z), returns the uppercase version (A-Z). If c is not a lowercase alphabetic character, just returns c.
//         tolower(char) ---> If c is an uppercase alphabetic character (A-Z), returns the lowercase version (a-z). If c is not an uppercase alphabetic character, just returns c.
//
//     */
//
//     return 0;
// }