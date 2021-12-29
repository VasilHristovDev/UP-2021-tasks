#include <iostream>
unsigned length(const char str[])
{
    unsigned int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

const int MAX_SIZE = 100;
//1a
int main0a()
{
    char str[MAX_SIZE];
    std::cin>>str;

    char temp[MAX_SIZE];
    for (int i = 0; i < length(str); ++i) {
        temp[i] = str[i];
    }

    for (int i = 0; i < length(str); ++i) {
        str[i] = temp[length(str) - i - 1];
    }

   std::cout<<str<<std::endl;
    return 0;
}
//0b
int main0b()
{
    char str[MAX_SIZE];
    std::cin.getline(str,MAX_SIZE);

    char temp[MAX_SIZE];

    for (int i = 0; i < length(str) ; ++i) {
        temp[i] = str[i];
    }

    for (int i = 0; i < length(str) ; ++i) {
        str[i] = temp[length(str) - i - 1];
    }
    std::cout<<str<<std::endl;

    return 0;
}
unsigned countVowels(const char str[])
{
    int vowelsCounter = 0;
    unsigned i = 0;
    while(str[i])
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i' || str[i] == 'y')
        {
            vowelsCounter++;
        }
        i++;
    }
    return vowelsCounter;
}

int main1()
{
    char str[MAX_SIZE];
    std::cin>>str;

    std::cout<<"Number of vowels in str is: "<<countVowels(str)<<std::endl;
    return 0;
}

void capitalize(const char str[])
{
    int i = 0;
    char temp[MAX_SIZE];
    for (int j = 0; j < length(str); ++j) {
        temp[j] = str[j];
    }

    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            temp[i] =  str[i] - 'a' + 'A';
        }
        i++;
    }
    for (int j = 0; j < length(str) ; ++j) {
        std::cout<<temp[j];
    }
    std::cout<<std::endl;
}
int main2()
{
    char str[MAX_SIZE];

    std::cin.getline(str, MAX_SIZE);

    capitalize(str);
    return 0;
}
//char alphabetLower [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't','u','v','w','x','y','z'};
//char alphabetCapital [] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'n', 'o', 'p', 'r', 's', 't','u','v','w','x','y','z'};

int main3()
{
    int letterCounters[26] {0};
    char str [MAX_SIZE];
    
    std::cin>>str;
    unsigned i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            letterCounters[str[i] - 'a']++;
        }
        i++;
    }
    std::cout<<"[ ";
    for (int letterCounter : letterCounters) {
        std::cout<<letterCounter<<", ";
    }
    std::cout<<"];";
    return 0;
}
void removeElementsFromArrayInString(char str[], const char array[], int n)
{
    unsigned sizeString = length(str);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sizeString ; ++j) {
            if(str[j] == array[i])
            {
                for (int k = j + 1; k < sizeString ; ++k) {
                    str[k- 1] = str[k];
                }
                sizeString--;
            }
        }
    }
    for (int i = 0; i < sizeString ; ++i) {
        std::cout<<str[i];
    }
}
int main4()
{
    char str[MAX_SIZE];
    char array[MAX_SIZE];

    int n;

    std::cout<<"Enter the string:";
    std::cin>>str;

    std::cout<<"Enter number of elements in the array:";
    std::cin>>n;
    std::cout<<"Enter the array of chars:";
    for (int i = 0; i < n; ++i) {
        std::cout<<"array["<<i<<"]:";
        std::cin>>array[i];
    }

    removeElementsFromArrayInString(str,array,n);


    return 0;
}
int timesArrayIsSubArray(char str[], const char subStr[])
{
    int count = 0;
    unsigned strLen = length(str);
    unsigned subStrLen = length(subStr);
    int i,j = 0;
    for (i = 0; i <= strLen - subStrLen; i++) {
        int j;
        bool flag = false;
        for (j = 0; j  < subStrLen && !flag; j++) {
            if(str[i + j] != subStr[j])
                flag = true;
        }
        if (!flag)
        {
            count++;
        }


    }
   return count;
}
int main5()
{
    char str[MAX_SIZE];
    char subStr[MAX_SIZE];

    std::cout<<"Enter the string:";
    std::cin>>str;

    std::cout<<"Enter the substring:";
    std::cin>>subStr;
    
    std::cout<<timesArrayIsSubArray(str,subStr)<<" "<<std::endl;

    return 0;
}
int main6()
{
    char str[MAX_SIZE];
    std::cout<<"Enter the string:";
    std::cin.getline(str, MAX_SIZE);

    for (int i = 0; i < length(str) ; ++i) {
        std::cout<<str[i];
        if(str[i + 1] == ' ')
        {
            std::cout<<'\n';
            i++;
        }
    }
    return 0;
}
bool isPalindrome(const char str[], int size)
{
    bool returnable = true;

    unsigned i = 0;
    while(i!=size && returnable)
    {

        if(str[i] != str[size - i - 1])
        {
            returnable = false;
        }
        i++;
    }

    return returnable;
}
int countPalindromeWordsInString(const char str[])
{
    int palindromeCounter = 0;
    char tempWord[MAX_SIZE];
    int tempIterator = 0;
    for (int i = 0; i < length(str) ; ++i) {
        tempWord[tempIterator++] = str[i];
        if(str[i + 1] == ' ')
        {
            if(isPalindrome(tempWord, tempIterator))
                palindromeCounter++;
            i++;
            tempIterator = 0;
        }
    }

    if(isPalindrome(tempWord, tempIterator)) palindromeCounter++;

    return palindromeCounter;
}
int main7()
{
    char str[MAX_SIZE];

    std::cin.getline(str, MAX_SIZE);

    std::cout<<"Count of palindrome words in string: "<<countPalindromeWordsInString(str)<<std::endl;
    return 0;
}
int modifiedTimesIsSubarray(const char str[], const char subStr[], unsigned sizeStr, int sizeSubStr)
{
    int count = 0;
    int i,j = 0;
    for (i = 0; i <= sizeStr - sizeSubStr ; i++) {
        int j;
        bool flag = false;
        for (j = 0; j  < sizeSubStr  && !flag; j++) {
            if(str[i + j] != subStr[j])
                flag = true;
        }
        if (!flag)
        {
            count++;
        }

    }
    return count;
}
void mostCommonWord(const char str[]) {
    char tempWord[MAX_SIZE];
    int tempIndex = 0;
    int counter = 0;
    int maxCounter = 0;
    char mostCommonWordStr[MAX_SIZE];
    int lengthOfMostCommonWord = 0;
    for (int i = 0; i < length(str); ++i) {
        tempWord[tempIndex++] = str[i];
        if (str[i + 1] == ' ') {
            counter = modifiedTimesIsSubarray(str, tempWord, length(str), tempIndex);
            if(counter > maxCounter)
            {
                maxCounter = counter;
                for (int j = 0; j < tempIndex; ++j) {
                    mostCommonWordStr[j] = tempWord[j];
                }
                lengthOfMostCommonWord = tempIndex;
            }
            i++;
            tempIndex = 0;
        }
    }
    for (int i = 0; i < lengthOfMostCommonWord ; ++i) {
        std::cout<<mostCommonWordStr[i];
    }
}
int main8()
{
    char str[MAX_SIZE];
    std::cin.getline(str,MAX_SIZE);

    mostCommonWord(str);
    return 0;
}
unsigned sizeOfLongestPrefixSuffix(const char str[])
{
    unsigned strLen = length(str);
    unsigned i = 1;
    unsigned len = 0;
    if(strLen < 2)
    {
        return 0;
    }
    while ( i < strLen)
    {
        if(str[i] == str[len])
        {
            len++;
            i++;
        }
        else
        {
            i = i - len + 1;
            len = 0;
        }
    }

    return len >= strLen / 2 ? len / 2 : len;
}
int main()
{
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);
    for (int i = 0; i < sizeOfLongestPrefixSuffix(str) ; ++i) {
        std::cout<<str[i];
    }
    return 0;
}

