/***
    Name:       Calista Lai
    Date:       Oct 15 2019
    Purpose:    to create a tic tac toe game



    player:     x   1
    computer:   o   0
***/

#include <iostream>
#include <string>

using namespace std;

enum markers{x, o, _};

class board{
public:
    //void board(int);
    board();
    void placeMarker(int);
    int isOccupied(int);
    //int legalPosition(int);
    int checkWin();
    void changeTurn();
    void declarePlayer();
    void gridOutput();
private:
    markers grid[3][3];
    markers player;
};
///yeet in all the blanks
board::board(){
    int r, y;
    for(r=0; r<3; r++){
        for(y=0; y<3; y++){
            grid[r][y] = _;
        }
    }
    player = x;
}
///I think this function is self-explanatory
///but in case it isn't: it places the marker
///on the position the user wishes
void board::placeMarker(int pos){
    int r, y;

    for(r=0; r<3; r++){
        for(y=1; y<=3; y++){
            if(((3*r) + y) == pos && grid[r][y-1] == _){
                //cout<<(3*r) +y<<endl;
                grid[r][y-1] = player;
                changeTurn();
            }
        }
    }

}

///checks to see if the position they entered
///is already taken by opponent. I wouldn't
///normally create a separate function for this
///but Ali would kill me if I used a break.
int board::isOccupied(int pos){
    int row, col, r,  y;

    for(r=0; r<3; r++){
        for(y=1; y<=3; y++){
            if(((3*r) + y) == pos){
                row = r;
                col = y-1;
            }
        }
    }

    if(grid[row][col] != _){
        return -1; /// occupied
    }
    else{
        return 1; /// empty
    }
}

int board::checkWin(){
    int r, c, flag=0;

    ///checks to see if the board has space
    for(r=0; r<3; r++){
        for(c=0; c<3; c++){
            if(grid[r][c] == _){
                flag=1;
            }
        }
    }

    if(flag == 1){
        for(r=0; r<3; r++){
            /// check for horizontal wins
            if(grid[r][0] == grid[r][1] && grid[r][0] ==grid[r][2] && grid[r][0] != _){
                return 1;
            }
            /// check for vertical wins
            else if(grid[0][r] == grid[1][r] && grid[0][r]== grid[2][r] && grid[0][r] != _){
                return 1;
            }
        }
        ///diagonals:
        if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != _){
            return 1;
        }
        else if(grid[0][2] == grid[1][1] && grid[0][2] ==grid[2][0] && grid[0][2] != _){
            return 1;
        }
        ///no wins:
        else{
            return -1;
        }
    }
    else{
        //return 2;
        for(r=0; r<3; r++){
            /// check for horizontal wins
            if(grid[r][0] == grid[r][1] && grid[r][0] ==grid[r][2] && grid[r][0] != _){
                return 1;
            }
            /// check for vertical wins
            else if(grid[0][r] == grid[1][r] && grid[0][r]== grid[2][r] && grid[0][r] != _){
                return 1;
            }
        }
        ///diagonals:
        if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != _){
            return 1;
        }
        else if(grid[0][2] == grid[1][1] && grid[0][2] ==grid[2][0] && grid[0][2] != _){
            return 1;
        }
        ///no wins:
        else{
            return 2;
        }
    }

    //*/

}
///idk man
void board::changeTurn(){
    if(checkWin() == -1){
        if(player == x){
            player = o;
        }
        else if(player == o){
            player = x;
        }
        //return player;
    }

}
void board::declarePlayer(){
    if(player == x){
        cout<<"x";
    }
    else if(player == o){
        cout<<"o";
    }
}
///spits out the updated board
void board::gridOutput(){
    int x, y;
    char symbol;

    for(x=0; x<3; x++){
        for(y=0; y<3; y++){
            if(grid[x][y]==2){
                symbol = '_';
            }
            else if(grid[x][y]==1){
                symbol = 'o';
            }
            else if(grid[x][y]==0){
                symbol = 'x';
            }
            cout<<symbol<<" ";
        }
        cout<<endl;
    }
}
///------------------------------------------------///
int main(){
    board grid;
    int x=1, position, player = 1;
    char symbol;

cout<<"Welcome to Tic Tac Toe!"<<endl;
cout<<"To play, choose a position (1-9) to place your marker."<<endl;
cout<<" 1 | 2 | 3 "<<endl;
cout<<"-----------"<<endl;
cout<<" 4 | 5 | 6 "<<endl;
cout<<"-----------"<<endl;
cout<<" 7 | 8 | 9 "<<endl;


///actual game, maybe
    while(x==1){
        cout<<"Enter position for player ";grid.declarePlayer();cout<<":  ";
        cin>>position;

        if(grid.isOccupied(position)== 1){
            grid.placeMarker(position);
        }
        else{
            cout<<"That spot's taken. Pick another one."<<endl;
        }

        ///check for wins
        if(grid.checkWin()==1){
            cout<<"======================================"<<endl;
            cout<<"PLAYER ";grid.declarePlayer();cout<<" WINS"<<endl;
            cout<<"======================================"<<endl;
            x = 42;
        }
        else if(grid.checkWin() == 2){
            cout<<"======================================"<<endl;
            cout<<"TIE"<<endl;
            cout<<"======================================"<<endl;
            x = 42;
        }

        grid.gridOutput();
        cout<<endl;
    }


    return 0;
}
