#include <iostream>
#include <cstring>

const int MAX_SIZE_TEXT = 1024;
const int MAX_SIZE_DICTIONARY = 128;
const int MAX_SIZE_WORD = 100;

unsigned length(const char number[])
{

    unsigned i = 0;
    while(number[i])
    {
        i++;
    }
    return i;
}
char * autoCorrect(char * text, char ** dictionary, int numberOfWordsInDictionary)
{
    char * correctedText = new char [MAX_SIZE_TEXT * 2];


}
int main()
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
        std::cin.getline(line,numberOfCharacters - enteredCharacters);
        strcat_s(text, "\n");
        strcat_s(text,line);
        enteredCharacters = length(text);
    }


    int numberOfWordsInsideDictionary;
    std::cout<<"Enter number of words in dictionary:";
    std::cin>>numberOfWordsInsideDictionary;

    char dictionary[MAX_SIZE_DICTIONARY][MAX_SIZE_WORD];

    for (int i = 0; i < numberOfWordsInsideDictionary; ++i) {
        std::cin.getline(dictionary[i], MAX_SIZE_WORD);
    }
    for (int i = 0; i < numberOfWordsInsideDictionary; ++i) {
        std::cout<<dictionary[i]<<std::endl;
    }


    return 0;
}
void transformMatrix(int ** &A, int ** &B, int &N1, int &M1, int N2, int M2)
{
    if(N1 > N2)
    {
        for (int i = N2; i < N1; ++i) {
            delete[] A[i];
            A[i] = nullptr;
        }
        N1 = N2;
    }
    if(M1 > M2)
    {
       int ** matrixLessColumns = new int *[N1];
        for (int i = 0; i < N1; ++i) {
            matrixLessColumns[i] = new int [M2];
            for (int j = 0; j < M2; ++j) {
                matrixLessColumns[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < N1; ++i) {
            delete [] A[i];
        }
        delete[] A;
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
        return chr - 'a' + 10;
    else if(chr >= 'A' && chr <= 'Z')
        return chr - 'A' + 10;
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

    int flag = 0;
    int currentIndex = 0;
    int occupiedIndex = 0;

    int currSum = 0;
    if(isBigger)
    {
        while(number1[currentIndex])
        {
            currSum = parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]);
            if(currSum + flag >= k)
            {
                if(currSum - k + flag >= 10)
                    result[occupiedIndex++] = parseChar(currSum - k + flag);
                else
                    result[occupiedIndex++] =  toChar(currSum - k + flag);
                flag = 1;
            }
            else
            {
                if(currSum + flag >= 10)
                    result[occupiedIndex++] = parseChar(currSum  + flag);
                else
                    result[occupiedIndex++] = toChar(currSum  + flag);
                flag = 0;
            }
            currentIndex++;
        }
    }

    else
    {
        while(number2[currentIndex])
        {
            currSum = parseNumber(number1[currentIndex]) + parseNumber(number2[currentIndex]);
            if(currSum + flag >= k)
            {
                if(currSum - k + flag >= 10)
                    result[occupiedIndex++] = parseChar(currSum - k + flag);
                else
                    result[occupiedIndex++] =  toChar(currSum - k + flag);
                flag = 1;
            }
            else
            {
                if(currSum + flag >= 10)
                    result[occupiedIndex++] = parseChar(currSum + flag);
                else
                    result[occupiedIndex++] = toChar(currSum + flag);
                flag = 0;
            }
            currentIndex++;
        }

    }

    //ако е останал флаг 1 го прибавяме към стринга
    if(flag == 1)
    {
        result[occupiedIndex++] = toChar(flag);
    }
    //слагаме последния символ
    result[occupiedIndex++] = '\0';
    reverse(result);

    return result;

}
int main2_TERC()
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