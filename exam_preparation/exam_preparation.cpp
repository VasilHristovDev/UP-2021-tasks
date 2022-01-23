#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;
bool isPowerOfTwo(int n)
{
    if (n == 1)
        return true;
    if(n % 2 == 0)
        return isPowerOfTwo(n / 2);
    return false;
}

int main1()
{
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    int matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            std::cin>>matrix[i][j];
        }
    }

    int sum = 0;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            if(i == j)
                sum +=matrix[i][j];
        }
    }
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n ; ++j) {
            if(i == n - 1 - j)
                sum +=matrix[i][j];
        }
    }
    sum = sum - matrix[n/2][n/2];
    std::cout<<sum<<std::endl;
    if(isPowerOfTwo(sum))
        std::cout<<"Yes";
    else
        std::cout<<"No";

    return 0;

}
bool isLetter(char c)
{
    return ('a'<= c && c <='z') || ('A' <=c && c <= 'Z');
}
bool areAnagrams(char * firstSentence, char * secondSentence)
{
    unsigned sizeSentence1 = strlen(firstSentence);
    unsigned sizeSentence2 = strlen(secondSentence);

    bool flag = false;
    for (int i = 0; i < sizeSentence1 ; ++i) {
        flag = false;
        if(!isLetter(firstSentence[i])) i++;

        for (int j = 0; j < sizeSentence2 && !flag; ++j) {
            if(firstSentence[i] == secondSentence[j] || (firstSentence[i] - 'a'+'A') == secondSentence[j] || firstSentence[i] == (secondSentence[j]-'a'+'A'))
            {
                secondSentence[j] = ' ';
                flag = true;
            }
        }
    }
    int currentCharSecondSentence  = 0;
    int characters = 0;
    while(secondSentence[currentCharSecondSentence])
    {
        if(isLetter(secondSentence[currentCharSecondSentence]))
            characters++;
        currentCharSecondSentence++;
    }
    if(characters == 0)
        return true;

    return false;
}
int main2()
{
    char firstSentence[MAX_SIZE];
    char secondSentence[MAX_SIZE];

    std::cout<<"Enter first sentence:";
    std::cin.getline(firstSentence,MAX_SIZE);

    std::cout<<"Enter second sentence:";
    std::cin.getline(secondSentence,MAX_SIZE);

    std::cout<<(areAnagrams(firstSentence,secondSentence) ? "YES": "NO")<<std::endl;

    return 0;
}
double productNumbers(double array[], int n)
{
    if(n == 0)
        return 1;
    if(array[n] > 0 && array[n-1] > array[n])
        return array[n] * productNumbers(array, n -1);
    return productNumbers(array, n - 1);
}
int main()
{
    double array[MAX_SIZE];
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;

    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
    }

    double product = productNumbers(array,n);
    std::cout<<product<<std::endl;

    return 0;
}
