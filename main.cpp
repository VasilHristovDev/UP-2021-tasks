#include <iostream>
#include <cstring>

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

int main()
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