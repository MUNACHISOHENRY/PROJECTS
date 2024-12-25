#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string scrambleword(string word) {
    string mixed = word;
    for(int i = 0; i < word.length(); i++) {
        int random = rand() % word.length();
        char temp = mixed[i];
        mixed[i] = mixed[random];
        mixed[random] = temp;
    }
    return mixed;
}
int main() {
    srand(time(0));
    string words[] = {"maximus", "philip", "roman", "verstappen", "hulkenberg"};
    string word_hints[] = {"Roman Name", "Name of a Saint", "The empire that Julius Caesar conquered", "Current F1 World Champion", "F1 driver also known as 'The Hulk'"};
    
    int score = 0;
    int correctletterattempt = 5;
    cout << "Welcome to the WORD SCRAMBLE GAME!\n";
    cout << "Enter 'S' to start or 'Q' to quit: ";
    
    char choice;
    cin >> choice;
    if (choice == 'Q' || choice == 'q') {
        cout << "ADIEUS!!\n";
        return 0;
    }
    for(int i = 0; i < 5; i++) {
        string current_word = words[i];
        string scrambled = scrambleword(current_word);
        string display = string(current_word.length(), '_'); // For showing revealed letters
        string guess;
        bool correctword = false;
        
        if(i == 4) {
            cout << "\nThis is the last word!\n";
        }
        while (!correctword) {
            cout << "\nScrambled word: " << scrambled << endl;
            cout << "Current word: " << display << endl;
            cout << "GET CORRECT LETTER attempts remaining: " << correctletterattempt << endl;
            cout << "Score: " << score << "/" << i << endl;
            cout << "SELECTIONS:\n";
            cout << "G - GET CORRECT LETTER\n";
            cout << "H - Take a Hint\n";
            cout << "N - Next Word\n";
            cout << "Or type your Guess: ";
            cin >> guess;
            if(guess == "G" || guess == "g") {
                if(correctletterattempt > 0) {
                    bool revealed = false;
                    for(int j = 0; j < current_word.length(); j++) {
                        if(display[j] == '_') {
                            display[j] = current_word[j];
                            revealed = true;
                            correctletterattempt--;
                            cout << "Letter revealed!" << endl;
                            break;
                        }
                    }
                    if(!revealed) {
                        cout << "All letters are revealed!" << endl;
                    }
                } else {
                    cout << "No GET CORRECT LETTER options left!" << endl;
                }
                continue;
            }
            if(guess == "H" || guess == "h") {
                cout << "HINT: " << word_hints[i] << endl;
                continue;
            }
            if(guess == "N" || guess == "n") {
                cout << "The word was: " << current_word << endl;
                cout << "No points given, going to the next word." << endl;
                correctword = true;
                continue;
            }
            if(guess == current_word) {
                cout << "Correct! You spelt the word correctly." << endl;
                score++;
                correctletterattempt++;
                cout << "You earned an extra GET CORRECT LETTER attempt!" << endl;
                cout << "Score: " << score << "/" << (i + 1) << endl;
                correctword = true;
            } else if (guess != "G" && guess != "g" && guess != "H" && guess != "h") {
                cout << "Wrong spelling." << endl;
            }
        }
    }
cout << "\nWell Done!\n" << "\nYour Final Score is: " << score << "/5\n";
    return 0;
}