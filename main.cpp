/*

    I will make a complete guess the number game in C++.
    It's my first complete C++ project that will be created with
    Visual Studio Code, and Repl.it to execute the program.
    I wish some return about the program and also the solution to have a better code.

*/

#include <iostream> // include the internal library called iostream / std

class ResultForGame { // Creation of the function called ResultForGame, she create for just have a result object for the game.
    public:
        int number_of_try;
        bool success;

        // Function init
        void init (int number_of_try_, bool success_) {
            number_of_try = number_of_try_;
            success = success_;
        }
};

ResultForGame game_loop(int guess, int min, int max) // Game loop function will return a ResultForGame Instance.
{
    ResultForGame Result; // declare a new ResultForGame instance


    int number_of_try = 0; // declare a number of attempts 
    bool SuccessfullyWinTheGame = false;
    Result.init(number_of_try, SuccessfullyWinTheGame);
    while(SuccessfullyWinTheGame == false)
    {
        int input_number;
        std::cout << "Enter a number between " << min << " and " << max << " > ";
        std::cin >> input_number;

        if (input_number < guess) {
            std::cout << "Greater than " << input_number << std::endl;
            number_of_try++;
            SuccessfullyWinTheGame = false;
            Result.init(number_of_try, SuccessfullyWinTheGame);
        } else if (input_number > guess) {
            std::cout << "Less than " << input_number << std::endl;
            number_of_try++;
            SuccessfullyWinTheGame = false;
            Result.init(number_of_try, SuccessfullyWinTheGame);
        } else {
            std::cout << "You are successfully guessed the number, the number to find is : " << guess << std::endl;
            number_of_try++;
            SuccessfullyWinTheGame = true;
            Result.init(number_of_try, SuccessfullyWinTheGame);
        }    
    }
    return Result;
}

// using namespace std; for don't having any error about this line I will comment this line and don't using.

int main()
{
    std::cout << "Welcome to " << "\033[36m" << "Volary" << "\033[0m" << std::endl;
    std::cout << "Made by" << " \033[34m" << "@Mids" << "\033[0m" << std::endl;

    std::cout << "Enter the minimum integer : ";
    int min;
    std::cin >> min;
    std::cout << "Enter the maximum integer : ";
    int max;
    std::cin >> max;

    ResultForGame Result = game_loop((rand()%max)+min,min,max);

    return 0; // return 0 to execute the program without any error.
}
