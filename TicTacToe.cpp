int main()
{
    r[0].Right = 79 ;
    r[0].Bottom = 23 ;
    SetConsoleTitle("                                                                      XO Game By Mabrouk");
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    info.dwSize = 100;
    info.bVisible = FALSE;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut,TRUE,r);
    SetConsoleCursorInfo(hOut, &info);
    Start_menu();
}

void Start_menu()
{
    COORD menu1 ;
    COORD menu2 ;
    margins.X = 0 , margins.Y = 7 ;
    menu2.X = 34 , menu2.Y = 3 ;
    menu1.X = 34 , menu1.Y = 5 ;
    cout <<"                                 Select  Mode\n";
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,margins);
    cout << "--------------------------------------------------------------------------------";
    string sp = " 1 Player " , sp2="-1 Player-", mp = " 2 Players ",mp2 ="-2 Players-" ;
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    while (ReadConsoleInput(hIn,&InRec,1,&NumRead))
    {
        if(InRec.Event.MouseEvent.dwMousePosition.X<=menu2.X+8&&InRec.Event.MouseEvent.dwMousePosition.X>=menu2.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==menu2.Y)
        {
            SetConsoleCursorPosition(hOut,menu2);
            cout << sp2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                single_start();
                break;
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,menu2);
            cout << sp ;
        }
        if(InRec.Event.MouseEvent.dwMousePosition.X<=menu1.X+9&&InRec.Event.MouseEvent.dwMousePosition.X>=menu1.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==menu1.Y)
        {
            SetConsoleCursorPosition(hOut,menu1);
            cout << mp2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                multi_start();
                break ;
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,menu1);
            cout << mp ;
        }
    }
}
void multi_start()
{
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    cout << endl;
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,margins);
    cout << "--------------------------------------------------------------------------------";
    COORD choose ;
    COORD which ;
    choose.X = 27 , choose.Y =3;
    which.X = 35 , which.Y = 5;
    SetConsoleCursorPosition(hOut,choose);
    cout << "Choose a mark for Player 1" ;
    SetConsoleCursorPosition(hOut,which);
    cout << "X       O" ;
    while (true)
    {
        ReadConsoleInput(hIn,&InRec,1,&NumRead);
        if (InRec.Event.MouseEvent.dwMousePosition.X==which.X&& InRec.Event.MouseEvent.dwMousePosition.Y==which.Y)
        {
            if (InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                Player1 = 'X' ;
                Player2 = 'O' ;
                system("cls");
                display();
                multi_game();
            }
        }
        else if (InRec.Event.MouseEvent.dwMousePosition.X==which.X+8&& InRec.Event.MouseEvent.dwMousePosition.Y==which.Y)
        {
            if (InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                Player1 = 'O' ;
                Player2 = 'X' ;
                system("cls");
                display();
                multi_game();
            }
        }
    }
}
void single_start()
{
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    cout << endl;
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,margins);
    cout << "--------------------------------------------------------------------------------";
    COORD choose ;
    COORD which ;
    choose.X = 27 , choose.Y =3;
    which.X = 35 , which.Y = 5;
    SetConsoleCursorPosition(hOut,choose);
    cout << "Choose a mark for PLayer" ;
    SetConsoleCursorPosition(hOut,which);
    cout << "X       O" ;
    while (true)
    {
        ReadConsoleInput(hIn,&InRec,1,&NumRead);
        if (InRec.Event.MouseEvent.dwMousePosition.X==which.X&& InRec.Event.MouseEvent.dwMousePosition.Y==which.Y)
        {
            if (InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                Player1 = 'X' ;
                Player2 = 'O' ;
                system("cls");
                display();
                single_game();
            }
        }
        else if (InRec.Event.MouseEvent.dwMousePosition.X==which.X+8&& InRec.Event.MouseEvent.dwMousePosition.Y==which.Y)
        {
            if (InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                Player1 = 'O' ;
                Player2 = 'X' ;
                system("cls");
                display();
                single_game();
            }
        }
    }
}
void display()
{
    COORD grid ={33,2};
    COORD gamemarg = {0,10};
    cout << "                    (click where you want to make your move)"<<endl;
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,gamemarg);
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,{0,12});
    cout << "--------------------------------------------------------------------------------";
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|---|---|---|";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|   |   |   |";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|---|---|---|";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|   |   |   |";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|---|---|---|";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|   |   |   |";
    grid.Y ++ ;
    SetConsoleCursorPosition(hOut,grid);
    cout <<"|---|---|---|";
}
bool sm1won(char arr[3][3])
{
    if(arr[1][0]!=' ' && arr[1][0]==arr[0][0] &&arr[1][0]==arr[2][0])
    {
        return true ;
    }
    if(arr[1][1]!=' ' && arr[1][1]==arr[0][1] &&arr[1][1]==arr[2][1])
    {
        return true ;
    }
    if(arr[1][2]!=' ' && arr[1][2]==arr[0][2] &&arr[1][2]==arr[2][2])
    {
        return true ;
    }
    if(arr[0][1]!=' ' && arr[0][1]==arr[0][0] &&arr[0][1]==arr[0][2])
    {
        return true;
    }
    if(arr[1][1]!=' ' && arr[1][1]==arr[1][0] &&arr[1][1]==arr[1][2])
    {
        return true;
    }
    if(arr[2][1]!=' ' && arr[2][1]==arr[2][0] &&arr[2][1]==arr[2][2])
    {
        return true;
    }
    if(arr[1][1]!=' ' && arr [1][1] == arr[0][0] && arr [1][1] == arr [2][2])
    {
        return true;
    }
    if(arr[1][1]!=' ' && arr [1][1] == arr[2][0] &&  arr [1][1] == arr [0][2])
    {
        return true;
    }
    return false ;
}
void multi_game()
{
    bool continueme = true , won = false ;
    COORD game_chars [3][3];
    COORD turn = {28 , 11} ;
    COORD retry = {34 , 14};
    COORD returntom = {32 , 16};
    for (int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j<3 ; j ++)
        {
            game_chars[i][j].X=35+j*4;
            game_chars[i][j].Y=3+i*2;
        }
    }
    char XO [3][3] = {{' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}};
    for(int k = 0 ; k < 9 && !won  ;k++)
    {
        SetConsoleCursorPosition(hOut,turn);
        if(k%2 == 0)
        {
            cout << "It's Player1" <<" turn [ " << Player1 << " ]";
        }
        else
        {
            cout << "It's Player2"<<" turn [ " << Player2 << " ]";
        }
        while(continueme)
        {
            SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
            ReadConsoleInput(hIn,&InRec,1,&NumRead);
            for (int i = 0 ; i < 3 ; i ++)
            {
                for(int j = 0 ; j<3 ; j ++)
                {
                    if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        if(InRec.Event.MouseEvent.dwMousePosition.X >= game_chars[i][j].X-1&& InRec.Event.MouseEvent.dwMousePosition.X <= game_chars[i][j].X+1&&InRec.Event.MouseEvent.dwMousePosition.Y==game_chars[i][j].Y)
                        {
                            if (k%2==0&&XO[i][j]==' ')
                            {
                                XO[i][j] = Player1;
                                SetConsoleCursorPosition(hOut,game_chars[i][j]);
                                cout << Player1;
                                if(k>3)
                                {
                                    won = sm1won(XO);
                                }
                                continueme = false ;
                            }
                            else if (k%2!=0&&XO[i][j]==' ')
                            {
                                XO[i][j] = Player2;
                                SetConsoleCursorPosition(hOut,game_chars[i][j]);
                                cout << Player2;
                                if(k>3)
                                {
                                    won = sm1won(XO);
                                }
                                continueme = false ;
                            }
                        }
                    }
                }
            }
        }
        continueme = true ;
        if (won)
        {
            SetConsoleCursorPosition(hOut,turn);
            if(k%2==0)
            {
                cout << "      Player1 Won!      ";
            }
            else
            {
                cout << "      Player2 Won!      ";
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,turn);
            if (k == 8)
            {
                cout << "   The Game is a Tie!    ";
            }
        }
    }
    string pa = " Play Again " , pa2="-Play Again-", rm = " Return to Menu ",rm2 ="-Return to Menu-" ;
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    while (ReadConsoleInput(hIn,&InRec,1,&NumRead))
    {
        if(InRec.Event.MouseEvent.dwMousePosition.X<=retry.X+11&&InRec.Event.MouseEvent.dwMousePosition.X>=retry.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==retry.Y)
        {
            SetConsoleCursorPosition(hOut,retry);
            cout << pa2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                multi_start();
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,retry);
            cout << pa ;
        }
        if(InRec.Event.MouseEvent.dwMousePosition.X<=returntom.X+14&&InRec.Event.MouseEvent.dwMousePosition.X>=returntom.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==returntom.Y)
        {
            SetConsoleCursorPosition(hOut,returntom);
            cout << rm2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                Start_menu();
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,returntom);
            cout << rm ;
        }
    }
}
void single_game()
{
    bool continueme = true , won = false ;
    int mr , mc ;
    COORD game_chars [3][3];
    COORD turn = {25 , 11} ;
    COORD retry = {34 , 14};
    COORD returntom = {32 , 16};
    for (int i = 0 ; i < 3 ; i ++)
    {
        for(int j = 0 ; j<3 ; j ++)
        {
            game_chars[i][j].X=35+j*4;
            game_chars[i][j].Y=3+i*2;
        }
    }
    SetConsoleCursorPosition(hOut,turn);
    cout << "Player " <<" [ " << Player1 << " ] | Computer" <<" [ " << Player2 << " ]";

    char XO [3][3] = {{' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}};
    for(int k = 0 ; k < 9 && !won  ;k++)
    {
        if(k%2==0)
        {

            while(continueme)
            {
                SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
                ReadConsoleInput(hIn,&InRec,1,&NumRead);
                for (int i = 0 ; i < 3 ; i ++)
                {
                    for(int j = 0 ; j<3 ; j ++)
                    {
                        if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                        {
                            if(InRec.Event.MouseEvent.dwMousePosition.X >= game_chars[i][j].X-1&& InRec.Event.MouseEvent.dwMousePosition.X <= game_chars[i][j].X+1&&InRec.Event.MouseEvent.dwMousePosition.Y==game_chars[i][j].Y)
                            {
                                if (k%2==0&&XO[i][j]==' ')
                                {
                                    XO[i][j] = Player1;
                                    SetConsoleCursorPosition(hOut,game_chars[i][j]);
                                    cout << Player1;
                                    if(k>3)
                                    {
                                        won = sm1won(XO);
                                    }
                                    continueme = false ;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            do
            {
                makebest(XO,mr,mc);
            }while(XO[mr][mc]!=' ');
            XO[mr][mc] = Player2;
            SetConsoleCursorPosition(hOut,game_chars[mr][mc]);
            cout << Player2;
            if(k>3)
            {
                won = sm1won(XO);
            }
        }
        continueme = true ;
        if (won)
        {
            SetConsoleCursorPosition(hOut,turn);
            if(k%2==0)
            {
                cout << "         Player Won!          ";
            }
            else
            {
                cout << "         Computer Won!         ";
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,turn);
            if (k == 8)
            {
                cout << "      The Game is a Tie!       ";
            }
        }
    }
    string pa = " Play Again " , pa2="-Play Again-", rm = " Return to Menu ",rm2 ="-Return to Menu-" ;
    SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
    while (ReadConsoleInput(hIn,&InRec,1,&NumRead))
    {
        if(InRec.Event.MouseEvent.dwMousePosition.X<=retry.X+11&&InRec.Event.MouseEvent.dwMousePosition.X>=retry.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==retry.Y)
        {
            SetConsoleCursorPosition(hOut,retry);
            cout << pa2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                single_start();
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,retry);
            cout << pa ;
        }
        if(InRec.Event.MouseEvent.dwMousePosition.X<=returntom.X+14&&InRec.Event.MouseEvent.dwMousePosition.X>=returntom.X+1&& InRec.Event.MouseEvent.dwMousePosition.Y==returntom.Y)
        {
            SetConsoleCursorPosition(hOut,returntom);
            cout << rm2 ;
            if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                system("cls");
                Start_menu();
            }
        }
        else
        {
            SetConsoleCursorPosition(hOut,returntom);
            cout << rm ;
        }
    }
}
void makebest(char arr[3][3],int &a , int &b)
{
    a = -1 ,b = -1 ;
    vector < pair <int,int> > v;
    vector < pair <int,int> > v2;
    int xs , os , spaces , ind ;
    for (int i = 0 ; i < 3 ; i++)
    {
        xs=0 , os=0 , spaces=0 ;
        for(int j = 0 ; j < 3 ; j++)
        {
            if (arr[i][j]==' ')
                spaces++;
            else if(arr[i][j]==Player1)
                xs++;
            else if (arr[i][j]==Player2)
                os++;
        }
        if(spaces==1 && (xs == 2 || os == 2))
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if (arr[i][j]==' ')
                {
                    a=i ;
                    b=j ;
                    if (os==2)
                    {
                        srand(time(0));
                        return ;
                    }
                }
            }
        }
        xs=0 , os=0 , spaces=0 ;
        for(int j = 0 ; j < 3 ; j++)
        {
            if (arr[j][i]==' ')
                spaces++;
            else if(arr[j][i]==Player1)
                xs++;
            else if (arr[j][i]==Player2)
                os++;
        }
        if(spaces==1 && (xs == 2 || os == 2))
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if (arr[j][i]==' ')
                {
                    a=j ;
                    b=i ;
                    if (os==2)
                    {
                        srand(time(0));
                        return ;
                    }
                }
            }
        }
    }
    xs=0 , os=0 , spaces=0 ;
    for ( int i = 0 ;i < 3 ; i++)
        {
        if(arr[i][i]==' ')
            spaces++;
        else if(arr[i][i]==Player1)
            xs++;
        else if (arr[i][i]==Player2)
            os++;
    }
    if(spaces==1 && (xs == 2 || os == 2))
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            if (arr[i][i]==' ')
            {
                a=i ;
                b=i ;
                if (os==2)
                {
                    srand(time(0));
                    return ;
                }
            }
        }
    }
    xs=0 , os=0 , spaces=0 ;
    for ( int i = 2 ;i >= 0 ; i--)
    {
        if(arr[2-i][i]==' ')
            spaces++;
        else if(arr[2-i][i]==Player1)
            xs++;
        else if (arr[2-i][i]==Player2)
            os++;
    }
    if(spaces==1 && (xs == 2 || os == 2))
    {
        for(int i = 2 ;i >= 0 ; i--)
        {
            if (arr[2-i][i]==' ')
            {
                a=2-i ;
                b=i ;
                if (os==2)
                {
                    srand(time(0));
                    return ;
                }
            }
        }
    }
    if(a==-1)
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            xs=0 , os=0 , spaces=0 ;
            v.clear();
            for(int j = 0 ; j < 3 ; j++)
            {
                if (arr[i][j]==' ')
                {
                    spaces++;
                    v.push_back(make_pair(i,j));
                }
                else if (arr[i][j]==Player2)
                    os++;
            }
            if(spaces==2 && ( os == 1) )
            {
                v2.insert(v2.begin(),v.begin(),v.end());
            }
        }
        for (int i = 0 ; i < 3 ; i++)
        {
            xs=0 , os=0 , spaces=0 ;
            v.clear();
            for(int j = 0 ; j < 3 ; j++)
            {
                if (arr[j][i]==' ')
                {
                    spaces++;
                    v.push_back(make_pair(j,i));
                }
                else if (arr[j][i]==Player2)
                    os++;
            }
            if(spaces==2 && ( os == 1))
            {
                v2.insert(v2.begin(),v.begin(),v.end());
            }
        }
        xs=0 , os=0 , spaces=0 ;
        v.clear();
        for(int i= 0 ; i < 3 ; i++)
        {
            if (arr[i][i]==' ')
            {
                spaces++;
                v.push_back(make_pair(i,i));
            }
            else if (arr[i][i]==Player2)
                os++;
        }
        if(spaces==2 && ( os == 1))
        {
            v2.insert(v2.begin(),v.begin(),v.end());
        }
        xs=0 , os=0 , spaces=0 ;
        v.clear();
        for(int i = 0 ; i < 3 ; i++)
        {
            if (arr[2-i][i]==' ')
            {
                spaces++;
                v.push_back(make_pair(2-i,i));
            }
            else if (arr[2-i][i]==Player2)
                os++;
        }
        if(spaces==2 && ( os == 1))
        {
            v2.insert(v2.begin(),v.begin(),v.end());
        }
        if(v2.size())
        {
            ind = rand()%v2.size();
            a = v2[ind].first;
            b = v2[ind].second;
        }
    }
    if(a==-1)
    {
        srand(time(0));
        v.clear();
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(arr[i][j]==' ')
                {
                    v.push_back(make_pair(i,j));
                }
            }
        }
        ind = rand()%v.size();
        a = v[ind].first;
        b = v[ind].second;
        srand(time(0));
        return;
    }
    srand(time(0));
    return ;
}
