#pragma comment(linker, "/Stack:5000000000")

#include <iostream>

using namespace std;

const int MAX_M = 5;
const int MAX_N = 20000000;

long long ack(const int m, const int n)
{

    static long long memory[MAX_M][MAX_N];
    long long& function = memory[m][n];

    if (!function)
    {
        function = (m == 0) ? n + 1 :
            (n == 0) ? ack(m - 1, 1) :
            ack(m - 1, ack(m, n - 1));
    }
    return function;
}

int main()
{
    cout << "An ackermann function:" << endl;
    cout << ack(1, 2) << endl;
    cout << ack(2, 1) << endl;
    cout << ack(2, 2) << endl;
    cout << ack(3, 20) << endl;
    cout << ack(4, 0) << endl;
    cout << ack(4, 1) << endl;
    cout << "End of values from the ackermann function." << endl;
}
