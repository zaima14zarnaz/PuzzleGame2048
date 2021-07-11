#include<bits/stdc++.h>
#include <windows.h>

using namespace std;

class block
{
    bool lose = 0;
public:
    static bool win;
    int num;
    block()
    {
        num = 0;
    }
    block(int num)
    {
        this->num = num;
    }
    bool setwin(bool a)
    {
        win = a;
        return win;
    }
    bool getwin()
    {
        return win;
    }
    bool setlose(bool a)
    {
        lose = a;
        return lose;
    }
    bool getlose()
    {
        return lose;
    }
    friend ostream& operator<<(ostream &out, block a)
    {
        HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
        if(a.num == 0)
        {
            SetConsoleTextAttribute(color, 3);
            out << "|";
            SetConsoleTextAttribute(color, 15);
            out << setw(5) << " " << " ";
        }
        else
        {
            if(a.num == 2048)
            {
                a.win = 1;
            }
            SetConsoleTextAttribute(color, 3);
            out << "|";
            SetConsoleTextAttribute(color, 15);
            out << setw(5) << a.num << " ";
        }
        return out;
    }
    bool operator==(block a)
    {
        if(num == a.num) return 1;
        else return 0;
    }
    bool operator!=(int a)
    {
        if(num != a) return 1;
        else return 0;
    }
    block & operator=(block &a)
    {
        num = a.num;
        return *this;
    }
    void operator=(int a)
    {
        num = a;
    }
    block & operator+(block &a)
    {
        num = num + a.num;
        return *this;
    }
    int operator+(int x)
    {
        num = num + x;
        return num;
    }

};
bool block :: win ;
int score = 0;

vector<vector<block> > up(vector<vector<block> > grid)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 6 ; i++)
    {
        bool p = 0;
        for(int j = 0 ; j < 5 ; j++)
        {
            if(grid[j][i] == grid[j+1][i] && grid[j][i] != 0)
            {

                p = 1;
                grid[j][i] = grid[j][i] + grid[j+1][i];
                score = grid[j][i].num + score;
                for(int k = j + 1 ; k < 5 ; k++)
                {
                    grid[k][i] = grid[k+1][i];
                }
                grid[5][i] = 2;
            }
        }
        if(p == 0)
        {
            for(int j = 0 ; j < 5 ; j++)
            {
                if(grid[j][i] == 0)
                {
                    for(int k = j ; k < 5 ; k++)
                    {
                        grid[k][i] = grid[k + 1][i];
                    }
                    grid[5][i] = 0;
                    break;
                }
            }
        }
    }

    system("CLS");

    SetConsoleTextAttribute(color, 15);
    cout << "\n\n                                                                                                   Score : ";
    SetConsoleTextAttribute(color, 11);
    cout << setw(8) << score << endl ;
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 3);
    cout << "                                      ________________________________________________\n";
    for(int i = 0 ; i < 6 ; i++)
    {
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |       |       |       |       |       |       |\n";
        cout << "                                      " ;
        for(int j = 0 ; j < 6 ; j++)
        {
           if(j == 5){
                    cout << grid[i][j];
                    SetConsoleTextAttribute(color, 3);
            cout << " |";
            }
            else
            cout << grid[i][j] << " ";
        }
        cout << endl;
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |_______|_______|_______|_______|_______|_______|\n";

    }
    return grid;

}

vector<vector<block> > down(vector<vector<block> > grid)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 6 ; i++)
    {
        bool p = 0;
        for(int j = 5 ; j > 0 ; j--)
        {
            if(grid[j][i] == grid[j-1][i] && grid[j][i] != 0)
            {
                p = 1;
                grid[j][i] = grid[j][i] + grid[j-1][i];
                score = grid[j][i].num + score;
                for(int k = j - 1 ; k > 0 ; k--)
                {
                    grid[k][i] = grid[k-1][i];
                }
                grid[0][i] = 2;
            }
        }
        if(p == 0)
        {
            for(int j = 5 ; j > 0 ; j--)
            {
                if(grid[j][i] == 0)
                {
                    for(int k = j ; k > 0 ; k--)
                    {
                        grid[k][i] = grid[k - 1][i];
                    }
                    grid[0][i] = 0;
                    break;
                }
            }
        }
    }

    system("CLS");

    SetConsoleTextAttribute(color, 15);
    cout << "\n\n                                                                                                   Score : ";
    SetConsoleTextAttribute(color, 11);
    cout << setw(8) << score << endl ;
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 3);
    cout << "                                      ________________________________________________\n";
    for(int i = 0 ; i < 6 ; i++)
    {
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |       |       |       |       |       |       |\n";
        cout << "                                      " ;
        for(int j = 0 ; j < 6 ; j++)
        {
            if(j == 5){
                    cout << grid[i][j];
                    SetConsoleTextAttribute(color, 3);
            cout << " |";
            }
            else
            cout << grid[i][j] << " ";
        }
        cout << endl;
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |_______|_______|_______|_______|_______|_______|\n";

    }
    return grid;
}

vector<vector<block> > right(vector<vector<block> > grid)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 6 ; i ++)
    {
        bool p = 0;
        for(int j = 5 ; j > 0 ; j-- )
        {
            if(grid[i][j] == grid[i][j-1] && grid[i][j] != 0)
            {
                p = 1;
                grid[i][j] = grid[i][j] + grid[i][j - 1];
                score = grid[j][i].num + score;
                for(int k = j - 1; k > 0 ; k-- )
                {
                    grid[i][k] = grid[i][k - 1];
                }
              //  cout << grid[i][0] << " ";
                grid[i][0] = 2;
            }
        }
        if(p == 0)
        {
        for(int j = 5 ; j > 0 ; j--)
        {
            if(grid[i][j] == 0)
            {
                for(int k = j ; k > 0 ; k--)
                {
                    grid[i][k] = grid[i][k-1];
                }
                grid[i][0] = 0;
                break;
            }
        }
        }
    }

    system("CLS");

    SetConsoleTextAttribute(color, 15);
    cout << "\n\n                                                                                                   Score : ";
    SetConsoleTextAttribute(color, 11);
    cout << setw(8) << score << endl ;
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 3);
    cout << "                                      ________________________________________________\n";
    for(int i = 0 ; i < 6 ; i++)
    {
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |       |       |       |       |       |       |\n";
        cout << "                                      " ;
        for(int j = 0 ; j < 6 ; j++)
        {
            if(j == 5){
                    cout << grid[i][j];
                    SetConsoleTextAttribute(color, 3);
            cout << " |";
            }
            else
            cout << grid[i][j] << " ";
        }
        cout << endl;
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |_______|_______|_______|_______|_______|_______|\n";

    }

    return grid;

}

vector<vector<block> > left(vector<vector<block> > grid)
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0 ; i < 6 ; i++)
    {
        bool p = 0;
        for(int j = 0 ; j < 6 ; j++)
        {
            if(grid[i][j] == grid[i][j+1] && grid[i][j] != 0)
            {
                p = 1;
                grid[i][j] = grid[i][j] + grid[i][j+1];
                score = grid[j][i].num + score;
                for(int k = j + 1 ; k < 5 ; k++)
                {
                    grid[i][k] = grid[i][k+1];
                }
                grid[i][5] = 2;
            }
        }
        if(p == 0)
        {
        for(int j = 0 ; j < 6 ; j++)
        {
            if(grid[i][j] == 0)
            {
                for(int k = j  ; k < 5 ; k++)
                {
                    grid[i][k] = grid[i][k+1];
                }
                grid[i][5] = 0;
                break;
            }
        }
        }
    }
    system("CLS");
    SetConsoleTextAttribute(color, 15);
    cout << "\n\n                                                                                                   Score : ";
    SetConsoleTextAttribute(color, 11);
    cout << setw(8) << score << endl ;
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 3);
    cout << "                                      ________________________________________________\n";
    for(int i = 0 ; i < 6 ; i++)
    {
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |       |       |       |       |       |       |\n";
        cout << "                                      " ;
        for(int j = 0 ; j < 6 ; j++)
        {
            if(j == 5){
                    cout << grid[i][j];
                    SetConsoleTextAttribute(color, 3);
            cout << " |";
            }
            else
            cout << grid[i][j] << " ";
        }
        cout << endl;
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |_______|_______|_______|_______|_______|_______|\n";

    }
    return grid;

}



vector<vector<block> > moves(char c,vector<vector<block> > grid)
{
    if(c == 'w' || c == 'W') grid = up(grid);
    else if(c == 's' || c == 'S') grid = down(grid);
    else if(c == 'a' || c == 'A') grid = left(grid);
    else if(c == 'd' || c == 'D') grid = right(grid);
    return grid;

}


vector< vector < block > > create()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    vector< vector < block > > grid;

    int n;
    int i = 0;
    int j = 1;
    string str;

    ifstream r;
    r.open("Initial.txt",ios::in);

    while(r)
    {
        r >> n;
        block a(n);

        grid.push_back(vector<block>());
        grid[i].push_back(a);

        j++;
        if(j > 6)
        {
            i++;
            j = 1;
        }

        if(i > 5) break;
    }

    SetConsoleTextAttribute(color, 15);
    cout << "\n\n                                                                                                   Score : ";
    SetConsoleTextAttribute(color, 11);
    cout << setw(8) << score << endl ;
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 3);
    cout << "                                      ________________________________________________\n";
    for(int i = 0 ; i < 6 ; i++)
    {
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |       |       |       |       |       |       |\n";
        cout << "                                      " ;
        for(int j = 0 ; j < 6 ; j++)
        {
            if(j == 5){
                    cout << grid[i][j];
                    SetConsoleTextAttribute(color, 3);
            cout << " |";
            }
            else
            cout << grid[i][j] << " ";
        }
        cout << endl;
        SetConsoleTextAttribute(color, 3);
        cout << "                                      |_______|_______|_______|_______|_______|_______|\n";

    }

    return grid;

}

int won()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(color, 12);
    cout << setw(65) << "Congratulaions\n\n";
    SetConsoleTextAttribute(color, 12);
    cout << setw(55) << " Score : ";
    SetConsoleTextAttribute(color, 15);
    cout << setw(8) << score << endl;
}

int play_again();


int main()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

    vector< vector < block > > grid;
    grid = create();

    char mov;

    while(1)
    {
    cout << endl << endl;
    SetConsoleTextAttribute(color, 15);
    cout << "                                                         Move : ";

    SetConsoleTextAttribute(color, 3);
    cin >> mov;

    if(mov == 'e')
    {
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << setw(60) << "Score : " << setw(7) << score << endl;
        getchar();
        getchar();
        play_again();

    }

    grid = moves(mov,grid);

    if(block :: win == true)
    {
        won();
        getchar();
        getchar();
        play_again();
    }


    }
}

int play_again()
{
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(color, 15);
    cout << "                                                      Play Again ?\n\n";
    SetConsoleTextAttribute(color, 13);
    cout << "                                                *******         ******\n";
    SetConsoleTextAttribute(color, 15);
    cout << "                                                  YES             NO\n";
    SetConsoleTextAttribute(color, 13);
    cout << "                                                *******         ******\n\n\n";
    SetConsoleTextAttribute(color, 15);
    cout << "                                                      Choice : ";

    string choice;
    cin >> choice;
    if(choice == "Yes"||choice == "YES" || choice == "yes" || choice == "Y" || choice == "y")
    {
        system("CLS");
        main();
    }
    else
        exit(1);

}
