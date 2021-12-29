#include <iostream>
const int MAX_SIZE = 100;
int * read (int a[], int n)
{
    int * begin = a;
    int * end = a + n;

    for (int* current = a; current < end ; current++) {
        std::cin>>*current;
    }
    return a;
}
//прочита масив и го връща като резултат от изпълнението на функцията
int main0a()
{
    int a[MAX_SIZE];
    int n;
    std::cout<<"Enter the size of the array:";
    std::cin>>n;
    int * ptrToA = read(a, n);
    for (int i = 0; i < n ; ++i) {
        std::cout<<*(ptrToA + i)<<" ";
    }
    //използваме delete само при алокиране на динамична памет с new или new[]
    return 0;
}
int ** readMatrix(int a[][MAX_SIZE], int N, int M)
{
    int ** matrix = new int *[N];

    for (int i = 0; i < N ; ++i) {
        matrix[i] = new int [M];
        for (int j = 0; j < M ; ++j) {
            std::cout << "matrix[" << i << "][" << j << "]:";
            std::cin>>*(*(matrix + i) + j);
        }
    }
    return matrix;

}
//прочита двумерен масив и го връща като резултат от изпълнението на функцията
int main0b()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int N, M;
    std::cout<<"Enter the size of N and M:";
    std::cin>>N>>M;

    int ** ptrTo2D = readMatrix(array2D,N,M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout<<*(*(ptrTo2D + i) + j)<<" ";
        }
        std::cout<<std::endl;
    }

    delete[] ptrTo2D;
    return 0;

}
void print2DArray( int ** arr, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout<<*(*(arr + i) + j)<<" ";
        }
        std::cout<<std::endl;
    }
}
//приема двумерен масив като аргумент на функцията и го извежда на конзолата
int main0c()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int n,m;
    std::cout<<"Enter the size of n and m:";
    std::cin>>n>>m;

    int **ptrTo2D = readMatrix(array2D, n,m);
    print2DArray(ptrTo2D, n,m);

    delete[] ptrTo2D;
    return 0;
}

int * doubleSize(int *& array, int size)
{
    int* newArr = new int [size * 2];
    for (int i = 0; i < size ; ++i) {
        newArr[i] = array[i];
    }
    delete[] array;
    array = newArr;

    return array;
}
//Да се напише функция, която преоразмерява масив като новия размер е 2 пъти по-голям
int main1()
{
    int n;

    std::cout<<"Enter the size of the array:";
    std::cin>>n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }
    int* ptrToArr = array;
    ptrToArr = doubleSize(ptrToArr, n);
    for (int i = 0; i < n  ; ++i) {
        std::cout<<ptrToArr[i]<<" ";
    }
    delete [] ptrToArr;
    return 0;
}
int * findLargestAscendingSequence(const int * array, int size, int &sizeOfSequence)
{
    int * largestSequence = new int [size];
    int counter = 0;
    int maxCounter = 0;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < size; ++i) {
        if(*(array + i) <= *(array + i + 1))
        {
            counter++;
        }
        else
        {
            if(maxCounter < counter)
            {
                maxCounter = counter;
                endIndex = i;
                startIndex = endIndex - counter;
            }
            counter = 0;
        }
    }

    if(maxCounter!=0)
    {
        int tempIndexHelper = 0;
        for (int i = startIndex; i <= endIndex ; ++i) {
            *(largestSequence + tempIndexHelper++) = *(array + i);
        }
        sizeOfSequence = endIndex - startIndex + 1;
    }
    return largestSequence;
}
//Да се напише функция, която приема масив от числа и връща като резултат най-голямата монотонно растяща подредица
int main2()
{
    int array[MAX_SIZE];
    int n;
    std::cout<<"Enter the size of the array:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }
    int newSize = 0;
    int* ptrToArr = findLargestAscendingSequence(array,n, newSize);

    for (int i = 0; i < newSize; ++i) {
        std::cout<<*(ptrToArr + i)<<" ";
    }
    delete[] ptrToArr;
    return 0;
}
int ** transpose(const int array2D[][MAX_SIZE], int N, int M)
{
    int ** matrix = new int *[M];

    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            *(*(matrix + i) + j) = *(*(array2D + j) + i);
        }
    }
    return matrix;
}
//Да се напише функция, която приема двумерен масив NxM като аргумент
//и връща транспонираната матрица с размер MxN като резултат от изпълнението на функцията
int main3()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int N,M;
    std::cout<<"Enter N and M";
    std::cin>>N>>M;

    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < M ; ++j) {
            std::cout<<"array["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }
    int ** transposedMatrix = transpose(array2D, N, M);
    for (int i = 0; i < M ; ++i) {
        for (int j = 0; j < N ; ++j) {
            std::cout<<*(*(transposedMatrix + i) + j)<<" ";
        }
        std::cout<<std::endl;
    }
    delete[] transposedMatrix;
    return 0;
}
char * transformSentence( char arrayWords[][MAX_SIZE], int numberOfWords)
{
    char * concatenatedString = new char [MAX_SIZE * MAX_SIZE];
    int lastIndex = 0;
    for (int i = 0; i < numberOfWords ; ++i) {
        int j = 0;
       while(arrayWords[i][j])
       {
           concatenatedString[lastIndex++] = arrayWords[i][j++];
       }
       concatenatedString[lastIndex++] = ' ';
    }
    concatenatedString[lastIndex++] = '\0';

    return concatenatedString;
}
//Да се напише функция, която приема масив от думи и връща като резултат изречението,
//което се получава като се слепят всички думи от масива като се разделят със ' '
int main4()
{
    char words[MAX_SIZE][MAX_SIZE];
    int n;
    std::cout<<"Enter the number of words you will enter:";
    std::cin>>n;

    for (int i = 0; i < n; i++) {
        std::cin>>words[i];
    }
    char* ptrToSentence = transformSentence(words, n);
    unsigned i = 0;
    while(ptrToSentence[i])
    {
        std::cout<<*(ptrToSentence + i++);
    }
    delete[] ptrToSentence;
    return 0;
}
int * combineAndSort(const int * array1, const int * array2, int size1, int size2)
{
    int * combinedArray = new int [size1 + size2 + 1 ];
    int size3 = size1 + size2;
    for (int i = 0; i < size1 ; ++i) {
        combinedArray[i] = array1[i];
    }
    int tempIncrement = 0;
    for (int i = size1; i < size3; ++i) {
        combinedArray[i] = array2[tempIncrement++];
    }

    for (int i = 0; i < size1 + size2; ++i) {
        for (int j = i; j < size1 + size2; ++j) {
            int tempVar ;
            if(combinedArray[i] > combinedArray[j])
            {
                tempVar = combinedArray[i];
                combinedArray[i] = combinedArray[j];
                combinedArray[j] = tempVar;
            }
        }
    }


    return combinedArray;
}
bool isSortedASC(const int * array, int size)
{
    for (int i = 0; i < size ; ++i) {
        if(array[i] > array[i + 1] && i + 1 < size)
        {
            return false;
        }
    }
    return true;
}
//Да се напише функция, която приема 2 масива - сортирани и връща като резултат трети масив,
//отново сортиран - резултат от сливането на 2та масива.
int main5()
{
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];
    int size1, size2;

    std::cout<<"Enter the size of the first array:";
    std::cin>>size1;

    std::cout<<"Enter the size of the second array:";
    std::cin>>size2;

    for (int i = 0; i < size1; ++i) {
        std::cout<<"array1["<<i<<"] :";
        std::cin>>array1[i];
    }

    for (int i = 0; i < size2; ++i) {
        std::cout<<"array2["<<i<<"] :";
        std::cin>>array2[i];
    }

    if(!isSortedASC(array1, size1) || !isSortedASC(array2, size2))
    {
        std::cerr<<"The arrays you've entered are not sorted in ascending order"<<std::endl;
        return -1;
    }
    int * mergedPtr = combineAndSort(array1, array2, size1, size2);

    for (int i = 0; i < size1 + size2; ++i) {
        std::cout<<*(mergedPtr + i)<<" ";
    }
    mergedPtr = nullptr;
    delete[] mergedPtr;
    return 0;
}
int * onlyEven(const int * array, int size , int &sizeEven)
{
    int * returnableArray = new int [size];
    int k = 0;

    for (int i = 0; i < size ; ++i) {
        if(array[i] % 2 == 0)
        {
            *(returnableArray + k++) = array[i];
        }
    }
    sizeEven = k;
    return returnableArray;
}
//Да се напише функция, която приема масив от числа и връща масив, който съдържа само четните елементи
int main6()
{
    int array[MAX_SIZE];
    int n;
    std::cout<<"Enter array size:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }

    int sizeEven = 0;
    int * ptrToEven = onlyEven(array, n, sizeEven);

    std::cout<<"[";
    for (int i = 0; i < sizeEven ; ++i) {
        std::cout<<*(ptrToEven + i)<<", ";
    }
    std::cout<<"]";

    ptrToEven = nullptr;
    delete[] ptrToEven;

    return 0;
}

int countWordsInSentence(const char str[])
{
    int counter = 0;
    unsigned i = 0;
    while(str[i])
    {
        if(str[i] == ' ')
        {
            counter++;
        }
        i++;
    }
    return ++counter;
}
bool isWordPalindrome(const char word[], unsigned size)
{
    for (int i = 0; i < size  ; ++i) {
        if(word[i] != word[size - 1 - i ])
            return false;
    }
    return true;
}
char ** arrayOfPalindromeWords(const char * sentence, int numberOfWords, unsigned & numberOfPalindromeWords)
{
    char ** returnableArray = new char * [numberOfWords];
    char * tempWord = new char [MAX_SIZE];

    unsigned tempIncrement = 0;
    unsigned numOfWordsOccupied = 0;
    unsigned i = 0;
    for (int j = 0; j < numberOfWords; ++j) {
        while(sentence[i] != ' ' && sentence[i]!='\0')
        {
            tempWord[tempIncrement++] = sentence[i++];
        }
        if(isWordPalindrome(tempWord,tempIncrement))
        {
            returnableArray[numOfWordsOccupied] = new char[tempIncrement + 1];
            for (int k = 0; k < tempIncrement; ++k) {
                returnableArray[numOfWordsOccupied][k] = tempWord[k];
            }
            returnableArray[numOfWordsOccupied++][tempIncrement + 1] = '\0';
        }
        tempIncrement = 0;
        i++;

    }
    numberOfPalindromeWords = numOfWordsOccupied;
    return returnableArray;

}
//Да се напише функция, която приема символен низ - изречение и връща като резултат масив от думите
//(дума е поредица от символи {a-z, A-Z, -, _}) в изречението, които са палиндроми
int main()
{
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    unsigned numberOfPalindromeWords = 0;
    char ** ptrToPalindromeWords = arrayOfPalindromeWords(str, countWordsInSentence(str), numberOfPalindromeWords);

    for (int i = 0; i < numberOfPalindromeWords; ++i) {
        int j = 0;
        while(ptrToPalindromeWords[i][j + 1] != '\0')
        {
            std::cout<<ptrToPalindromeWords[i][j++];
        }
        std::cout<<std::endl;
    }

    delete [] ptrToPalindromeWords;
    return 0;

}