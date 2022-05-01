#include <iostream>
#include <queue>
#include <algorithm>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
using namespace std;

void scan(int &angka)
{
    angka = 0;
    bool negative = false;
    char input = gc();
    while ((input < '0') || (input > '9'))
    {
        if (input == '-')
            negative = true;
        input = gc();
    }
    while (input >= '0' && input <= '9')
    {
        angka = (angka << 3) + (angka << 1) + input - 48;
        input = gc();
    }
    if (negative)
        angka = -angka;
}

void print(int angka)
{
    if (angka == 0)
    {
        pc('0');
        return;
    }
    else if (angka < 0)
    {
        pc('-');
        angka *= -1;
    }

    char number[20];
    short i = 0;
    while (angka > 0)
    {
        number[i++] = angka % 10 + '0';
        angka /= 10;
    }
    while (i--)
        pc(number[i]);
}

int n, m;
string labyrinth[1000];
pair<int, int> A, B;

void bfs(int x, int y)
{
    queue<pair<int, int>> arr;
    arr.push({x, y});
    while (!arr.empty())
    {
        x = arr.front().first;
        y = arr.front().second;
        arr.pop();
        if (x - 1 >= 0 && labyrinth[x - 1][y] == '.')
        {
            labyrinth[x - 1][y] = 'U';
            if (x - 1 == B.first && y == B.second)
                return;
            arr.push({x - 1, y});
        }
        if (y - 1 >= 0 && labyrinth[x][y - 1] == '.')
        {
            labyrinth[x][y - 1] = 'L';
            if (x == B.first && y - 1 == B.second)
                return;
            arr.push({x, y - 1});
        }
        if (x + 1 < n && labyrinth[x + 1][y] == '.')
        {
            labyrinth[x + 1][y] = 'D';
            if (x + 1 == B.first && y == B.second)
                return;
            arr.push({x + 1, y});
        }
        if (y + 1 < m && labyrinth[x][y + 1] == '.')
        {
            labyrinth[x][y + 1] = 'R';
            if (x == B.first && y + 1 == B.second)
                return;
            arr.push({x, y + 1});
        }
    }
}

string route()
{
    string way = "";
    int x = B.first, y = B.second;

    while (labyrinth[x][y] != 'A')
    {
        way += labyrinth[x][y];
        if (labyrinth[x][y] == 'U')
            x++;
        else if (labyrinth[x][y] == 'L')
            y++;
        else if (labyrinth[x][y] == 'D')
            x--;
        else if (labyrinth[x][y] == 'R')
            y--;
    }

    reverse(way.begin(), way.end());
    return way;
}

signed main()
{
    scan(n);
    scan(m);

    for (int i = 0; i < n; i++)
    {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++)
        {
            if (labyrinth[i][j] == 'A')
                A = {i, j};
            if (labyrinth[i][j] == 'B')
                B = {i, j};
        }
    }

    labyrinth[B.first][B.second] = '.';
    bfs(A.first, A.second);

    if (labyrinth[B.first][B.second] == '.')
    {
        pc('N');
        pc('O');
        pc('\n');
    }
    else
    {
        pc('Y');
        pc('E');
        pc('S');
        pc('\n');

        string result = route();
        print(result.length());
        pc('\n');

        cout << result;
        pc('\n');
    }
    return 0;
}