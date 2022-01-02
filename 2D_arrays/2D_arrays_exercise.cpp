#include <iostream>

//целочислена матрица с размерност n,m [1,10]

const unsigned MAX_SIZE = 10;
// a) проверява дали матрицата е симетрична спрямо главния диагонал (n x n)
bool isSymmetricByPrime(const int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}
int main1a()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    std::cout<<(isSymmetricByPrime(matrix, n) ? "It is symmetric": "It is not symmetric")<<std::endl;

    return 0;
}
// б) намира и извежда транспонираната матрица
int ** transposeMatrix( const int matrix[MAX_SIZE][MAX_SIZE], int N, int M)
{
    int ** transposed = new int * [M];

    for (int i = 0; i < M ; ++i) {
        transposed[i] = new int [N];
        for (int j = 0; j < N; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}
int main1b()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n, m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    int ** ptrToTransposed = transposeMatrix(matrix, n ,m);

    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n ; ++j) {
            std::cout<<ptrToTransposed[i][j]<<" ";
        }
        ptrToTransposed[i] = nullptr;
        delete[] ptrToTransposed[i];
        std::cout<<std::endl;
    }
    ptrToTransposed = nullptr;
    delete[] ptrToTransposed;

    return 0;
}
// в) събира матрицата с друга със същата размерност
int ** addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int N, int M)
{
    int ** sumMatrix = new int * [N];

    for (int i = 0; i < N; ++i) {
        sumMatrix[i] = new int [M];
        for (int j = 0; j < M; ++j) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sumMatrix;
}
int main1c()
{
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];

    int n,m;
    std::cout<<"Enter n and m";
    std::cin>>n>>m;

    int ** ptrToSummedMatrices = addMatrices(matrix1, matrix2, n, m);

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout<<ptrToSummedMatrices[i][j]<<" ";

        }
        ptrToSummedMatrices[i] = nullptr;
        delete[] ptrToSummedMatrices[i];
        std::cout<<std::endl;
    }
    ptrToSummedMatrices = nullptr;
    delete[] ptrToSummedMatrices;
    return 0;
}
// г) умножава матрица с размер n x m с друга с рамер m x p
int ** productMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int N, int M, int P)
{
    int ** productMatrix = new int * [N];
    int currElemSum = 0;
    for (int i = 0; i < N ; ++i)
    {
        productMatrix[i] = new int [P];
        for (int j = 0; j < P; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                currElemSum += matrix1[i][k] + matrix2[k][j];
            }
            productMatrix[i][j] = currElemSum;
            currElemSum = 0;
        }
        
    }
    return productMatrix;
}
int main1d()
{
     int matrix1[MAX_SIZE][MAX_SIZE];
     int matrix2[MAX_SIZE][MAX_SIZE];
     int n,m,p;

    std::cout<<"Enter the size of the matrix1:";
    std::cin>>n>>m;

    std::cout<<"Enter the size of columns of the second matrix:";
    std::cin>>p;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin>>matrix1[i][j];
        }
    }

    std::cout<<"Enter the second matrix:"<<std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            std::cin>>matrix2[i][j];
        }
    }

    int ** ptrToProductMatrices = productMatrices(matrix1, matrix2, n, m, p);
    std::cout<<"Sum Matrix:"<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            std::cout<<ptrToProductMatrices[i][j]<<" ";
        }
        ptrToProductMatrices[i] = nullptr;
        delete[] ptrToProductMatrices[i];
        std::cout<<std::endl;
    }
    ptrToProductMatrices = nullptr;
    delete[] ptrToProductMatrices;

    return 0;
}
//да се напише функция, която намира сумата на елементите под главния диагонал на квадратна матрица n x n
int sumUnderPrimeDiagonal (const int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( i > j)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
//да се напише функция, която намира сумата на елементите над главния диагонал на квадратна матрица n x n
int sumAbovePrimeDiagonal (const int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ( i < j)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main2()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    std::cout<<"Enter the size:";
    std::cin>>n;

    std::cout<<"The sum under the prime diagonal is: "<<sumUnderPrimeDiagonal(matrix, n);
    std::cout<<"The sum above the prime diagonal is: "<<sumAbovePrimeDiagonal(matrix, n);

    return 0;

}
bool isInsideMatrix(const int matrix[20][30], int n, int m, int number, int &posI, int &posJ)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ( number == matrix[i][j])
            {
                posI = i;
                posJ = j;
                return true;
            }
        }
    }
    return false;
}
int main3()
{
    const unsigned MAX_ROWS = 20;
    const unsigned MAX_COLS = 30;

    int A[MAX_ROWS][MAX_COLS];
    int n, m;

    std::cout<<"Enter the size of n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin>>A[i][j];
        }
    }

    int number;
    std::cout<<"Enter a number:";
    std::cin>>number;

    int posI, posJ;

    if(isInsideMatrix(A,n,m,number,posI,posJ))
        std::cout<<"The number is found inside the matrix and it is on positions: "<<posI<<" "<<posJ<<std::endl;
    else
        std::cout<<"The number was not found inside the matrix!"<<std::endl;

    return 0;
}
int ** deleteRow(const int matrix[MAX_SIZE][MAX_SIZE], int &n, int m, int k)
{
    int ** returnableMatrix = new int* [n -1];

    for (int i = 0; i < n; ++i) {
        returnableMatrix[i] = new int [m];
        if(k == i) {
            for (int j = 0; j < m ; ++j) {
                returnableMatrix[i][j] = matrix[i + 1][j];
            }
        }
        else
        {
            for (int j = 0; j < m ; ++j) {
                returnableMatrix[i][j] = matrix[i][j];
            }
        }

    }
    n--;
    return returnableMatrix;
}
int main4a()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n, m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin>>matrix[i][j];
        }
    }

    int k;
    std::cout<<"Enter the row to be removed:";
    std::cin>>k;

    int ** ptrToNewMatrix = deleteRow(matrix, n , m, k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout<<ptrToNewMatrix[i][j]<<" ";
        }
        ptrToNewMatrix[i] = nullptr;
        delete[] ptrToNewMatrix[i];
        std::cout<<std::endl;
    }
    ptrToNewMatrix = nullptr;
    delete[] ptrToNewMatrix;

    return 0;
}
//да се напише функция, която премахва колона к в матрица n x m
int ** deleteColumn(const int matrix[MAX_SIZE][MAX_SIZE], int n, int &m, int k)
{
    int ** returnableMatrix = new int* [n];

    for (int i = 0; i < n; ++i) {
        returnableMatrix[i] = new int [m - 1];
        for (int j = 0; j < m; ++j) {
            if(j == k)
            {
                returnableMatrix[i][j] = matrix[i][j + 1];
            }
            else
            {
                returnableMatrix[i][j] = matrix[i][j];
            }
        }

    }
    m--;
    return returnableMatrix;
}
int main4()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n, m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin>>matrix[i][j];
        }
    }

    int k;
    std::cout<<"Enter the column to be removed:";
    std::cin>>k;

    int ** ptrToNewMatrix = deleteColumn(matrix, n , m, k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout<<ptrToNewMatrix[i][j]<<" ";
        }
        ptrToNewMatrix[i] = nullptr;
        delete[] ptrToNewMatrix[i];
        std::cout<<std::endl;
    }
    ptrToNewMatrix = nullptr;
    delete[] ptrToNewMatrix;

    return 0;
}
//да се напише програма, която  извежда всички редове с брой различни елементи по-малък от дадено число

int numberOfDistinctElements(const int array[], int size)
{
    int counter = size;
    for (int i = 0; i < size ; ++i) {

        for (int j = i + 1; j < size; ++j) {
            if(array[i] == array[j])
            {
                counter--;
            }

        }
    }

    return counter;
}
int findIndexOfMin(const int array[], int n, int start)
{
    if (start >= n)
        return -1;

    int minIndex = start;
    for (int i = start + 1; i < n; ++i)
    {
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
    }

    return minIndex;
}
void sortOutput(int array[], int n)
{
    int tempVar;
    for (int i = 0; i < n; ++i)
    {
        int minIndex = findIndexOfMin(array, n, i);

        if (minIndex != i)
        {
            tempVar = array[i];
            array[i] = array[minIndex];
            array[minIndex]  = tempVar;
        }
        else
        {
            continue;
        }

    }
    for (int i = 0; i < n ; i++) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}

int main5()
{
    int array[MAX_SIZE][MAX_SIZE];
    int n,m;

    std::cout<<"Enter n and m :";
    std::cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            std::cin>>array[i][j];
        }
    }
    int maxNumDistinctElements;
    std::cout<<"Enter the maximum number of distinct elements:";
    std::cin>>maxNumDistinctElements;

    for (int i = 0; i < n; ++i) {
        if(numberOfDistinctElements(array[i], m) < maxNumDistinctElements)
            sortOutput(array[i],m);

    }
    return 0;
}
//да се напише програма, която проверява дали съществува елемент, който е равен на сумата от съседите си
int sumOfNeighbours(const int matrix[MAX_SIZE][MAX_SIZE], int N, int M, int i, int j)
{
    int sumNeighbours = 0;
    if(i == 0)
    {
        if(j == 0)
        {
            sumNeighbours = matrix[i + 1][j] + matrix[i+1][j+1] + matrix[i][j+1];
        }
        else if(j == M - 1)
        {
            sumNeighbours = matrix[i+1][j] + matrix[i][j - 1] + matrix[i+1][j-1];
        }
        else
        {
            sumNeighbours = matrix[i][j+1] + matrix[i][j-1] + matrix[i+1][j+1] + matrix[i+1][j] + matrix[i+1][j-1];
        }
    }
    else if( i > 0 && i < N - 1)
    {
        if(j == 0)
        {
            sumNeighbours = matrix[i - 1][j] + matrix[i-1][j+1] + matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1];
        }
        else if(j == M -1)
        {
            sumNeighbours = matrix[i][j-1] + matrix[i-1][j] + matrix[i-1][j-1] + matrix[i+1][j-1] + matrix[i+1][j];
        }
        else
        {
            sumNeighbours = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j-1] + matrix[i+1][j] + matrix[i+1][j+1];
        }
    }
    else
    {
        if(j == 0)
        {
            sumNeighbours = matrix[i - 1][j] + matrix[i-1][j+1] + matrix[i][j+1];
        }
        else if(j == M -1)
        {
            sumNeighbours = matrix[i][j-1] + matrix[i-1][j] + matrix[i-1][j-1];
        }
        else
        {
            sumNeighbours = matrix[i-1][j-1] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j-1] + matrix[i][j+1];
        }
    }
    return sumNeighbours;
}
int main6()
{
    int array[MAX_SIZE][MAX_SIZE];
    int  n,m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin>>array[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(array[i][j] == sumOfNeighbours(array,n,m,i,j))
            {
                std::cout<<array[i][j]<<" i:"<<i<<" j:"<<j<<std::endl;
            }
        }
    }
    return 0;
}
bool areSimilar(const int * array1, const int * array2, int n)
{
    int counter = 0;
    int size2 = n;
    int copyArray2[MAX_SIZE];
    for (int i = 0; i < size2; ++i) {
        copyArray2[i] = array2[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size2; ++j) {
            if(array1[i] == copyArray2[j])
            {
                for (int k = j; k < size2; ++k) {
                    copyArray2[k] = copyArray2[k+1];
                }
                counter++;
            }
        }
    }
    return counter == n;
}
int main7()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>matrix[i][j];
        }
    }
    bool found = false;
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(areSimilar(matrix[i], matrix[j], n))
            {
                std::cout<<"Yes there are two similar!"<<"\n"<<"Row "<<i<<" and "<<j<<std::endl;
                found = true;
            }

        }
    }
    if(!found) std::cout<<"None of the rows are similar!"<<std::endl;

    return 0;

}
double calculateDistance(double x1, double y1, double x2, double y2)
{
    double distanceX = x2 - x1;
    double distanceY = y2 - y1;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}
int main8()
{
    double matrix[2][MAX_SIZE];
    int n;

    std::cout<<"Enter the number of columns in the matrix:";
    std::cin>>n;

    double maxDistance = 0;
    double distance = 0;
    int indexI1 = 0;

    for (int i = 0; i < 2 ; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>matrix[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        distance = calculateDistance(matrix[0][i],matrix[1][i],matrix[0][i+1], matrix[1][i+1]);
        if(distance > maxDistance)
        {
            maxDistance = distance;
            indexI1 = i;
        }

    }
    std::cout<<"Max distance between two points is: "<<maxDistance<<". Indexes of the points are: "<<indexI1<<" "<<indexI1 + 1<<std::endl;
    return 0;

}
bool isMinimalElementInRow(int matrix[20][30], int n, int m, int element, int row)
{
    for (int i = 0; i < m; ++i) {
        if(element > matrix[row][i])
            return false;
    }
    return true;
}
bool isMaximalElementInColumn(int matrix[20][30], int n, int m, int element, int column)
{
    for (int i = 0; i < n; ++i) {
        if(element < matrix[i][column])
            return false;
    }
    return true;
}
int main9()
{
    const int MAX_ROWS = 20;
    const int MAX_COLS = 30;
    int matrix[MAX_ROWS][MAX_COLS];
    int n, m;

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m ; ++j) {
            std::cin>>matrix[i][j];
        }
    }
    std::cout<<"Sedlovi tochki:"<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(isMaximalElementInColumn(matrix, n, m , matrix[i][j], j) && isMinimalElementInRow(matrix, n , m, matrix[i][j], i))
                std::cout<<matrix[i][j]<<" ";
        }
    }

    return 0;
}
unsigned length (const char str[])
{
    unsigned len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
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

//да се напише функция, която намира най-често срещания низ в масив от низове
char * mostCommonWord(char arrayWords[][9], int size)
{
    char * word = new char [MAX_SIZE];
    int counter = 0;
    int maxCounter = 0;

    for (int i = 0; i < size ; ++i) {
        char * tempWord = new char [MAX_SIZE];
        for (int j = 0; j < length(arrayWords[i]); ++j) {
            tempWord[j] = arrayWords[i][j];
        }
        for (int j = i; j < size; ++j) {
            if(myStrCompare(tempWord, arrayWords[i]) == 0)
                counter++;
        }
        if(counter > maxCounter)
        {
            maxCounter = counter;
            for (int j = 0; j < length(arrayWords[i]); ++j) {
                word[j] = tempWord[j];
            }
            word[length(arrayWords[i])] = '\0';
        }
        tempWord = nullptr;
        delete[] tempWord;
    }
    return word;
}
int main10()
{
    char arrayOfWords[MAX_SIZE][9];
    int n;

    std::cout<<"Enter size:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cin>>arrayOfWords[i];
    }

    char * ptrToMostCommonWord = mostCommonWord(arrayOfWords, n);
    std::cout<<ptrToMostCommonWord<<std::endl;

    ptrToMostCommonWord = nullptr;
    delete[] ptrToMostCommonWord;
    return 0;
}
//Дадена е квадратна таблица с думи да се намери колко пъти се среща дадена дума под вторичния диагонал
int timesWordIsFoundUnderPrimeDiagonal(char tableWords[][MAX_SIZE][6],int n, char  word[])
{
    int counter = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i + j > n - 1 && myStrCompare(word,tableWords[i][j]) == 0)
                counter++;
        }
    }
    return counter;
}
int main11()
{
    char table[MAX_SIZE][MAX_SIZE][6];
    int n;

    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            std::cin>>table[i][j];
        }
    }
    char word[6];
    std::cout<<"Enter a word:";
    std::cin>>word;

    std::cout<<timesWordIsFoundUnderPrimeDiagonal(table,n,word)<<" times word found under prime diagonal!"<<std::endl;
    return 0;
}