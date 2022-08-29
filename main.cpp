#include <iostream>
#include <vector>
#include <string>

using namespace std;

int roll(int min, int max)
{
   // x is in [0,1[
   double x = rand()/static_cast<double>(RAND_MAX+1); 

   // [0,1[ * (max - min) + min is in [min,max[
   int that = min + static_cast<int>( x * (max - min) );

   return that;
}

char mapToChar(int in)
{
    switch(in)
    {
        case 1:
        return 'r';
        break;
        case 2:
        return 'p';
        break;
        case 3:
        return 's';
        default:
        return 100;
        break;
    }
}

int mapToInt(char in)
{
    switch(in)
    {
        case 'r':
        return 1;
        break;
        case 'p':
        return 2;
        break;
        case 's':
        return 3;
        default:
        return 100;
        break;
    }
}
                 /*user*/     /*r, p, s*/
int winMatrixForUser[3][3] = { {0, 1, -1},  /*r*/
                               {-1, 0, 1},  /*p*/
                               {1, -1, 0} }; /*s*/

enum GAMERES 
{
    WIN = 0,
    LOOSE,
    DRAW,
    NO_EVAL
};

string SpellGameRes(GAMERES in)
{
    switch(in)
    {
        case WIN:
        return "won";
        case LOOSE:
        return "lost";
        case DRAW:
        return "drew";
        case NO_EVAL:
        return "---";
    }
}
GAMERES DidUserWin(const int user, const int comp)
{
    int res = winMatrixForUser[comp-1][user-1];

    switch(res)
    {
        case 1:
        return  WIN;
        case 0:
        return DRAW;
        case -1:
        return LOOSE;
        default:
        return NO_EVAL;
    }
}

int main()
{
    int count_win = 0;
    int count_draw = 0;
    int count_loose = 0;
    int cout_error = 0;

    while(true)
    {
        cout << "*********************************************************"<<endl;
        cout << "Lets play rock, paper , scissors" << endl;
        cout << "enter r for rock, p for paper or s for scissors" << endl;

        char input;

        cin >> input;

        cout << "user input: " << input << endl;

        int outputComp = roll(1,4);

        char compRes = mapToChar(outputComp);
        cout << "computer says: " << compRes << endl;

        cout<< "Player:" << SpellGameRes(DidUserWin(mapToInt(input), mapToInt(compRes))) << endl;

        GAMERES result = DidUserWin(mapToInt(input), mapToInt(compRes));

        if(result==DRAW)
            count_draw++;
        else if(result==WIN)
            count_win++;
        else if(result==LOOSE)
            count_loose++;
        else
            cout_error++;
        
        cout << "win count: " << count_win << endl;
        cout << "loose count: " << count_loose << endl;
        cout << "draw count: " << count_draw << endl;

    }

    
}