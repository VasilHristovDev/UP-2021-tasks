#include <iostream>
#include <cstring>

const int MAX_SIZE_TEXT = 1024;
const int MAX_SIZE_DICTIONARY = 128;
const int MAX_SIZE_WORD = 100;

//дължина на стринг
int length(const char number[])
{

    int i = 0;
    while(number[i])
    {
        i++;
    }
    return i;
}

//Проверка дали сгрешената дума се съдържа в следващите length(word) позиции
//и дали следващия символ е различен от буква
bool containsFromCurrentPosition(const char * text, char * word, int currentIndex)
{
    int wordIndex = 0;
    int counter = 0;
    for (int i = currentIndex; i < currentIndex + length(word); ++i) {
        if(text[i] == word[wordIndex++])
            counter++;
        else
            return false;
    }
    return counter == length(word) && (text[currentIndex + length(word)] == ' ' || text[currentIndex + length(word)] == '.' &&
            !(text[currentIndex + length(word)] >= 'A' && text[currentIndex + length(word)] <= 'Z') &&
            !(text[currentIndex + length(word)] >= 'z' && text[currentIndex + length(word)] <= 'z'));
}

// функцията връща масив с всички позиции на двойни кавички
int * quotationMarksPositionsInText(const char * text, int &count)
{
    for (int i = 0; i < length(text) ; ++i) {
        if(text[i] == '"')
        {
            count++;
        }

    }
    int * positions = new int [count + 1];
    int occupied = 0;
    for (int i = 0; i < length(text); ++i) {
        if(text[i] == '"')
        {
            positions[occupied++] = i;
        }
    }

    return positions;
}

//проверка дали кавичката е отваряща
bool isOnOddPosition(const int * positions, int position, int count)
{
    int pos;
    for (int i = 0; i < count; ++i) {
        if(positions[i] == position)
            pos = i;
    }
    return pos % 2 == 0;
}

char * autoCorrect(const char * text, char  dictionary[MAX_SIZE_DICTIONARY][MAX_SIZE_WORD], int numberOfWordsInDictionary)
{
    char * correctedText = new char [MAX_SIZE_TEXT * 2];
    int currentChar = 0;
    int occupiedChar = 0;
    int countOfQuotationMarks = 0;
    int * ptrToPositionsOfQuotationMarks = quotationMarksPositionsInText(text, countOfQuotationMarks);
    char wrongWord[MAX_SIZE_WORD];
    char correctedWord[MAX_SIZE_WORD];

    while(currentChar <= length(text))
    {

        for (int i = 0; i < numberOfWordsInDictionary; ++i) {
            int tempIndex = 0;
            int tempCorrectedIndex = 0;
            while(dictionary[i][tempIndex] != '-')
            {
                wrongWord[tempIndex] = dictionary[i][tempIndex];
                tempIndex++;
            }
            wrongWord[tempIndex++] = '\0';
            if(containsFromCurrentPosition(text,wrongWord, currentChar))
            {
                while(dictionary[i][tempIndex] != '\0')
                {
                    correctedWord[tempCorrectedIndex++] = dictionary[i][tempIndex++];
                }
                correctedWord[tempCorrectedIndex++] = '\0';
                tempCorrectedIndex = 0;
                for (int j = occupiedChar; j < occupiedChar + length(correctedWord); ++j) {
                    correctedText[j] = correctedWord[tempCorrectedIndex++];
                }
                occupiedChar+= length(correctedWord) - 1;
                currentChar+= length(wrongWord) - 1;
            }
        }
        if((text[currentChar] !=' ') && (text[currentChar + 1] == '+' ||
            text[currentChar + 1] == '-' || text[currentChar + 1] == '=' ||
            text[currentChar] == '*' || text[currentChar + 1] == '(' ||
            (text[currentChar + 1] == '"' && isOnOddPosition(ptrToPositionsOfQuotationMarks, currentChar + 1, countOfQuotationMarks))||
            (text[currentChar] == ',' || text[currentChar] == '.' || text[currentChar] == '!' || text[currentChar] == '?' ||
            text[currentChar] == ';' || text[currentChar] == ':') && text[currentChar+1] != ' ' && text[currentChar+1] != '\n'))
        {
            correctedText[occupiedChar++] = text[currentChar];
            correctedText[occupiedChar++] = ' ';
        }
        else if((text[currentChar] != '.') && (text[currentChar + 1] == '\n' || text[currentChar + 1] == '\0'))
        {
            correctedText[occupiedChar++] = '.';
            correctedText[occupiedChar++] = text[currentChar];
        }
        else
        {
            correctedText[occupiedChar++] = text[currentChar];
        }
        currentChar++;

    }
    correctedText[occupiedChar++] = '\0';
    delete [] ptrToPositionsOfQuotationMarks;
    ptrToPositionsOfQuotationMarks = nullptr;

    return correctedText;
}
int main0()
{
    char text[MAX_SIZE_TEXT];
    int numberOfCharacters;

    std::cout<<"Enter number of characters in text:";
    std::cin>>numberOfCharacters;

    char line[MAX_SIZE_TEXT];
    unsigned enteredCharacters = 0;
    text[0] = '\0';

    std::cout<<"Enter text:";

    std::cin.ignore();
    while(enteredCharacters < numberOfCharacters)
    {
        std::cin.getline(line,numberOfCharacters - enteredCharacters + 1);
        strcat_s(text, "\n");
        strcat_s(text,line);
        enteredCharacters = length(text);
    }


    int numberOfWordsInsideDictionary;
    std::cout<<"Enter number of words in dictionary:";
    std::cin>>numberOfWordsInsideDictionary;

    char dictionary[MAX_SIZE_DICTIONARY][MAX_SIZE_WORD];
    std::cin.ignore();
    for (int i = 0; i < numberOfWordsInsideDictionary; ++i) {
        std::cin.getline(dictionary[i], MAX_SIZE_WORD);
    }

    char * ptrToCorrectedText = autoCorrect(text, dictionary, numberOfWordsInsideDictionary);
    for (int i = 0; i < length(ptrToCorrectedText); ++i) {
        std::cout<<ptrToCorrectedText[i];
    }

    delete [] ptrToCorrectedText;
    ptrToCorrectedText = nullptr;


    return 0;
}


void transformMatrix(int ** &A, int ** &B, int &N1, int &M1, int N2, int M2)
{
    if(N1 > N2)
    {
        //изтриваме редовете от N2 до N1
        for (int i = N2; i < N1; ++i) {
            delete[] A[i];
            A[i] = nullptr;
        }
        N1 = N2;
    }
    if(M1 > M2)
    {
        //Заделяме нова матрица с по-малко колони
       int ** matrixLessColumns = new int *[N1];
        for (int i = 0; i < N1; ++i) {
            matrixLessColumns[i] = new int [M2];
            for (int j = 0; j < M2; ++j) {
                matrixLessColumns[i][j] = A[i][j];
            }
        }
        //Изтриваме старата
        for (int i = 0; i < N1; ++i) {
            delete [] A[i];
        }
        delete[] A;
        //Подаваме и указател към новата
        A = matrixLessColumns;
        M1 = M2;

    }
    for (int i = 0; i < N1 ; ++i) {
        for (int j = 0; j < M1; ++j) {
            if(A[i][j] > B[i][j])
            {
                A[i][j] = -A[i][j];
            }
            else if(A[i][j] < B[i][j])
            {
                A[i][j] = B[i][j];
            }
        }
    }

}
int main2()
{
    int n1,n2;
    int m1,m2;
    std::cout<<"Enter the sizes of the first matrix (nxm):";
    std::cin>>n1>>m1;

    int ** matrix1 = new int * [n1];
    std::cout<<"Enter the first matrix:"<<std::endl;

    for (int i = 0; i < n1; ++i) {
        matrix1[i] = new int [m1];
        for (int j = 0; j < m1; ++j) {
            std::cin>>matrix1[i][j];
        }
    }

    std::cout<<"Enter the sizes of the second matrix (n x m):";
    std::cin>>n2>>m2;

    int ** matrix2 = new int* [n2];
    std::cout<<"Enter the second matrix:"<<std::endl;

    for (int i = 0; i < n2; ++i) {
        matrix2[i] = new int [m2];
        for (int j = 0; j < m2; ++j) {
            std::cin>>matrix2[i][j];
        }
    }
    transformMatrix(matrix1,matrix2,n1,m1,n2,m2);

    std::cout<<std::endl;
    for (int i = 0; i < n1 ; ++i) {
        for (int j = 0; j < m1; ++j) {
            std::cout<<matrix1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    //изчистваме заделената памет:
    for (int i = 0; i < n1; ++i) {
        delete [] matrix1[i];
        matrix1[i] = nullptr;
    }
    delete [] matrix1;
    matrix1 = nullptr;

    for (int i = 0; i < n2; ++i) {
        delete[] matrix2[i];
        matrix2[i] = nullptr;
    }
    delete [] matrix2;
    matrix2 = nullptr;

    return 0;
}

const int MAX_SIZE = 100;
const int MIN_LENGTH_FOR_LETTER = 10;
// дължина на стринг

//обръщане на стринг
void reverse(char * &str)
{
    char helper[MAX_SIZE];
    for (int i = 0; i < length(str) ; ++i) {
        helper[i] = str[i];
    }
    for (int i = 0; i < length(str) ; ++i) {
        str[i] = helper[length(str) - i - 1];
    }
}

int parseNumber(char chr)
{
    if( chr >= '0' && chr <= '9')
        return chr - '0';
    else if(chr >= 'a' && chr <= 'z')
        return chr - 'a' + MIN_LENGTH_FOR_LETTER;
    else if(chr >= 'A' && chr <= 'Z')
        return chr - 'A' + MIN_LENGTH_FOR_LETTER;
    else
        return 0;
}
//ако има число по-голямо или равно на 10 да се превърне в буква
char parseChar(int num)
{
    return (char)(num - 10 + 'A');
}
//parse
char toChar(int number)
{
    return char(number + '0');
}

char * calculateStr(char number1[],char number2[], int k)
{
    char * result = new char [MAX_SIZE];

    //обръщаме двата стринга и започваме да събираме елементите по индекси
    reverse(number1);
    reverse(number2);

    bool isBigger = length(number1) > length(number2);

    int remainder = 0;
    int currentIndex = 0;
    int occupiedIndex = 0;

    int currSum = 0;
    while(isBigger? number1[currentIndex] : number2[currentIndex])
    {
        currSum = parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]);
        //Ако сумата е по-голяма от системата, в която се намираме
        if(currSum + remainder >= k)
        {
            //Ако се намираме в бройна система по-голяма от десетичната, записваме съответната буква
            if(currSum - k + remainder >= MIN_LENGTH_FOR_LETTER)
                result[occupiedIndex++] = parseChar(currSum - k + remainder);
            else
                result[occupiedIndex++] =  toChar(currSum - k + remainder);
            remainder = 1;
        }
        else
        {
            if(currSum + remainder >= MIN_LENGTH_FOR_LETTER)
                result[occupiedIndex++] = parseChar(currSum  + remainder);
            else
                result[occupiedIndex++] = toChar(currSum  + remainder);
            remainder = 0;
        }
        currentIndex++;
    }



    //ако е останал остатък 1 го прибавяме към стринга
    if(remainder == 1)
    {
        result[occupiedIndex++] = toChar(remainder);
    }
    //слагаме последния символ
    result[occupiedIndex++] = '\0';
    reverse(result);

    return result;

}
int main()
{
    char number1[MAX_SIZE], number2[MAX_SIZE];
    std::cout<<"Enter number 1:";
    std::cin>>number1;

    std::cout<<"Enter number 2:";
    std::cin>>number2;

    int k;
    std::cout<<"Enter the numeric system:";
    std::cin>>k;
    //валидация
    if(k < 2 || k > 36)
    {
        std::cerr<<"Enter a valid numeric system!";
        return -1;
    }
    int tempIndex = 0;

    //проверка дали има символи непринадлежащи на бройната  система
    while(number1[tempIndex])
    {
        if(parseNumber(number1[tempIndex]) >= k)
        {
            std::cerr<<"Bad input data!";
            return -1;
        }
        tempIndex++;
    }
    tempIndex = 0;

    while(number2[tempIndex])
    {
        if(parseNumber(number2[tempIndex]) >= k)
        {
            std::cerr<<"Bad input data!";
            return -1;
        }
        tempIndex++;
    }

   char * ptrToResult = calculateStr(number1, number2,k);
   std::cout<<ptrToResult<<std::endl;
   delete [] ptrToResult;
   ptrToResult = nullptr;

   return 0;
}