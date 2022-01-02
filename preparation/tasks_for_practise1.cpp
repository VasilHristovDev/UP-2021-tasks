#include <iostream>
#include <cmath>
#include <set>

const int MAX_SIZE = 100;

bool contains(int element, const int * sequenceL, int n)
{
    for (int i = 0; i < n; ++i) {
        if(element == sequenceL[i])
            return true;
    }
    return false;
}
int * removeLargestElementInK(int * sequenceK, int * sequenceL, int &m, int n)
{
    int *  sequenceKNew = new int [m - 1];
    int maxElement = 0;
    int indexInK;
    for (int i = 0; i < m; ++i) {

        if(maxElement < sequenceK[i] && !contains(sequenceK[i],sequenceL, m))
        {
            maxElement = sequenceK[i];
            indexInK = i;
        }
    }
    for (int i = 0; i < m ; ++i) {
        if(indexInK == i)
            sequenceKNew[i] = sequenceK[i + 1];
        else
            sequenceKNew[i] = sequenceK[i];
    }
    m--;
    return sequenceKNew;
}
// да се напише програма , която премахва най-големия елемент от една редица, който не се съдържа в друга
int main1()
{
    const int MAX_ELEMENTS = 100;
    int sequenceK[MAX_ELEMENTS];
    int sequenceL[MAX_ELEMENTS];

    int m,n;
    std::cout<<"Enter m and n:";
    std::cin>>m>>n;

    for (int i = 0; i < m; ++i) {
        std::cout<<"k["<<i<<"]:";
        std::cin>>sequenceK[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout<<"l["<<i<<"]:";
        std::cin>>sequenceL[i];
    }

    int * ptrToNewK = removeLargestElementInK(sequenceK, sequenceL, m, n);

    for (int i = 0; i <  m; ++i) {
        std::cout<<ptrToNewK[i]<<" ";
    }
    ptrToNewK = nullptr;
    delete [] ptrToNewK;

    return 0;

}
void cycle(int * x,int n, int k)
{

    for (int i = 0; i < n - k; ++i) {
        *(x + i) = *(x + i + k);
        std::cout<<*(x + i)<<" ";
    }
    std::cout<<std::endl;
}
void cycleMatr(int a[][20], int n, int * b)
{
    for (int i = 0; i < n; ++i) {
        cycle(a[i],n,b[i]);
    }
}
int main2()
{

    int a[MAX_SIZE][20];
    int n;

    std::cout<<"Enter size:";
    std::cin>>n;

    std::cout<<"Enter the matrix:"<<std::endl;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            std::cin>>a[i][j];
        }
    }
    int b[MAX_SIZE];
    std::cout<<"Enter the array b:"<<std::endl;

    for (int i = 0; i < n ; ++i) {
        std::cin>>b[i];
    }

    std::cout<<std::endl;
    cycleMatr(a,n,b);
    
    return 0;
}
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

char * mother(char tableWithNames[20][4][20], const char * person, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        if(myStrCompare(tableWithNames[i][0], person) == 0)
            return tableWithNames[i][1];

    }
    return nullptr;
}
char * father(char tableWithNames[20][4][20], const char * person, int n, int m)
{
    for (int i = 0; i < n; ++i) {
        if(myStrCompare(tableWithNames[i][0], person) == 0)
            return tableWithNames[i][2];

    }
    return nullptr;
}
bool inheritor(char * person, char * inheritorC, char R[20][4][20], int n)
{
    if (father(R,person, n,3) == nullptr && mother(R,person,n,3) == nullptr)
        return false;
    else if(myStrCompare(inheritorC, father(R,person,n,3)) == 0
            ||
            myStrCompare(inheritorC, mother(R,person,n,3))
            ||
            myStrCompare(person,inheritorC) == 0)
        return true;
    else
        return inheritor(inheritorC, father(R,inheritorC,n,3),R,n);
}
int main3()
{
    char R[20][4][20];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;
    std::cin.ignore();
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin.getline(R[i][j],20);
        }
    }
    char person[MAX_SIZE];
    char inheritorC[MAX_SIZE];

    std::cout<<"Enter a person's name:";
    std::cin.getline(person, 20);

    char * ptrToMother = mother(R,person,n,3);
    char * ptrToFather = father(R,person,n,3);

    std::cout<<(ptrToMother == nullptr ? "None": ptrToMother)<<std::endl;
    std::cout<<(ptrToFather == nullptr ? "None": ptrToFather)<<std::endl;

    ptrToMother = nullptr;
    ptrToFather = nullptr;

    delete[] ptrToMother;
    delete[] ptrToFather;

    std::cout<<"Enter a person:";
    std::cin.getline(person,20);

    std::cout<<"Enter an inheritor:";
    std::cin.getline(inheritorC,20);

    std::cout<<(inheritor(person, inheritorC, R,n)? "The person is an inheritor": "The person is not an inheritor")<<std::endl;
    return 0;

}
unsigned length(const char * str)
{
    unsigned i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
const int MAX_SIZE_NUMBERS = 10;
int * extractNumbers(char * sentence, int & sizeNew)
{
    int * numbers = new int [MAX_SIZE_NUMBERS];
    unsigned size = length(sentence);
    int occupiedNumbers = 0;
    int number = 0;
    int helper = 0;
    int counter = 0;
    bool negative = false;
    for (int i = 0; i < size; ++i) {
        if(sentence[i] >= '0' && sentence[i] <= '9')
        {
            if(sentence[i-1] == '-')
                negative = true;
            number = 0;
            counter = 0;
            while(sentence[i] >= '0' && sentence[i] <= '9')
            {
                counter++;
                i++;
            }
            helper = (int) pow(10,counter-1);
            i = i - counter;
            while(sentence[i] >= '0' && sentence[i] <= '9')
            {
                number += (sentence[i] - '0') * helper;
                helper/= 10;
                i++;
            }
            if(negative) {
                numbers[occupiedNumbers++] = -number;
                negative = false;
            }
            else
            {
                numbers[occupiedNumbers++] = number;
            }
        }
    }
    sizeNew = occupiedNumbers;
    return numbers;
}
int main4()
{
    char str[MAX_SIZE];

    std::cout<<"Enter sentence:";

    std::cin.getline(str, MAX_SIZE);

    int size = 0;
    int * ptrToArray = extractNumbers(str, size);

    for (int i = 0; i < size ; ++i) {
        std::cout<<*(ptrToArray + i)<<" ";
    }
    ptrToArray = nullptr;
    delete [] ptrToArray;
    return 0;
}
char ** extractWords(char *sentence, int size)
{
    char ** returnableArray = new char * [size];
    unsigned sizeSentence = length(sentence);
    int currentIndex = 0;
    int tempIndex = 0;
    int occupiedWords = 0;
    while(sentence[currentIndex] && currentIndex < sizeSentence - 1)
    {
        if(sentence[currentIndex] == ' ')
        {
            tempIndex = 0;
            currentIndex++;
            returnableArray[occupiedWords] = new char [MAX_SIZE];
            while(sentence[currentIndex] != ' ')
            {
                returnableArray[occupiedWords][tempIndex++] = sentence[currentIndex++];
            }
            returnableArray[occupiedWords][tempIndex++] = '\0';
            occupiedWords++;
        }
        else
        {
            currentIndex++;
        }
    }

    return  returnableArray;
}
int countBlankSpaces(const char * str)
{
    int count = 0;
    int i = 0;
    while(str[i])
    {
        if(str[i] == ' ')
            count++;
        i++;
    }
    return count;
}
int main5()
{
    char str[MAX_SIZE];
    std::cout<<"Enter sentence:";
    std::cin.ignore();
    std::cin.getline(str, MAX_SIZE);
    int numWords = countBlankSpaces(str) - 1;
    char ** ptrToArrayOfWords = extractWords(str, numWords);

    for (int i = 0; i < numWords; ++i) {
        std::cout<<ptrToArrayOfWords[i]<<" ";
        ptrToArrayOfWords[i] = nullptr;
        delete[] ptrToArrayOfWords[i];
    }
    ptrToArrayOfWords = nullptr;
    delete[] ptrToArrayOfWords;

    return 0 ;
}
int * sortRowBySumOfDigits(const int * row, int m)
{
    int * newRow = new int [m];
    for (int i = 0; i < m; ++i) {
        newRow[i] = row[i];
    }
    int sums[MAX_SIZE];
    int occupiedElements = 0;
    int tempVar = 0;
    int sumDigits = 0;
    for (int i = 0; i < m; ++i) {
        tempVar = row[i];
        sumDigits = 0;
        while(tempVar > 0)
        {
            sumDigits+= tempVar % 10;
            tempVar/=10;
        }
        sums[occupiedElements++] = sumDigits;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if(sums[i] > sums[j])
            {
                tempVar = sums[i];
                sums[i] = sums[j];
                sums[j] = tempVar;

                tempVar = newRow[i];
                newRow[i] = newRow[j];
                newRow[j] = tempVar;
            }
        }
    }

    return newRow;
}
bool existsDiagonalArithmeticProgression(int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    int counter = 0;
    double x;
    double D;
    double prevX = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j)
            {
                D = 1 + 4 * (2 * matrix[i][j]);
                x = (sqrt(D) - 1)/2;

                if(x == prevX + 1 && flag)
                {
                    counter++;
                }
                flag = true;
                prevX = x;

            }
        }
    }
    return counter == n - 1;
}
int main6()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    std::cout<<"Enter size:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
           std::cin>>matrix[i][j];
        }
    }

    for (int i = 0; i < n ; ++i) {
        int * ptrToNewRow = sortRowBySumOfDigits(matrix[i], n);
        for (int j = 0; j < n ; ++j) {
            matrix[i][j] = ptrToNewRow[j];
        }
        ptrToNewRow = nullptr;
        delete[] ptrToNewRow;
    }

    std::cout<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    if(n >= 3)
    {
       std::cout<<(existsDiagonalArithmeticProgression(matrix,n) ? "It exists":"It does not exist")<<std::endl;
    }
    return  0;
}
bool checkPath(int labyrinth[10][10], const char * path, int n, int& firstChar, int i, int j)
{
    if(n == 1)
    {
        return true;
    }
    else
    {
        char currentPath = path[firstChar];
        if(currentPath == 'N')
        {
            i = i - 1;
        }
        else if(currentPath == 'E')
        {
            j = j + 1;
        }
        else if(currentPath == 'S')
        {
            i = i + 1;
        }
        else
        {
            j = j - 1;
        }

    }
    if(labyrinth[i][j] == 0)
        return false;
    else if(i > n - 1 || j > n -1 || i < 0 || j < 0)
        return false;
    else
    {
        firstChar++;
        if(i == n - 1 && j == n - 1)
            return true;
        return checkPath(labyrinth, path, n, firstChar, i, j);
    }
}
int main7()
{
    int labyrinth[10][10];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>labyrinth[i][j];
        }
    }

    char path[MAX_SIZE];
    std::cout<<"Enter path:";
    std::cin>>path;
    int firstChar = 0;
    std::cout<<(checkPath(labyrinth,path,n,firstChar,0,0) ? "The path succeeds!": "The path does not succeed!")<<std::endl;

    return 0;

}
char * encode(const char * string)
{
    char * encoded = new char [MAX_SIZE];
    unsigned i = 0;
    int tempCount = 1;
    int occupiedElements = 0;
    while(string[i])
    {
        if(string[i] == string[i+1])
        {
            tempCount++;
        }
        else
        {
            if(tempCount > 1)
                encoded[occupiedElements++] =  tempCount + '0';
            encoded[occupiedElements++] = string[i];
            tempCount = 1;
        }
        i++;
    }
    encoded[occupiedElements++] = '\0';
    return encoded;
}
int main8()
{
    char string[MAX_SIZE];
    std::cout<<"Enter string:";
    std::cin>>string;

    char * ptrToEncoded = encode(string);
    std::cout<<ptrToEncoded<<std::endl;

    ptrToEncoded = nullptr;
    delete[] ptrToEncoded;
    return 0;
}
bool rowHasDistinctElements(const int * row, int n)
{
    int distinctCounter = 0;
    for (int i = 0; i < n * n; ++i) {
        for (int j = i + 1; j < n * n; ++j) {
            if(row[i] != row[j])
                distinctCounter++;
        }
    }
    int sumToCheck = 0;
    for (int i = n * n -1; i > 0 ; --i) {
        sumToCheck+=i;
    }
    return distinctCounter == sumToCheck;
}

bool rowsAndColsDistinct(int field[MAX_SIZE][MAX_SIZE], int n)
{
    int countDistinctRows = 0;
    int countDistinctCols = 0;

    for (int i = 0; i < n * n; ++i) {
        if(rowHasDistinctElements(field[i],n))
            countDistinctRows++;
    }
    int occupiedElements = 0;
    int * column = new int [n*n];
    for (int i = 0; i < n * n; ++i) {
        occupiedElements = 0;
        for (int j = 0; j < n * n ; ++j) {
            column[occupiedElements++] = field[j][i];
        }
        if(rowHasDistinctElements(column,n))
            countDistinctCols++;
    }

    column = nullptr;
    delete [] column;
    return countDistinctRows == n * n  && countDistinctCols == n * n;


}
bool checkSudoku(int field[MAX_SIZE][MAX_SIZE], int n, int i, int j, int iBase, int jBase)
{
    int numDistinctElements = 0;

    int ** square = new int * [n];
    for (int k = 0; k < n; ++k) {
        j = jBase;

        square[k] = new int [n];
        for (int l = 0; l < n; ++l) {
            square[k][l] = field[i][j++];
        }
        i++;

    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            for (int m = 0; m < n; ++m) {
                for (int i1 = 0; i1 < n; ++i1) {
                    if(square[k][l] != square[m][i1])
                        numDistinctElements++;
                }
            }
        }
    }
    int sumToCheck = 0;
    for (int k = n * n - 1; k > 0; --k) {
        sumToCheck +=k;
    }
    for (int k = 0; k < n; ++k) {
        square[k] = nullptr;
        delete [] square[k];
    }
    square = nullptr;
    delete[] square;

    if(numDistinctElements == sumToCheck * 2)
    {
        if(iBase == n * n - n && jBase == n * n - n)
        {
            return true;
        }
        else if(jBase == n * n - n)
        {
            j = 0;
            iBase = iBase + n;
            i = iBase;
            jBase = 0;
        }
        else
        {
            jBase = jBase + n;
            i = iBase;
        }

        return checkSudoku(field,n,i,j,iBase, jBase);
    }

    else
        return false;


}
int main9()
{
    int field[MAX_SIZE][MAX_SIZE];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n * n; ++i) {
        for (int j = 0; j < n * n ; ++j) {
            std::cin>>field[i][j];
        }
    }
    std::cout<<(rowsAndColsDistinct(field,n) && checkSudoku(field,n,0,0,0, 0)? "It fits the rules!" : "It does not fit the rules")<<std::endl;

    return 0;

}
int numOfNeighboursO(char map[MAX_SIZE][MAX_SIZE], int n, int i, int j)
{
    int countOfOs = 0;
    if (i == 0)
    {
        if(j == 0)
        {
            if(map[i][j+1] == 'o')
                countOfOs++;
            if(map[i+1][j] == 'o')
                countOfOs++;
        }
        else if (j == n - 1)
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i+1][j] == 'o')
                countOfOs++;
        }
        else
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i+1][j] == 'o')
                countOfOs++;
            if(map[i][j+1] == 'o')
                countOfOs++;
        }
    }
    else if ( i > 0 && i < n - 1)
    {
        if(j == 0)
        {
            if(map[i - 1][j] == 'o')
                countOfOs++;
            if(map[i + 1][j] == 'o')
                countOfOs++;
            if(map[i][j+1] == 'o')
                countOfOs++;
        }
        else if (j == n - 1)
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i+1][j] == 'o')
                countOfOs++;
            if(map[i-1][j] == 'o')
                countOfOs++;
        }
        else
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i][j+1] == 'o')
                countOfOs++;
            if(map[i+1][j] == 'o')
                countOfOs++;
            if(map[i-1][j] == 'o')
                countOfOs++;
        }
    }
    else
    {
        if(j == 0)
        {
            if(map[i - 1][j] == 'o')
                countOfOs++;
            if(map[i][j+1] == 'o')
                countOfOs++;
        }
        else if (j == n - 1)
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i-1][j] == 'o')
                countOfOs++;
        }
        else
        {
            if(map[i][j-1] == 'o')
                countOfOs++;
            if(map[i][j+1] == 'o')
                countOfOs++;
            if(map[i-1][j] == 'o')
                countOfOs++;
        }
    }
    return countOfOs;
}
int main()
{
    char map[MAX_SIZE][MAX_SIZE];
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>map[i][j];
        }
    }
    int counter = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(numOfNeighboursO(map,n,i,j) % 2 == 0)
                counter++;
        }
    }
    std::cout<<(counter == n * n ? "YES": "NO")<<std::endl;
    return 0;
}