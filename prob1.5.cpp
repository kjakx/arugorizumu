#include <iostream>

using namespace std;

int gcd_euclid(int, int);

int main()
{   
    int p, q;
    int gcd;
    cin >> p >> q;
    gcd = gcd_euclid(p, q);
    cout << gcd << endl;
    return 0;
}

int gcd_euclid(int p, int q)
{
    int r, tmp, gcd;
    while (true)
    {
        r = p % q;
        if (r == 0)
        {
            gcd = q;
            break;
        }
        else
        {
            p = q;
            q = r;
        }
    }
    return gcd;
}