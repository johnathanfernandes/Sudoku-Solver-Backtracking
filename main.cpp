#include<iostream>

using namespace std;

int i,j,n;
int board[9][9]={
                        {6,5,0,   8,7,3,   0,9,0},
                        {0,0,3,   2,5,0,   0,0,8},
                        {9,8,0,   1,0,4,   3,5,7},

                        {1,0,5,   0,0,0,   0,0,0},
                        {4,0,0,   0,0,0,   0,0,2},
                        {0,0,0,   0,0,0,   5,0,3},

                        {5,7,8,   3,0,1,   0,2,6},
                        {2,0,0,   0,4,8,   9,0,0},
                        {0,9,0,   6,2,5,   0,8,1},
                    };
bool row, col, sec;

void display();
bool solve();
bool inrow(int, int);
bool incol(int, int);
bool insec(int, int, int);
bool islegal(int, int, int);

int main()
{
    cout<<endl<<"Initial State:"<<endl;
    display();

    cout<<endl<<"Solving..."<<endl;
    solve();

    cout<<endl<<"Final State"<<endl;
    display();


    return 0;
}

void display()
{
    cout<<"+---+---+---+"<<endl;
    for(i=0;i<9;i++)
    {
        cout<<"|";

        for(j=0;j<9;j++)
        {
            cout<<board[i][j];
            //cout<<"    ";
            if(j==2 || j==5 || j==8)
                cout<<"|";
        }
        cout<<endl;
        if(i==2 || i==5 || i==8)
            cout<<"+---+---+---+"<<endl;
    }
}

bool solve()
	{
		for(int r=0; r<9; r++)
		{
			for(int c=0; c<9; c++)
			{
				if(board[r][c]==0)
				{
					for(int n=1; n<=9; n++)
					{
						if(islegal(r, c, n))
						{
							board[r][c]=n;
							if(solve())
							{
								return true;
							}
							else
							{
								board[r][c]=0;
							}
						}
					}
					return false;
				}
			}
		}
		return true;
	}

bool inrow (int r, int n)
{
    for(i=0; i<9; i++)
        if(board[r][i]==n)
            return true;

    return false;
}

bool incol (int c, int n)
{
    for(i=0; i<9; i++)
        if(board[i][c]==n)
            return true;

    return false;
}

bool insec (int r, int c, int n)
{
    r-=(r%3);
    c-=(c%3);

    for(i=r; i<r+3; i++)
        for(j=c; j<c+3;j++)
            if(board[i][j]==n)
                return true;

    return false;
}

bool islegal(int r, int c, int n)
{
    return !(inrow(r,n) || incol(c,n) || insec(r,c,n));
}

