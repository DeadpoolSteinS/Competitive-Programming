#include <cstdio>
#define pc putchar_unlocked
using namespace std;

void print(int angka)
{
    char number[10];
    short i = 0;
    if (angka == 0)
    {
        pc('0');
        return;
    }
    while (angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while (i--)
        pc(number[i]);
}

char board[8][8], col[8], bt[15], tb[15];
int ans;

void solve(int r)
{
    if (r == 8)
        ans++;
    else
    {
        for (int i = 0; i < 8; i++)
        {
            // check every box
            if (board[r][i] == '.' && !col[i] && !bt[r + i] && !tb[r - i + 7])
            {
                // box is used
                col[i] = bt[r + i] = tb[r - i + 7] = 1;
                solve(r + 1);
                // box is no longer used
                col[i] = bt[r + i] = tb[r - i + 7] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
        scanf("%s", board[i]);
    solve(0);
    print(ans);
    pc('\n');
    return 0;
}