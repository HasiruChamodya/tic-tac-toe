#include <iostream> // For basic input/output operations.
#include <string>   // For handling player names.
#include <windows.h>  // For console manipulation, such as clearing the screen and changing text color.

using namespace std;

// Define constants for console text colors.
const int WHITE = 15;
const int LIGHT_BLUE = 9;
const int LIGHT_GREEN = 10;
const int LIGHT_RED = 12;

// Declare the game board as a 2D array, representing the 3x3 grid.
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; 
int row;    // Variable to track the row of the selected grid position.
int column; // Variable to track the column of the selected grid position.
char token = 'X'; // Variable to track the current player's symbol ('X' or 'O').
bool istie = false; // Flag to check for a tie game.
string n1;  // Player 1's name.
string n2;  // Player 2's name.

// Function prototypes.
void Grid();  // Function to display the game 3x3 grid.
void Turn();  // Function to get player inputs and update the grid.
bool Win();   // Function to determine the winner and check winning conditions.
void SetConsoleColor(int color);  // Function to set the console text color.
void DisplayRules();  // Function to display the game rules.
void ClearScreen();   // Function to clear the console screen.
void ResetGame();     // Function to reset the game to its initial state.

int main() {
    int choice;

    // Main game loop to display the menu and handle user input.
    while (true) {
        // Set console color to light green and display the main menu.
        SetConsoleColor(LIGHT_GREEN);
        cout << "====================================================================================================================\n";
        cout << "   ############  ###  #######       ############     ####    #######     ############    ###########  ##########    \n";
        cout << "   ##### ######  # #  # ###         ##### ######   #  #  #   # ####      ##### ######    # #     # #  #  #######    \n";
        cout << "       # #       # #  # #               # #       #  ###  #  # #             # #         # #     # #  #  #          \n";
        cout << "       # #       # #  # #               # #       # ##### #  # #             # #         # #     # #  #  ####       \n";
        cout << "       # #       # #  # #               # #       # #   # #  # #             # #         # #     # #  #  #          \n";
        cout << "       # #       # #  # ###             # #       # #   # #  # ####          # #         # #     # #  #  #######    \n";
        cout << "       ###       ###  #######           ###       ###   ###  #######         ###         ###########  ##########    \n";
        cout << "====================================================================================================================\n";

        // Set console color to light red and display the menu options.
        SetConsoleColor(LIGHT_RED);
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                                                       1. Start Game\n";
        cout << "                                                       2. View Rules\n";
        cout << "                                                       3. Exit\n";

        // Reset console color to white for user input.
        SetConsoleColor(WHITE);
        cin >> choice;
        
        // Handle the user's menu choice.
        switch (choice) {
            case 1:
                // Clear the console screen before starting the game.
                ClearScreen();

                // Prompt players to enter their names.
                cout << "Enter 1st player name: ";
                cin >> n1;
                cout << "Enter 2nd player name: ";
                cin >> n2;
                cout << "                        \n";
                cout << n1 << " will play first\n";
                cout << n2 << " will play second\n\n\n";

                // Play the game until a win or tie is detected.
                while (!Win()) {
                    Grid(); // Display the grid.
                    Turn(); // Process the player's turn.
                }
                Grid(); // Display the final grid.
                
                // Display the result of the game.
                if (!istie) {
                    if (token == 'O') {
                        SetConsoleColor(LIGHT_RED);
                        cout << n1 << " Wins the game\n";
                        cout << "Congratulations!!!\n\n\n";
                    } else if (token == 'X') {
                        SetConsoleColor(LIGHT_RED);
                        cout << n2 << " Wins the game\n";
                        cout << "Congratulations!!!\n\n\n";
                    }
                } else {
                    SetConsoleColor(LIGHT_RED);
                    cout << "Game is a draw\n\n\n";
                }

                // Reset the game to play another round.
                ResetGame();
                break;

            case 2:
                // Clear the screen and display the rules.
                ClearScreen();
                DisplayRules();
                break;

            case 3:
                // Exit the game.
                SetConsoleColor(LIGHT_RED);
                cout << "Exiting the game. Goodbye!\n";
                SetConsoleColor(WHITE);
                return 0;

            default:
                // Handle invalid menu choice.
                SetConsoleColor(LIGHT_RED);
                cout << "Invalid choice! Please select 1, 2, or 3.\n";
                SetConsoleColor(WHITE);
                break;
        }
    }

    return 0;
}

// Function to display the game grid.
void Grid() {
    SetConsoleColor(LIGHT_BLUE);
    cout << "       |       |       " << endl;
    cout << "   " << space[0][0] << "   |   " << space[0][1] << "   |   " << space[0][2] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "                       " << endl;
    SetConsoleColor(WHITE);
}

// Function to handle the player's turn and update the grid.
void Turn() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number (1-9): ";
    }
    else if (token == 'O') {
        cout << n2 << ", please enter a number (1-9): ";
    }
    cin >> digit;
    cout << "" << endl;

    // Determine the row and column based on the player's input.
    if (digit >= 1 && digit <= 9) {
        if (digit == 1) {
            row = 0;
            column = 0;
        } else if (digit == 2) {
            row = 0;
            column = 1;
        } else if (digit == 3) {
            row = 0;
            column = 2;
        } else if (digit == 4) {
            row = 1;
            column = 0;
        } else if (digit == 5) {
            row = 1;
            column = 1;
        } else if (digit == 6) {
            row = 1;
            column = 2;
        } else if (digit == 7) {
            row = 2;
            column = 0;
        } else if (digit == 8) {
            row = 2;
            column = 1;
        } else if (digit == 9) {
            row = 2;
            column = 2;
        }

        // Check if the selected cell is empty; if so, place the token.
        if (space[row][column] != 'X' && space[row][column] != 'O') {
            if (token == 'X') {
                space[row][column] = 'X';
                token = 'O'; // Switch to the next player's turn.
            } else {
                space[row][column] = 'O';
                token = 'X'; // Switch to the next player's turn.
            }
        } else {
            cout << "There is no empty space, try again\n";
            Win(); // Prompt to win check to proceed if the position is occupied.
        }
    } else {
        cout << "Invalid input, please enter again.\n";
        Turn(); // Prompt the user to enter a valid number again.
    }
}

// Function to check if there is a winner or if the game is a tie.
bool Win() {
    // Check rows and columns for a win condition.
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
    // Check diagonals for a win condition.
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    // Check if there are any empty spaces left; if not, it's a tie.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }
    istie = true; // If all spaces are filled and no winner, it's a tie.
    return true;
}

// Function to set the console text color.
void SetConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to clear the console screen.
void ClearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = { 0, 0 };  // Coordinates for the top-left corner of the console.
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    DWORD written;
    DWORD size;

    // Get the console screen buffer information.
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    size = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;

    // Fill the console with spaces to clear it.
    FillConsoleOutputCharacter(hConsole, ' ', size, topLeft, &written);
    FillConsoleOutputAttribute(hConsole, consoleInfo.wAttributes, size, topLeft, &written);

    // Set the cursor position back to the top-left corner.
    SetConsoleCursorPosition(hConsole, topLeft);
}

// Function to display the rules of the game.
void DisplayRules() {
    SetConsoleColor(LIGHT_BLUE);
    cout << "\n\n			=========== RULES ===========\n\n";
    cout << "1. The game is played on a 3x3 grid.\n";
    cout << "2. Players take turns to mark the grid with 'X' or 'O'.\n";
    cout << "3. The first player to align 3 marks in a row, column, or diagonal wins.\n";
    cout << "4. If all 9 squares are filled without a winner, the game ends in a draw.\n";
    cout << "\n		        =============================\n\n";
    SetConsoleColor(WHITE);

    // Prompt the user to press any key to return to the main menu.
    cout << "Press any key to return to the main menu...";
    cin.ignore();
    cin.get();  // Wait for the user to press a key.
}

// Function to reset the game board to its initial state.
void ResetGame() {
    // Reinitialize the game board with the initial values.
    char initialBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    memcpy(space, initialBoard, sizeof(space));

    // Reset the token and tie flag for a new game.
    token = 'X';
    istie = false;
}

