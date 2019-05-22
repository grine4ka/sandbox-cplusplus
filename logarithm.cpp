#include <iostream>
using namespace std;

int log2(int num);

int main()
{
    int lines = 0;
    cin >> lines;
    int *nums = new int[lines];
    for (int i = 0; i < lines; i++) {
        int num;
        cin >> num;
        nums[i] = num;
    }
    for (int j = 0; j < lines; j++) {
        cout << log2(nums[j]) << endl;
    }
    return 0;
}

int log2(int num)
{
    int power = 0;
    int exponentedNum = 1;
    for (power = 0; exponentedNum <= num; power++) {
        exponentedNum *= 2;
    }
    return --power;
}
