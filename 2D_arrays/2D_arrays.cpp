#include <iostream>

const int MAX_SIZE = 100;

int main0()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;


    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }

    //task 1
    //Output every row of the 2D array on a separate row
    std::cout<<"Rows separated:"<<std::endl;

    for (int i = 0; i < sizeRows; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<array2D[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    //task 2
    //Output every column of the 2D array on a separate row
    std::cout<<"Columns separated:"<<std::endl;

    for (int i = 0; i < sizeRows; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<array2D[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    //task 3
    //Output the elemets of the main diagonal
    std::cout<<"Elements of the main diagonal:"<<std::endl;
    for (int i = 0; i < sizeRows; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            if(i == j)
            std::cout<<array2D[i][j]<<" ";
        }
    }
    std::cout<<std::endl;

    //task 4
    //Output the elements of the secondary diagonal

    std::cout<<"Elements of the secondary diagonal:"<<std::endl;

    for (int i = 0; i < sizeRows; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            if(j == sizeColumns - i - 1 )
            std::cout<<array2D[i][j]<<" ";
        }
    }
    std::cout<<std::endl;

    return 0;
}
void transpose(const int array2D[][MAX_SIZE], int sizeRows, int sizeColumns)
{
    int sizeColumnsT = sizeRows;
    int sizeRowsT = sizeColumns;

    int arrayT [MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < sizeRowsT ; ++i) {
        for (int j = 0; j < sizeColumnsT ; ++j) {
            arrayT[i][j] = array2D[j][i];
        }
    }
    for (int i = 0; i < sizeRowsT ; ++i) {
        for (int j = 0; j < sizeColumnsT ; ++j) {
            std::cout<<arrayT[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
int main1()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;


    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }
    transpose(array2D, sizeRows, sizeColumns);
    return 0;
}
int main2()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;


    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }
    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            if(i % 2 == 0)
            {
                std::cout<<array2D[i][sizeColumns - j - 1]<<" ";
            }
            else
            {
                std::cout<<array2D[i][j]<<" ";
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}
int main3()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;

    int sumCol = 0;
    int maxSumCol = 0;
    int index ;
    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }

    for (int j = 0; j < sizeColumns ; ++j) {
        for (int i = 0; i < sizeRows ; ++i) {
            sumCol+=array2D[j][i];
        }
        if(sumCol > maxSumCol)
        {
            maxSumCol = sumCol;
            sumCol = 0;
            index = j;
        }
    }
    std::cout<<"Column with biggest sum: "<<index+1;
    return 0;
}
bool isPalindromeByRows(const int array2D[][MAX_SIZE], int sizeRows, int sizeCols)
{
    bool returnable = true;

    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeCols; ++j) {
            if(array2D[i][j] != array2D[i][sizeCols - j - 1])
            {
                returnable = false;
            }
        }
    }
    return returnable;
}
bool isPalindromeByCols(const int array2D[][MAX_SIZE], int sizeRows, int sizeCols)
{
    bool returnable = true;

    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeCols; ++j) {
            if(array2D[i][j] != array2D[sizeRows - i - 1][j])
            {
                returnable = false;
            }
        }
    }
    return returnable;
}
int main4()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;

    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }
    std::cout<<((isPalindromeByRows(array2D, sizeRows, sizeColumns) && isPalindromeByCols(array2D, sizeRows, sizeColumns)? "The matrix is palindrome!": "The matrix is not palindrome!"));
    return 0;
}
int main5()
{
    int array2D[MAX_SIZE][MAX_SIZE];
    int sizeRows, sizeColumns;

    std::cout<<"Enter number of rows:";
    std::cin>>sizeRows;

    std::cout<<"Enter size of columns:";
    std::cin>>sizeColumns;

    for (int i = 0; i < sizeRows ; ++i) {
        for (int j = 0; j < sizeColumns ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D[i][j];
        }
    }
    int printedElements = 0;
    int tempRowSize = sizeRows;
    int tempColSize = sizeColumns;
    int currRow;
    int currCol;
    int difference = 1;
    do
    {
        currRow = difference - 1;
        currCol = difference - 1;
        for (int i = currCol; i < tempColSize ; i++) {
            std::cout<<array2D[currRow][i]<<" ";
            printedElements++;
        }
        if(printedElements == sizeRows * sizeColumns) break;
        currRow++;
        for (int i = currRow; i < tempRowSize ; i++) {
            std::cout<<array2D[i][tempColSize - 1]<<" ";
            printedElements++;
        }
        if(printedElements == sizeRows * sizeColumns) break;
        currCol = tempColSize - 2;
        currRow = tempRowSize  - 1;

        for (int j = currCol; j >= difference - 1 ; j--) {
            std::cout<<array2D[currRow][j]<<" ";
            printedElements++;
        }
        if(printedElements == sizeRows * sizeColumns) break;
        currCol = difference - 1;
        currRow--;
        for (int i = currRow; i >= difference ; i--) {
            std::cout<<array2D[i][currCol]<<" ";
            printedElements++;
        }
        if(printedElements == sizeRows * sizeColumns) break;
        difference++;
        tempColSize--;
        tempRowSize--;
    } while(printedElements <= sizeColumns * sizeRows);
    return 0;
}
int main()
{
    int array2D1[MAX_SIZE][MAX_SIZE];
    int sizeRows1, sizeColumns1;

    std::cout<<"Enter number of rows1:";
    std::cin>>sizeRows1;

    std::cout<<"Enter size of columns1:";
    std::cin>>sizeColumns1;

    for (int i = 0; i < sizeRows1 ; ++i) {
        for (int j = 0; j < sizeColumns1 ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D1[i][j];
        }
    }
    int array2D2[MAX_SIZE][MAX_SIZE];
    int sizeRows2, sizeColumns2;

    std::cout<<"Enter number of rows1:";
    std::cin>>sizeRows2;

    std::cout<<"Enter size of columns1:";
    std::cin>>sizeColumns2;

    for (int i = 0; i < sizeRows2 ; ++i) {
        for (int j = 0; j < sizeColumns2 ; ++j) {
            std::cout<<"array2D["<<i<<"]["<<j<<"]:";
            std::cin>>array2D2[i][j];
        }
    }
    if(sizeColumns1 != sizeRows2)
    {
        std::cerr<<"Cannot multiply matrices"<<std::endl;
        return -1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    int sizeRowsM = sizeRows1;
    int sizeColsM = sizeColumns2;
    int currElementSum = 0;
    for (int i = 0; i < sizeRowsM; ++i) {
        for (int j = 0; j < sizeColsM ; ++j) {
            for (int k = 0; k < sizeColumns1; ++k) {
                currElementSum += array2D1[i][k] * array2D2[k][j];

            }
            matrix[i][j] = currElementSum;
            currElementSum = 0;
        }
    }

    for (int i = 0; i < sizeRowsM; ++i) {
        for (int j = 0; j < sizeColsM ; ++j) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
