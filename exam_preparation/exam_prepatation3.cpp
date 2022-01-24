#include <iostream>

int min(int a, int b) {
    if (a == -1) {
        return b;
    }

    if (b == -1) {
        return a;
    }

    return a > b ? b : a;
}

int min(int a, int b, int c, int d) {
    return min(min(min(a, b), c), d);
}

int shortestPathUpDown(int matrix[][100], bool visited[][100], int n, int m, int rowCurr, int colCurr, int rowEnd,
                       int colEnd) {
    if (rowCurr < 0 || rowCurr >= n || colCurr < 0 || colCurr >= m) {
        return -1;
    }

    if (rowEnd == rowCurr && colEnd == colCurr) {
        return 0;
    }

    if (visited[rowCurr][colCurr] || matrix[rowCurr][colCurr] == 0) {
        return -1;
    }

    visited[rowCurr][colCurr] = true;

    int pathUpwards = shortestPathUpDown(matrix, visited, n, m, rowCurr - 1, colCurr, rowEnd, colEnd);
    int pathDownwards = shortestPathUpDown(matrix, visited, n, m, rowCurr + 1, colCurr, rowEnd, colEnd);
    int pathLeft = shortestPathUpDown(matrix, visited, n, m, rowCurr, colCurr - 1, rowEnd, colEnd);
    int pathRight = shortestPathUpDown(matrix, visited, n, m, rowCurr, colCurr + 1, rowEnd, colEnd);

    visited[rowCurr][colCurr] = false;

    return 1 + min(pathDownwards, pathUpwards, pathLeft, pathRight);
}

int shortestPathLeftRight(int matrix[][100], bool visited[][100], int n, int m, int rowCurr, int colCurr, int rowEnd,
                          int colEnd) {
    if (rowCurr < 0 || rowCurr >= n || colCurr < 0 || colCurr >= m) {
        return -1;
    }

    if (rowEnd == rowCurr && colEnd == colCurr) {
        return 0;
    }

    if (visited[rowCurr][colCurr] || matrix[rowCurr][colCurr] == 0) {
        return -1;
    }

    visited[rowCurr][colCurr] = true;

    int pathLeft = shortestPathLeftRight(matrix, visited, n, m, rowCurr, colCurr - 1, rowEnd, colEnd);
    int pathRight = shortestPathLeftRight(matrix, visited, n, m, rowCurr, colCurr + 1, rowEnd, colEnd);
    int pathUpwards = shortestPathLeftRight(matrix, visited, n, m, rowCurr - 1, colCurr, rowEnd, colEnd);
    int pathDownwards = shortestPathLeftRight(matrix, visited, n, m, rowCurr + 1, colCurr, rowEnd, colEnd);


    visited[rowCurr][colCurr] = false;

    return 1 + min(pathDownwards, pathUpwards, pathLeft, pathRight);
}

int main1() {
    int n, m;
    std::cin >> n >> m;

    int matrix[100][100];
    bool visited[100][100]{};

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int rowStart, colStart, rowEnd, colEnd;
    std::cin >> rowStart >> colStart >> rowEnd >> colEnd;


    int upDown = shortestPathUpDown(matrix, visited, n, m, rowStart, colStart, rowEnd, colEnd);
    int leftRight = shortestPathLeftRight(matrix, visited, n, m, rowStart, colStart, rowEnd, colEnd);

    std::cout << min(upDown, leftRight) << std::endl;

    return 0;
}

int max ( int a, int b)
{
    return a > b ? a : b;
}
int maxFour(int a, int b, int c , int d)
{
    return max(max(max(a,b), c), d);
}
//zero for black, one for white
int countAreaOfColors(int matrix[][100], int color, int row, int col, int n, int m, bool visited[][100], int sum = 0)
{
    if (col >= m || col < 0 || row >= n || row < 0) {
        return 0;
    }
    if ( visited[row][col] || matrix[row][col] != color ) {
        return 0;
    }
    visited[row][col] = true;

    int downWards = countAreaOfColors(matrix, color, row + 1, col, n, m, visited,sum + 1 );
    int upWards = countAreaOfColors(matrix, color, row - 1, col, n, m,visited, sum + 1);
    int right = countAreaOfColors(matrix, color, row, col + 1, n, m, visited, sum + 1);
    int left = countAreaOfColors(matrix, color, row, col - 1, n, m, visited, sum + 1);

    return  1 + downWards + upWards + right + left;
}

int main() {
    int matrix[100][100];
    int n, m;
    std::cout << "Enter n and m:";
    std::cin >> n >> m;
    bool visited[100][100] = {false};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    int color;
    std::cout << "Enter color:";
    std::cin >> color;

    if (color < 0 || color > 1) {
        std::cerr << "Invalid data entered!";
        return -1;
    }
    int * arrayWithAreaSize = new int [n*m/2];
    int occupiedAreas = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j] == color && !visited[i][j])
            {
                arrayWithAreaSize[occupiedAreas] = countAreaOfColors(matrix, color, i, j, n, m, visited);
                if(arrayWithAreaSize[occupiedAreas] > 1)
                {
                    occupiedAreas++;
                }
            }
        }
    }
    std::cout<<"Areas with color: "<<color<<std::endl;
    std::cout<<occupiedAreas<<std::endl;
    for (int i = 0; i < occupiedAreas; ++i) {
        std::cout<<arrayWithAreaSize[i]<<std::endl;
    }
    delete [] arrayWithAreaSize;
    arrayWithAreaSize = nullptr;



    return 0;
}
bool wordIsInsideMatrix(char matrix[][100], char * word, int n, int m, int iterator, int currRow, int currCol)
{
    if(iterator == strlen(word))
        return true;
    if(currCol < 0 || currRow < 0 || currCol >= n || currRow >=m)
        return false;
    if(matrix[currRow][currCol] != word[iterator])
        return false;
    return wordIsInsideMatrix(matrix, word , n, m, iterator +1, currRow + 1, currCol + 1)
            || wordIsInsideMatrix(matrix, word , n, m, iterator +1, currRow - 1, currCol + 1)
            || wordIsInsideMatrix(matrix, word, n, m, iterator +1, currRow - 1, currCol - 1)
            || wordIsInsideMatrix(matrix, word , n, m, iterator +1, currRow + 1, currCol - 1);
}
int main2()
{
    char word[100];
    std::cout<<"Enter word:";
    std::cin>>word;
    
    char matrix[100][100];
    int n, m;
    std::cout<<"Enter m and n:";
    std::cin>>m>>n;

    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n ; ++j) {
            std::cin>>matrix[i][j];
        }
    }

    int row = 0, col = 0;
    while(matrix[row][col] != word[0])
    {
        col++;
        if(col >= n)
        {
            row++;
            col = 0;
        }
    }
    std::cout<<wordIsInsideMatrix(matrix, word, n, m, 0, row , col) << std::endl;


    return 0;
}