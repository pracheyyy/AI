
#include <iostream>
using namespace std;

int main()
{
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter first 2x2 matrix:\n";

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter second 2x2 matrix:\n";

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> B[i][j];
        }
    }

    int a = A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];

    int e = B[0][0];
    int f = B[0][1];
    int g = B[1][0];
    int h = B[1][1];

    int M1 = (a + d) * (e + h);
    int M2 = (c + d) * e;
    int M3 = a * (f - h);
    int M4 = d * (g - e);
    int M5 = (a + b) * h;
    int M6 = (c - a) * (e + f);
    int M7 = (b - d) * (g + h);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;

    cout << "\nResultant Matrix:\n";

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
