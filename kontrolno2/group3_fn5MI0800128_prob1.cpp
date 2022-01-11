#include <iostream>
const int MAX_SIZE = 100;
unsigned myStrLen (const char str[])
{
    unsigned i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int myStrCompare(char str1[], char str2[])
{
    unsigned i = 0;
    while(myStrLen(str1) > myStrLen(str2) ? str1[i] : str2[i])
    {
        if(str1[i] > str2[i])
        {
            return 1;
        }
        else if (str2[i] > str1[i])
        {
            return -1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
bool isSubArray (const char text[], char str[], int &currentIndex)
{
    int indexText = 0;
    int indexStr = 0;
    int counter = 0;
    while(text[indexText])
    {
        counter = 0;
        for (int i = indexText; i < indexText + myStrLen(str) ; ++i) {
            if(text[i] == str[indexStr++])
                counter++;
        }
        if(counter == myStrLen(str))
        {
            currentIndex = indexText;
            return true;
        }
        else
        {
            indexText++;
            indexStr = 0;
        }
    }
    return false;
}
char * minWord (const char text[])
{
    char * lexicographicallySmallest = new char [MAX_SIZE];
    char words[MAX_SIZE][MAX_SIZE];
    char tempWord[MAX_SIZE];

    int currentChar = 0;
    int occupiedWords = 0;
    int occupiedChar = 0;
    while (text[currentChar])
    {
        if((text[currentChar] >= 'a' && text[currentChar] <= 'z' ) || (text[currentChar] >= 'A' && text[currentChar] <= 'Z') || (text[currentChar] >= '0' && text[currentChar] <= '9'))
        {
            words[occupiedWords][occupiedChar++] = text[currentChar];
        }
        else
        {
            words[occupiedWords][occupiedChar++] = '\0';
            occupiedChar = 0;
            occupiedWords++;
        }
        currentChar++;
    }


    for (int i = 0; i < occupiedWords ; ++i) {
        for (int j = i + 1; j < occupiedWords ; ++j) {
            if(myStrCompare(words[i],words[j]) == 1)
            {
                for (int k = 0; k < myStrLen(words[j]) ; ++k) {
                    tempWord[k] = words[j][k];
                }
                tempWord[myStrLen(words[j])] = '\0';
            }
            else if (myStrCompare(words[i], words[j]) == -1)
            {
                for (int k = 0; k < myStrLen(words[i]) ; ++k) {
                    tempWord[k] = words[i][k];
                }
                tempWord[myStrLen(words[i])] = '\0';
            }
        }
    }
    currentChar = 0;
    occupiedChar = 0;
    int startingIndex = 0;
    if(isSubArray(text, tempWord, startingIndex))
    {
        while(text[startingIndex])
        {
            lexicographicallySmallest[occupiedChar++] = text[startingIndex++];
        }
    }
    lexicographicallySmallest[occupiedChar++] = '\0';

    return lexicographicallySmallest;
}
int main()
{
    char text[MAX_SIZE];

    std::cout<<"Enter text:";
    std::cin.getline(text, MAX_SIZE);


    char * ptrToMinWord = minWord(text);

    std::cout<<ptrToMinWord<<std::endl;

    delete [] ptrToMinWord;
    ptrToMinWord = nullptr;


    return 0;

}