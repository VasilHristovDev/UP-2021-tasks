#include <iostream>
const int MAX_SIZE = 100;

bool numbersMakeSum(int * array, int n, int k, int current)
{
    if (k == 0)
        return true;

    if (current >= n)
        return false;

    bool sumWithNumber = numbersMakeSum(array, n,  k - array[current], current + 1);
    bool sumWithout = numbersMakeSum(array, n,  k, current + 1);

    return sumWithNumber || sumWithout;
}

int main1()
{
    int array[MAX_SIZE];
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        std::cin>>array[i];
    }

    int k;
    std::cout<<"Enter sum of elements:";
    std::cin>>k;

    std::cout<<(numbersMakeSum(array, n, k, 0) ? "It is possible" : "It is not possible")<<std::endl;

    return 0;
}
double averageOfArea(int matrix[][MAX_SIZE], int n, int m, int currRow, int currCol, bool visited[][MAX_SIZE], double sum , int& counter)
{

    if(currRow >= n || currRow < 0 || currCol < 0 || currCol >= m)
    {
        return 0;
    }
    if(visited[currRow][currCol] || matrix[currRow][currCol] == 0)
    {
        return 0;
    }
    visited[currRow][currCol] = true;
    counter++;
    double up = averageOfArea(matrix, n, m, currRow + 1, currCol, visited, sum + matrix[currRow][currCol], counter);
    double down = averageOfArea(matrix, n, m, currRow - 1, currCol, visited, sum + matrix[currRow][currCol], counter);
    double left = averageOfArea(matrix, n, m, currRow , currCol - 1, visited, sum + matrix[currRow][currCol], counter);
    double right = averageOfArea(matrix, n, m, currRow, currCol + 1, visited, sum + matrix[currRow][currCol], counter);
    double upRight = averageOfArea(matrix, n, m, currRow - 1, currCol + 1, visited, sum + matrix[currRow][currCol], counter);
    double upLeft = averageOfArea(matrix, n, m, currRow - 1, currCol - 1, visited, sum + matrix[currRow][currCol], counter);
    double downLeft = averageOfArea(matrix, n, m, currRow + 1, currCol - 1, visited, sum + matrix[currRow][currCol], counter);
    double downRight = averageOfArea(matrix, n, m, currRow + 1, currCol + 1, visited, sum + matrix[currRow][currCol], counter);
    matrix[currRow][currCol] = 0;
    std::cout<<currRow<<" "<<currCol<<" "<<sum + up + down +  left + right + downLeft + downRight + upLeft + upRight<<std::endl;
    return  sum + up + down +  left + right + downLeft + downRight + upLeft + upRight;
}
int main()
{
    int tv [MAX_SIZE][MAX_SIZE];
    int n,m;
    bool visited[MAX_SIZE][MAX_SIZE]{false};

    std::cout<<"Enter n and m:";
    std::cin>>n>>m;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin>>tv[i][j];
        }
    }

    int counter = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(tv[i][j]!=0 && !visited[i][j])
            {
                std::cout<<"( "<<i<<" , "<<j<<" )"<<" "<<std::endl;
                std::cout<<averageOfArea(tv,n,m,i,j,visited,0,counter)<<std::endl;
                counter = 0;
            }
        }
    }
    return 0;

}