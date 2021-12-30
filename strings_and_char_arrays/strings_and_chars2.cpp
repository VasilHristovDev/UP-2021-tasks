#include <iostream>
#include <cmath>

const int MAX_SIZE = 50;


//функция, която намира дължината на низ
unsigned length (const char str[])
{
    unsigned len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}

//функция (подобна на strcmp), сравняваща два низа лексикографски
int myStrCompare(const char str1[], const char str2[])
{
    unsigned comparedIndex = 0;
    while(str1[comparedIndex] != '\0' && str2[comparedIndex] != '\0')
    {
        if(str1[comparedIndex] > str2[comparedIndex])
        {
            return 1;
        }
        else if (str1[comparedIndex] == str2[comparedIndex])
        {
            comparedIndex++;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}


// функция, която променя всички малки букви в даден низ и ги прави главни
// работи с реферънс към низа от главната програма и променя стойностите в адресите от него
void toUpper (char *& str)
{
    char * begin = str;

    int i = 0;
    while(*(begin + i) != '\0')
    {
        if(*(begin + i) >= 'a' && *(begin + i) <= 'z')
        {
            *(begin + i) -= 'a' + 'A';
        }
        i++;
    }
}
int main1()
{
    char str[MAX_SIZE];
    std::cout<<"Enter a string to check the length of:";
    std::cin>>str;

    unsigned strLen = length(str);
    std::cout<<"The length is: "<<strLen<<std::endl;

    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    std::cout<<"Now we would compare two strings lexicographically."<<std::endl;

    std::cout<<"Enter the first string:";
    std::cin>>str1;

    std::cout<<"Enter the second string:";
    std::cin>>str2;

    if(myStrCompare(str1,str2) == 1)
    {
        std::cout<<"The first string is bigger than the second lexicographically"<<std::endl;
    }
    else if(myStrCompare(str1, str2) == -1)
    {
        std::cout<<"The second string is bigger than the first lexicographically"<<std::endl;
    }
    else
    {
        std::cout<<"The strings are equal"<<std::endl;
    }

    char * ptrToStr = str;
    toUpper(ptrToStr);

    std::cout<<ptrToStr<<std::endl;

    return 0;
}


//напишете  функция, която проверява дали един низ е палиндром
bool isPalindrome(const char * str, unsigned size)
{
    unsigned i = 0;
    while (i != size)
    {
        if( *( str + i ) != *(str + size - i - 1))
            return false;
        i++;
    }
    return true;
}
int main2()
{
    char str[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin>>str;

    if(isPalindrome(str, length(str)))
        std::cout<<str<<" is palindrome"<<std::endl;
    else
        std::cout<<str<<" is not palindrome"<<std::endl;

    return 0;
}
// напишете функция, която намира подстринг на друг стрринг от индекс за старт до индекс за край
char * findSubString(const char * source, int start, unsigned length)
{
    unsigned size = length - start + 1;
    char * substr = new char [size];

    for (int i = 0; i < size; ++i) {
        *(substr + i) = *(source + start++);
    }

    *(substr + size) = '\0';
    return substr;
}
int main3()
{
    char str[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin>>str;

    int start, len;
    std::cout<<"Enter the starting index of the substring:";
    std::cin>>start;

    char * ptrToSubstring  = findSubString(str, start, length(str));

    std::cout<<ptrToSubstring<<std::endl;

    ptrToSubstring = nullptr;
    delete [] ptrToSubstring;

    return 0;
}
// напишете функция, която връща броя на думите, по - големи от minLength символа
unsigned countOfWords(const char * str, unsigned minLength)
{
    unsigned count = 0;
    int numOfLetters = 0;
    int currentChar = 0;
    while(str[currentChar] != '\0')
    {
        numOfLetters++;
        if(str[currentChar + 1] == ' ' || str[currentChar + 1] == '\0')
        {
            if(numOfLetters >= minLength)
            {
                count++;
            }
            numOfLetters = 0;
            currentChar++;
        }
        currentChar++;
    }
    return count;
}
int main4()
{
    char str[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin.getline(str, MAX_SIZE);

    std::cout<<"Number of words larger than 3 characters: "<<countOfWords(str, 4);
    return 0;
}

//напишете програма, която взима един стринг и обръща всички думи в него
// за дума считаме всяко разделение с ' ' ',' и '.'
char * revertWordsInsideString(const char * str)
{
    char * reverted = new char [length(str) + 1];
    int startingIndex = 0;
    int endingIndex = 0;
    int currentIndex = 0;
    while(*(str + currentIndex) != '\0' && currentIndex < length(str))
    {
        char nextChar = *(str + currentIndex + 1);
        if(nextChar == ',' || nextChar == '.' || nextChar == ' ' || nextChar == '\0')
        {
            endingIndex = currentIndex;
            char * tempWord = new char [endingIndex - startingIndex + 1];
            int tempOccupiedChars = 0;

            for (int i = startingIndex; i <= endingIndex ; ++i) {
                tempWord[tempOccupiedChars++] = str[i];
            }

            for (int i = startingIndex,  k = 0; i <= endingIndex; ++i,k++) {
                reverted[i] = tempWord[tempOccupiedChars - k - 1];
            }

            *(reverted + currentIndex + 1) = nextChar;
            tempOccupiedChars = 0;

            tempWord = nullptr;
            delete[] tempWord;

            startingIndex = currentIndex + 2;
        }
        currentIndex++;
    }

    return reverted;

}
int main5()
{
    char str[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin.getline(str, MAX_SIZE);

    char * ptrToRevertedWords = revertWordsInsideString(str);
    std::cout<<ptrToRevertedWords<<std::endl;

    ptrToRevertedWords = nullptr;
    delete [] ptrToRevertedWords;

    return 0;
}

//Да се напише функция, която връща число по зададен стринг, който започва с + или -
//стринга да е максимално 9 елемента и да съдържа елементи само от '0' до '9'
signed int parseStringToNumber(char * str)
{
    signed int number = 0;
    auto helperTenPow = (double)length(str) - 2;
    for (int i = 1; i < length(str); ++i) {
        number += pow(10.0,helperTenPow--) * (str[i] - '0');
    }
    if(str[0] == '-')
        number*=-1;

    return number;
}
bool validate ( char * str)
{
    if((str[0] != '+' && str[0] != '-') || length(str) > 9)
    {
        return false;
    }
    for (int i = 0; i < length(str) ; ++i) {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}
int main6()
{
    const int MAX_CHARS = 10;
    char str [MAX_CHARS];

    std::cout<<"Enter the number with a symbol + or - in the beginning:";
    std::cin>>str;
    if(!validate(str))
    {
        std::cerr<<"Invalid data entered! Try again!"<<std::endl;
        return -1;
    }
    int number = parseStringToNumber(str);
    std::cout<<number<<std::endl;

    return 0;
}
//да се напише функция, която проверява дали един низ се среща в началото на друг
bool containsInTheBeginning(char * str, char * subStr)
{
    unsigned lenStr = length(str);
    unsigned lenSubStr = length(subStr);

    unsigned currentIndex = 0;
    while(str[currentIndex] != '\0' && currentIndex < lenSubStr)
    {
        if(str[currentIndex] != subStr[currentIndex])
            return false;
        currentIndex++;
    }
    return true;
}
// да се напише функция, която проверява дали един низ е част от друг
bool contains (char * str, char * subStr)
{
    unsigned len = length(str);
    unsigned lenSubstr = length(subStr);
    bool flag = false;
    int startingIndex = 0;
    int counter = 0;
    int i = 0;
    while(!flag && i < len)
    {
        startingIndex = i;
        for (int j = 0; j < lenSubstr; ++j) {
            if(subStr[j] == str[startingIndex++])
                counter++;
        }
        if(counter == lenSubstr)
            flag = true;
        else
            flag = false;
        counter = 0;
        i++;
    }
    return flag;
}
int main7()
{
    char str[MAX_SIZE];
    char subStr[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin.getline(str, MAX_SIZE);

    std::cout<<"Enter the substring:";
    std::cin.getline(subStr, MAX_SIZE);

    std::cout<<"The string "<<(containsInTheBeginning(str, subStr) ? "contains "  : "does not contain ")<<"the substring in the beginning! "<<std::endl;
    std::cout<<"The string "<<(contains(str, subStr) ? "contains "  : "does not contain ")<<"the substring!"<<std::endl;

    return 0;
}
//Да се напише функция, която изтрива повтарящите се интервали в един символен низ
char * removeIntervals(char * str)
{
    char * returnableStr = new char [length(str)];
    int currentIndex = 0;
    int occupiedIndex = 0;
    while(str[currentIndex])
    {
        if(str[currentIndex] == ' ')
        {
            returnableStr[occupiedIndex++] = str[++currentIndex];
            currentIndex++;
        }
        else
            returnableStr[occupiedIndex++] = str[currentIndex++];
    }

    returnableStr[occupiedIndex++] = '\0';
    return returnableStr;
}
int main8()
{
    char str[MAX_SIZE];
    std::cout<<"Enter the string:";
    std::cin.getline(str, MAX_SIZE);

    char * ptrToNewString = removeIntervals(str);

    std::cout<<ptrToNewString<<std::endl;

    ptrToNewString = nullptr;
    delete[] ptrToNewString;

    return 0;

}
//да се напише функция, която изтрива всяко срещане на даден низ в друг низ
char * removeSubStrFromStr(char * str, char * substr)
{

    unsigned len = length(str);
    unsigned subLen = length(substr);
    char * returnableStr = new char [len - subLen];

    int currentIndex = 0;
    while(str[currentIndex])
    {
        returnableStr[currentIndex] = str[currentIndex];
        currentIndex++;
    }
    currentIndex = 0;
    int counter = 0;
    while(returnableStr[currentIndex])
    {
       int startingIndex = currentIndex;
        for (int j = 0; j < subLen; ++j) {
            if(substr[j] == returnableStr[startingIndex++])
                counter++;
        }
        if(counter == subLen)
        {

            for (int i = currentIndex; i < len ; ++i) {
                returnableStr[i] = returnableStr[i + subLen];
            }
            len -= subLen;
        }

        counter = 0;
        currentIndex++;
    }
    returnableStr[len++] = '\0';
    return returnableStr;
}
int main9()
{
    char str[MAX_SIZE];
    char substr[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin.getline(str,MAX_SIZE);

    std::cout<<"Enter the substring:";
    std::cin.getline(substr, MAX_SIZE);

    if(!contains(str,substr))
    {
        std::cerr<<"The substring you've entered is not part of the main string!"<<std::endl;
        return -1;
    }
    char * ptrToNewString = removeSubStrFromStr(str, substr);
    std::cout<<ptrToNewString<<std::endl;

    ptrToNewString = nullptr;
    delete[] ptrToNewString;

    return 0;
}
//да се напише функция, която връща най - често срещаната дума в редицата от думи
char * mostCommonWord(char sequence[10][MAX_SIZE], int size)
{
    char * word = new char [MAX_SIZE];
    int counter = 0;
    int maxCounter = 0;

    for (int i = 0; i < size ; ++i) {
        char * tempWord = new char [MAX_SIZE];
        for (int j = 0; j < length(sequence[i]); ++j) {
            tempWord[j] = sequence[i][j];
        }
        for (int j = i; j < size; ++j) {
            if(myStrCompare(tempWord, sequence[i]) == 0)
                counter++;
        }
        if(counter > maxCounter)
        {
            maxCounter = counter;
            for (int j = 0; j < length(sequence[i]); ++j) {
                word[j] = tempWord[j];
            }
            word[length(sequence[i])] = '\0';
        }
        tempWord = nullptr;
        delete[] tempWord;
    }
    return word;
}
int main()
{
    char arrayOfWords[10][MAX_SIZE];
    int size;

    std::cout<<"Enter the number of words in the sequence:";
    std::cin>>size;

    if(size > 9)
    {
        std::cerr<<"The size must not be greater than 9!";
        return -1;
    }

    for (int i = 0; i < size; ++i) {
        std::cin>>arrayOfWords[i];
    }
    char * ptrToMostCommonWord = mostCommonWord(arrayOfWords, size);
    std::cout<<ptrToMostCommonWord<<std::endl;

    ptrToMostCommonWord = nullptr;
    delete[] ptrToMostCommonWord;

    return 0;

}