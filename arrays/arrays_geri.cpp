#include <iostream>

//Да се напише програма, която прочита масив от числа и проверява дали има повтарящ се елемент в масива.
int main1() {
    int array[10];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (array[i] == array[j])
                flag = true;
        }
    }

    std::cout << (flag ? "it has" : "it doesn't have") << std::endl;
    return 0;
}

//Да се напише програма, която прочита масив от числа и намира максималната сума,
// която може да се получи от които и да е 2 елемента на масива.
int main2() {
    int array[10];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    int sum = 0;
    int maxSum = array[0] + array[1];

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum = array[i] + array[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    std::cout << maxSum << std::endl;

    return 0;
}

//Площадка в масив наричаме последователност от еднакви елементи.
//Да се напише програма, която прочита масив от числа и намира максималната по дължина площадка в масива.
int main3() {
    int array[10];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int sequence = 1;
    int maxSequence = 1;

    int prevElement = array[0];
    for (int i = 1; i < n; ++i) {
        if (array[i] == prevElement)
            sequence++;
        else {
            if(sequence > maxSequence) {
                maxSequence = sequence;
                sequence  = 1;
            }
        }
        prevElement = array[i];
    }
    std::cout<<maxSequence<<std::endl;

    return 0;
}
//Да се напише програма, която прочита масив от числа и го обръща (първия елемент става последен и т.н.)
int main4()
{
    int array[10];
    int n;

    std::cin>>n;
    int temp[10];

    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
        temp[i] = array[i];
    }

    for (int i = 0; i < n ; ++i) {
        array[i] = temp[n - i - 1];
    }

    for (int i = 0; i < n ; ++i) {
        std::cout<<array[i]<<" ";
    }
    return 0;
}
//Да се напише програма, която прочита масив от числа и казва всяка цифра по колко пъти се среща.
/*
 * [0] = 0
 * [1] = 1
 * [2] = 2
 * ...
 *
 */
void addToCounter(int * digitCounter, int number)
{
    if(number > 9)
    {
        while(number > 0)
        {
            digitCounter[number%10]++;
            number /= 10;
        }
    }
    else {
        digitCounter[number]++;
    }
}

int main()
{
    int array[100];
    int digitCounters[10] = {0};

    int n;
    std::cin>>n;
    for (int i = 0; i < n ; ++i) {
        std::cin>>array[i];
    }

    for (int i = 0; i < n ; ++i) {
        addToCounter(digitCounters,array[i]);
    }

    for (int i = 0; i < 10; ++i) {
        std::cout<<i<<": "<<digitCounters[i]<<std::endl;
    }
    return 0;
}

