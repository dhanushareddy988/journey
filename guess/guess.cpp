#include<cstdlib>
#include<iostream>
#include<emscripten.h>
void guessingGame(void* _guess){
    const auto guess = static_cast<unsigned int*>(_guess);
    unsigned int userGuess=0;
    std::cout<<"Please enter a guess (1-100): \n";
    std::cin>> userGuess;
    if(userGuess >100 || userGuess < 1){
        std::cerr<<"Invalid input\n";
        delete guess;
        emscripten_cancel_main_loop();
    }
    else if(userGuess>*guess){
        std::cout<<"Too High\n";
    }
    else if(userGuess<*guess){
        std::cout<<"Too low\n";
    }
    else{
        std::cout<<"Correct\n";
        emscripten_cancel_main_loop();
    }
}
int main(){
    srand(time(NULL));
    unsigned int *guess= new unsigned int(rand() %100 + 1 );
    emscripten_set_main_loop_arg(guessingGame, guess, 0 ,false);
}
