
#include <iostream>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

//Prints the board to the screen
void _displayGrid(char Board[3][3]);

//Gets input from user and places token
void _getInput(char player, char Board[3][3]);

//Checks if one of the players have won
bool _checkForWins(char player, char Board[3][3]);

int Core();

/// --- This is main(), It does exactly what main() should, if you don't know what main does, go take a look at "c++ 101" or "c++ for dummies" --- \\\ 
int main(int argc, char *argv[]){ Core(); }


int Core(){


    //Weather the player chose to restart
    char restart = '-';

    //The current turn number
    int turnNumber = 0;

    //Player who's turn it is
    char currentPlayer = 'x';

    //Weather the game has finished yet or not
    bool finished = false;

    //Row chosen by the user to place on
    int chosenRow = 0;

    //Column chosen by the user to place on
    int chosenColumn = 0;

    //Holds values of every grid coordinate
    char gridHolder[3][3] = {{'-', '-', '-'},{'-', '-', '-'},{'-', '-', '-'}};

    
/*
          0,0  0,1  0,2
          1,0  1,1  1,2
          2,0  2,1  2,2
*/


    /// -- G a m e   L o o p -- \\\ 

    while (finished == false){

        

        //Increments turn number so that wins are only checked for after turn 5
        turnNumber += 1;

        //Player's turn
        cout << "\n Player " << currentPlayer << "'s turn:\n";
        _displayGrid(gridHolder);
        _getInput(currentPlayer, gridHolder);

        cout << turnNumber;

        //Checks for wins
        if (turnNumber >= 5)  {finished = _checkForWins(currentPlayer, gridHolder);}
        //Check for stalemate
        else if (turnNumber >= 9)  {finished = true;}

        //Changes who's turn it is
        if (finished == false){
            if ( currentPlayer == 'x' ){ currentPlayer = 'o'; }
            else if ( currentPlayer == 'o' ){ currentPlayer = 'x'; }
        }

    }

    /// -- W i n   M e s s a g e -- \\\ 

    if (turnNumber >= 9) {
    cout << "\n\n\n\n";
    _displayGrid(gridHolder);
    cout << "\n " << " S T A L E M A T E "; 

    }
    else{
    cout << "\n\n\n\n";
    _displayGrid(gridHolder);
    cout << "\n " << currentPlayer << "   W I N S !"; 
    }

    //Asks the player to play again
    cout << "\n Play again? y/n \n";
    cin >> restart;
    cout << "\n\n\n\n";
    if (restart == 'y'){
        Core();
    } 

    return 0;
}




void _displayGrid(char Board[3][3]){
    
    cout << "1 " << Board[0][0] << " " << Board[0][1] << " " << Board[0][2] << "\n" 
         << "2 " << Board[1][0] << " " << Board[1][1] << " " << Board[1][2] << "\n" 
         << "3 " << Board[2][0] << " " << Board[2][1] << " " << Board[2][2] << "\n";
    cout << "  1 2 3\n\n";
}



void _getInput(char player, char Board[3][3]){
    //Row chosen to place on by player
    int chosenRow = 0;
    //Column chosen to place on by player 
    int chosenColumn = 0;

    /// --- Get inputs from user
    cout << "Enter the Column you would like to place on \n";
    cin >> chosenColumn;
    cout << "\n";
    cout << "Enter the Row you would like to place on \n";
    cin  >> chosenRow;
    cout << "\n";

    /// --- Checks if move is valid
    //If valid change space and move on
    if (Board[chosenRow - 1][chosenColumn - 1] =='-') { Board[chosenRow - 1][chosenColumn - 1] = player; }

    //Otherwise print board and request inputs again
    else{ 
        cout << "That space is invalid or has a piece on it\n";
        system("pause");
        cout << "\n\n\n\n\n";
        _displayGrid(Board);
        _getInput(player, Board);
    }
}

bool _checkForWins(char player, char Board[3][3]){

    //Checks for horisontal wins
    for ( int i = 0; i <= 2; i++ ){

        if (Board[i][0] == player
            &&
            Board[i][1] == player
            &&
            Board[i][2] == player
            )
            { return true; }

    }

    //Checks for verticle wins
    for ( int i = 0; i <= 2; i++ ){

        if (Board[0][i] == player
            &&
            Board[1][i] == player
            &&
            Board[2][i] == player
            )
            { return true; }

    }

    //Checks for both types of diagonal wins
    if (Board[0][0] == player
        &&
        Board[1][1] == player
        &&
        Board[2][2] == player
        )
        { return true; }
    if (Board[2][0] == player
        &&
        Board[1][1] == player
        &&
        Board[0][2] == player
        )
        { return true; }
    
    //No wins found
    else { return false; }

    
}
