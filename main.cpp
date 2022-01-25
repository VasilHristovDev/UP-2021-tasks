#include <iostream>
#include <cstring>

const int MAX_SIZE_SENTENCE = 100;

int main()
{
    char word[MAX_SIZE_SENTENCE];
    std::cin>>word;

    unsigned length = strlen(word);
    int currentCharacter = 0;

    char encodedWord[MAX_SIZE_SENTENCE];
    int countChars = 0;

    while(word[currentCharacter])
    {
        if(word[currentCharacter] != 'a' && word[currentCharacter] != 'b' && word[currentCharacter] != 'c')
        {
            std::cerr<<"The word must contain only a, b and c!"<<std::endl;
            return -1;
        }
        currentCharacter++;
    }
    currentCharacter = 0;
    int count = 0;
    while (word[currentCharacter])
    {
        encodedWord[countChars++] = word[currentCharacter];
        count = 0;
        while(word[currentCharacter] == encodedWord[countChars - 1])
        {
            count++;
            currentCharacter++;
        }
        encodedWord[countChars++] = count + '0';
    }
    encodedWord[countChars] = '\0';
    bool error = false;

    if(encodedWord[0] != 'a' && encodedWord[0] != 'b')
        error = true;
    if(encodedWord[countChars - 2] != 'c' && encodedWord[countChars - 2] != 'b')
        error = true;

    int tempIterator = 0;
    int tempCounter = 0;
    while(encodedWord[tempIterator])
    {
        if(encodedWord[tempIterator] == 'a' || encodedWord[tempIterator] == 'b' || encodedWord[tempIterator] == 'c')
        {
            tempCounter++;
        }
        tempIterator++;
    }
    if(tempCounter > 3)
        error = true;
    std::cout<<(!error ? "It is correct" : "It is not correct")<<std::endl;
    return 0;
}