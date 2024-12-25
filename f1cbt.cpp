#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

bool verify(string &username);
void test();
void result(int score, const vector<char> &user_answers);
void testscript(const vector<char> &user_answers);

//Welcome message
int main() {
    cout << "WELCOME TO THE FORMULA 1 COMPUTER BASED TEST!\n";
    cout << "Press 'A' to Attempt or 'Q' to Quit: ";
    char start_choice;
    cin >> start_choice;
    start_choice = toupper(start_choice);

    while (start_choice != 'A' && start_choice != 'Q') {
        cout << "Incorrect Input. Enter 'A' to Attempt or 'Q' to Quit: ";
        cin >> start_choice;
        start_choice = toupper(start_choice);
    }

    if (start_choice == 'Q') {
        cout << "QUITTING!\n";
        return 0;
    }

    string username;
    if (!verify(username)) {
        return 0;
    }

    cout << "Welcome " << username << " TEST YOUR F1 KNOWLEDGE!";
    test();
    return 0;
}

//Username and password
bool verify(string &username) {
    vector<pair<string, string>> students = {{"MUNACHISO", "password"}, {"CHIKA", "ICONIC"}, {"HENRY", "SIUU101."}};
    string input_username, input_password;
    while (true) {
        cout << "\nEnter username: ";
        cin >> input_username;
        cout << "Enter password: ";
        cin >> input_password;

        for (const auto &student : students) {
            if (input_username == student.first && input_password == student.second) {
                username = input_username;
                return true;
            }
        }
        cout << "Wrong login details! Try again.\n";
    }
}

//Questions and options
const vector<string> questions = {
    "WHO IS THE CURRENT CHAMPION OF F1?",
    "HOW MANY CARS ARE IN A F1 GRID?",
    "WHO IS THE FASTEST DRIVER IN F1 HISTORY?",
    "HOW MANY GRAND PRIX ARE IN A F1 SEASON?",
    "WHO IS THE YOUNGEST DRIVER TO WIN A F1 GRAND PRIX?",
    "HOW MANY WORLD CHAMPIONSHIPS HAS LEWIS HAMILTON WON?",
    "WHO IS THE DRIVER WITH MOST WINS AT SILVERSTONE?"
};

const vector<vector<string>> options = {
    {"A. NIKI LAUDA", "B. CARLOS SAINZ", "C. MAX VERSTAPPEN", "D. LEWIS HAMILTON"},
    {"A. 20", "B. 22", "C. 24", "D. 26"},
    {"A. MAX VERSTAPPEN", "B. LEWIS HAMILTON", "C. FERNANDO ALONSO", "D. AYRTON SENNA"},
    {"A. 22", "B. 23", "C. 24", "D. 25"},
    {"A. MAX VERSTAPPEN", "B. MICHAEL SCHUMACHER", "C. OSCAR PIASTRI", "D. SEBASTIAN VETTEL"},
    {"A. 7", "B. 8", "C. 9", "D. 10"},
    {"A. MAX VERSTAPPEN", "B. MICHAEL SCHUMACHER", "C. LANDO NORRIS", "D. LEWIS HAMILTON"}
};

const vector<char> correct_answers = {'C', 'B', 'B', 'A', 'A', 'A', 'D'};

//main loop
void test() {
    const int num_questions = questions.size();
    vector<char> user_answers(num_questions, ' ');
    vector<bool> skipped(num_questions, false);
    int current_question = 0;

    while (true) {
        cout << "\nQuestion " << current_question + 1 << " of " << num_questions << ":\n";
        cout << questions[current_question] << "\n";
        
        for (const string &option : options[current_question]) {
            cout << option << "\n";
        }
            if (user_answers[current_question] != ' ') {
            cout << "\nYour current answer: " << user_answers[current_question] << "\n";
        }
        cout << "\nYour answer (A, B, C, D, S to skip, N for next, P for previous, W to submit): ";
        char choice;
        cin >> choice;
        choice = toupper(choice);
            if (choice == 'W') {
            cout << "\nYou have submitted the test.\n";
            break;
        } 
        else if (choice == 'S') {
            cout << "Question skipped.\n";
            skipped[current_question] = true;
            user_answers[current_question] = 'S';
        }
        else if (choice == 'N') {
            if (current_question == num_questions - 1) {
                cout << "This is the last question you cannot go forward.\n";
                continue;
            }
            current_question++;
            continue;
        }
        else if (choice == 'P') {
            if (current_question == 0) {
                cout << "This is the first question you cannot go backward.\n";
                continue;
            }
            current_question--;
            continue;
        }
        else if (choice >= 'A' && choice <= 'D') {
            user_answers[current_question] = choice;
            skipped[current_question] = false;
        }
        else {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (current_question < num_questions - 1) {
            current_question++;
        }
    }

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (user_answers[i] == correct_answers[i]) {
            score++;
        }
    }
    result(score, user_answers);
}
//testscript and result
void result(int score, const vector<char> &user_answers) {
    cout << "\nYOUR FINAL SCORE IS: " << score << "/" << questions.size() << "\n";
    char view_script;
    cout << "\nDo you want to view the TEST SCRIPT? (Y or N): ";
    cin >> view_script;
    
    if (toupper(view_script) == 'Y') {
        testscript(user_answers);
    }
    cout << "CBT COMPLETE!\n";
}

void testscript(const vector<char> &user_answers) {
    cout << "\nTEST SCRIPT\n";
    for (int i = 0; i < questions.size(); i++) {
        cout << "\nQ" << i + 1 << ": " << questions[i] << "\n";
        for (const string &option : options[i]) {
            cout << option << "\n";
        }
        string answer_display = (user_answers[i] == ' ') ? "NIL" : 
                              (user_answers[i] == 'S') ? "Skipped" : 
                              string(1, user_answers[i]);
        
        cout << "Your Answer: " << answer_display << " | Correct Answer: " << correct_answers[i];
        if (user_answers[i] == correct_answers[i]) {
            cout << " [Correct]\n";
        } else {
            cout << " [Wrong]\n";
        }
    }
}