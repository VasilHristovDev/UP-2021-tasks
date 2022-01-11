#include <iostream>
const int MAX_SIZE = 30;
bool hasNoDistinctDigits(int number)
{
    int helpArray[MAX_SIZE];
    int occupiedCells = 0;
    while(number > 0 )
    {
        helpArray[occupiedCells++] = number%10;
        number /=10;
    }
    for (int i = 0; i < occupiedCells ; ++i) {
        for (int j = i + 1; j < occupiedCells; ++j) {
            if(helpArray[i] == helpArray[j])
                return true;
        }
    }
    return false;
}
int countElementsWithoutDistinctDigits(int matrix[MAX_SIZE][MAX_SIZE], int n)
{
    int counter = 0;
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if(hasNoDistinctDigits(matrix[i][j]))
                counter++;
        }
    }
    return counter;
}
int * collect (int matrix[MAX_SIZE][MAX_SIZE], int n)
{

    int * arrayWithNumbers = new int [countElementsWithoutDistinctDigits(matrix, n)];
    int occupiedCells = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n - 1 - i+1; ++j) {
            if(hasNoDistinctDigits(matrix[i + j][j]))
                arrayWithNumbers[occupiedCells++] = matrix[i+j][j];
        }
    }
    for (int j = 1; j <= n - 1; ++j) {
        for (int i = 0; i <= n-2; ++i) {
            if(hasNoDistinctDigits(matrix[i][j + i]))
            {
                arrayWithNumbers[occupiedCells++] = matrix[i][j + i];
            }
        }
    }

    return arrayWithNumbers;
}
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];

    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    if(n < 1 || n > 30)
    {
        std::cerr<<"Invalid data! N must be between 1 and 30!";
        return -1;
    }

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin>>matrix[i][j];
        }
    }
    int sizeArray = countElementsWithoutDistinctDigits(matrix, n);
    int * ptrToArray = collect(matrix, n);

    for (int i = 0; i < sizeArray ; ++i) {
        std::cout<<*(ptrToArray + i) << " ";
    }

    delete [] ptrToArray;
    ptrToArray = nullptr;


    return 0;

}