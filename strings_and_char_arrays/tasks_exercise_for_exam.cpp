#include <iostream>
#include <cstring>
#include <assert.h>

const int MAX_SIZE_SENTENCE = 100;

int countWordsInSentence(const char * sentence)
{
    int i = 0;
    int counter = 0;
    while(sentence[i])
    {
        if (sentence[i] == ' ')
            counter++;
        i++;
    }
    return counter + 1;
}
char * getLongestWord(char sentence[], int n)
{
    char ** wordsInSentence = new char * [countWordsInSentence(sentence)];
    int i = 0;
    int occupiedCharacters = 0;
    int occupiedWords = 0;

    wordsInSentence[occupiedWords] = new char [MAX_SIZE_SENTENCE];
    while(sentence[i])
    {
        wordsInSentence[occupiedWords][occupiedCharacters++] = sentence[i];
        if(sentence[i + 1 ] == ' ')
        {
            wordsInSentence[occupiedWords][occupiedCharacters] = '\0';
            occupiedWords++;
            wordsInSentence[occupiedWords] = new char [MAX_SIZE_SENTENCE];
            occupiedCharacters = 0;
            i++;
        }
        i++;
    }

    int maxCount = 0;
    int jMax = 0;
    for (int j = 0; j < occupiedWords ; ++j) {
        if(maxCount < strlen(wordsInSentence[j]))
        {
            maxCount = strlen(wordsInSentence[j]);
            jMax = j;
        }
    }
    for (int j = 0; j < countWordsInSentence(sentence); ++j) {
        if(j != jMax)
            delete [] wordsInSentence[j];
    }
    return wordsInSentence[jMax];
}

int main1()
{
    int n;
    char sentence[MAX_SIZE_SENTENCE];
    std::cout<<"Enter n:";
    std::cin>>n;
    std::cin.ignore();
    std::cin.getline(sentence,n);
    sentence[n] = '\0';
    char * ptrToLongestWord = getLongestWord(sentence,n);

    std::cout<<ptrToLongestWord<<std::endl;
    delete [] ptrToLongestWord;
    return 0;
}
char * reverse (char * word)
{
    char * reversedWord = new char [strlen(word)];

    for (int i = 0; i < strlen(word); ++i) {
        reversedWord[i] = word[strlen(word) - i - 1];
    }
    reversedWord[strlen(word)] = '\0';
    return reversedWord;
}
int timesWordIsSeenInSentence(const char * sentence, char * reversedWord)
{
    int i = 0;
    int counterWord = 0;
    int counterSameCharacters = 0;
    int timesWordIsSeen = 0 ;
    while(sentence[i])
    {
        for (int j = i; j < i + strlen(reversedWord); ++j) {
            if(sentence[j] == reversedWord[counterWord++])
            {
                counterSameCharacters++;
            }
        }
        if(counterSameCharacters == strlen(reversedWord))
        {
            timesWordIsSeen++;
        }
        counterSameCharacters = 0;
        counterWord = 0;
        i++;
    }
    return timesWordIsSeen;
}

int main2()
{
    int n,m;
    char sentence[MAX_SIZE_SENTENCE];
    char word[MAX_SIZE_SENTENCE];
    std::cout<<"Enter size of sentence and size of word:";
    std::cin>>n>>m;

    std::cout<<"Enter word:";
    std::cin>>word;

    std::cin.ignore();
    std::cout<<"Enter sentence:";
    std::cin.getline(sentence,n);
    std::cout<<std::endl;
    if(timesWordIsSeenInSentence(sentence, reverse(word)) > 0)
    {
        std::cout<<"Word is seen "<<timesWordIsSeenInSentence(sentence, reverse(word))<<"times"<<std::endl;
    }
    else
    {
        std::cout<<"Word is not seen in sentence!"<<std::endl;
    }
    return 0;
}


void diagonalOrder(char ** matrix, int n, int m) {
    for (int k = m - 1; k > 0; k--) {
        int i = n - 1;
        int j = k;

        while (i > 0  && j < m) {
            std::cout << matrix[i][j];
            i--;
            j++;
        }
        std::cout<<" ";
    }
    for (int k = n - 1; k >= 0; k--) {
        int i = k;
        int j = 0;

        while (i >= 0  && j < m ) {
            std::cout << matrix[i][j];
            i--;
            j++;
        }
        std::cout<<" ";

    }

}

int main3()
{
    int n;
    int m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    char ** matrix = new char * [n];

    for (int i = 0; i <n ; ++i) {
        matrix[i] = new char [m];
        for (int j = 0; j <m ; ++j) {
            std::cin>>matrix[i][j];
        }
    }

    diagonalOrder(matrix,n,m);
    for (int i = 0; i <n ; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}
int main4()
{
    int n,m;
    std::cout<<"Enter size n and m:";
    std::cin>>n>>m;
    int ** matrix = new int * [n];

    for (int i = 0; i < n ; ++i) {
        matrix[i] = new int [m];
        for (int j = 0; j < m ; ++j) {
            std::cin>>matrix[i][j];
        }
    }
    int minElement = matrix[0][0];
    int minI = 0;
    int minJ = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j] < minElement)
            {
                minElement = matrix[i][j];
                minI = i;
                minJ = j;
            }
        }
    }
    int ** resultMatrix = new int * [n -1];
    int occupiedRows = 0;
    int occupiedElements = 0;
    for (int i = 0; i < n; ++i) {
        occupiedElements = 0;
        if(i != minI)
        {
            resultMatrix[occupiedRows] = new int [m - 1];
            for (int j = 0; j < m ; ++j) {
                if(j != minJ)
                {
                    resultMatrix[occupiedRows][occupiedElements++] = matrix[i][j];
                }
            }
            occupiedRows++;
        }
    }
    for (int i = 0; i < n ; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = resultMatrix;

    for (int i = 0; i < n - 1 ; ++i) {
        for (int j = 0; j < m - 1 ; ++j) {
            std::cout<<resultMatrix[i][j]<<" ";
        }
        std::cout<<std::endl;
        delete [] resultMatrix[i];
    }
    delete [] resultMatrix;

    return 0;

}

bool hasQueen(char ** field, int n, int m, int row, int col)
{
    for (int i = 0; i < n; i++) {
        if (i != row && field[i][col] == 'O')
            return true;
    }

    for (int i = 0; i < m; i++) {
        if (i != col && field[row][i] == 'O')
            return true;
    }

    for (int i = 1; row - i >= 0 && col - i >= 0; i++) {
        if (field[row - i][col - i] == 'O')
            return true;
    }

    for (int i = 1; row + i < n && col + i < m; i++) {
        if (field[row + i][col + i] == 'O')
            return true;
    }

    for (int i = 1; row - i >= 0 && col + i < m; i++) {
        if (field[row - i][col + i] == 'O')
            return true;
    }

    for (int i = 1; row + i < n && col - i >= 0; i++) {
        if (field[row + i][col - i] == 'O')
            return true;
    }

    return false;
}
int main5()
{
    int n,m;
    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    char ** field = new char * [n];

    for (int i = 0; i < n; ++i) {
        field[i] = new char [m];
        for (int j = 0; j <m ; ++j) {
            std::cin>>field[i][j];
        }
    }
    int i = 0;
    int j = 0;
    while(field[i][j]!='O' && i < n )
    {
        if(j == m - 1)
        {
            j = 0;
            i++;
        }
        j++;
    }
    bool isSafe = hasQueen(field,n,m,i,j);
    std::cout<<isSafe<<std::endl;
    for (int k = 0; k < n ; ++k) {
        delete [] field[i];
        field[i] = nullptr;
    }
    delete [] field;
    field = nullptr;
    return 0;
}

void countTimesWordIsSeen(char * sentence, char * word)
{
    std::cout<<word<<" : ";
    int currentCharSentence = 0;
    int currentCharacterWord = 0;
    int counterIsSubArray = 0;
    int tempCounter = 0;
    while(sentence[currentCharSentence] && currentCharSentence + strlen(word) <= strlen(sentence) )
    {
        for (int i = currentCharSentence; i < currentCharSentence + strlen(word); ++i) {
            if(sentence[i] == word[currentCharacterWord++])
                tempCounter++;
        }
        if(tempCounter == strlen(word))
            counterIsSubArray++;
        currentCharacterWord = 0;
        tempCounter = 0;
        currentCharSentence++;
    }
    std::cout<<counterIsSubArray<<std::endl;
}
int main6()
{
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    char * sentence = new char [n + 1];

    std::cin.ignore();
    std::cin.getline(sentence, n);

    char ** wordsArray = new char * [countWordsInSentence(sentence)];
    for (int i = 0; i < countWordsInSentence(sentence); ++i) {
        wordsArray[i] = new char [n];
    }
    int wordsInSentence =  countWordsInSentence(sentence);
    int occupiedWords = 0;
    int occupiedCharacters = 0;
    int currentCharacter = 0;
    while(sentence[currentCharacter])
    {
        wordsArray[occupiedWords][occupiedCharacters++] = sentence[currentCharacter];
        if(sentence[currentCharacter + 1] == ' ' )
        {
            wordsArray[occupiedWords][occupiedCharacters] = '\0';
            occupiedWords++;
            occupiedCharacters = 0;
            currentCharacter++;
        }
        currentCharacter++;
    }
    wordsArray[occupiedWords][occupiedCharacters] = '\0';
    int helper = 0;
    for (int i = 0; i < wordsInSentence ; ++i) {
        for (int j = i - 1; j >= 0 ; --j) {
            if(strcmp(wordsArray[i], wordsArray[j]) != 0)
                helper++;
        }
        if(helper == i)
            countTimesWordIsSeen(sentence,wordsArray[i]);
        helper = 0;
    }


    for (int i = 0; i < wordsInSentence; ++i) {
        delete [] wordsArray[i];
        wordsArray[i] = nullptr;
    }
    delete [] wordsArray;
    wordsArray = nullptr;

    return 0;

}
void  removeMostCommonWord( char *& sentence, char * word)
{
    char * resultSentence = new char [MAX_SIZE_SENTENCE];
    int currentChar = 0;
    int occupiedChar = 0;
    int tempCounter = 0;
    int tempIndex = 0;
    while(sentence[currentChar])
    {
        for (int i = currentChar; i < currentChar + strlen(word) ; ++i) {
            if(sentence[i] == word[tempIndex++])
                tempCounter++;
        }
        if(tempCounter == strlen(word))
        {
            currentChar+= strlen(word);
        }
        else
        {
            resultSentence[occupiedChar++] = sentence[currentChar++];
        }
        tempCounter = 0;
        tempIndex = 0;
    }
    resultSentence[occupiedChar++] = '\0';
    delete [] sentence;
    sentence = resultSentence;
}
int main()
{
    int n ;
    std::cout<<"Enter n:";
    std::cin>>n;

    char * sentence = new char [n + 1];

    std::cin.ignore();
    std::cin.getline(sentence, n);

    char ** wordsInSentence = new char * [countWordsInSentence(sentence)];

    for (int i = 0; i < countWordsInSentence(sentence); ++i) {
        wordsInSentence[i] = new char [n + 1];
    }
    int currentCharacter = 0;
    int occupiedWords = 0;
    int occupiedCharacters = 0;
    while(sentence[currentCharacter])
    {
        wordsInSentence[occupiedWords][occupiedCharacters++] = sentence[currentCharacter];
        if(sentence[currentCharacter + 1] == ' ' )
        {
            wordsInSentence[occupiedWords][occupiedCharacters] = '\0';
            occupiedWords++;
            occupiedCharacters = 0;
            currentCharacter++;
        }
        currentCharacter++;
    }
    wordsInSentence[occupiedWords][occupiedCharacters] = '\0';

    int maxCountWord = 0;
    int count = 0;
    int maxIndex = 0;
    for (int i = 0; i < occupiedWords; ++i) {
        for (int j = i + 1; j < occupiedWords; ++j) {
            if(strcmp(wordsInSentence[i], wordsInSentence[j]) == 0)
                count++;
        }
        if(count > maxCountWord) {
            maxCountWord = count;
            maxIndex = i;
        }
    }
    removeMostCommonWord(sentence,wordsInSentence[maxIndex]);

    std::cout<<sentence<<std::endl;

    for (int i = 0; i < countWordsInSentence(sentence) ; ++i) {
        delete [] wordsInSentence[i];
        wordsInSentence[i] = nullptr;
    }
    delete [] wordsInSentence;
    wordsInSentence = nullptr;

    delete [] sentence;
    sentence = nullptr;

    return 0;



}