#include "header.h"
#include "class.cpp"



vector< vector < block > > create()
{
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

    for(int i = 0 ; i < 6 ; i++)
    {
        for(int j = 0 ; j < 6 ; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return grid;

}
