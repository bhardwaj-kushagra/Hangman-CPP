#include <iostream>
#include <vector>
#include <ctime>
#include <cctype>
#include <unordered_set>

using namespace std;

// Hangman ASCII Art
const string HANGMAN_STAGES[] = {
    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
};

// Function to get a hidden word with underscores
string getHiddenWord(const string& word, const unordered_set<char>& guessedLetters) {
    string hiddenWord = "";
    for (char c : word) {
        hiddenWord += (guessedLetters.count(c) ? c : '_');
        hiddenWord += ' ';
    }
    return hiddenWord;
}

int main() {
    vector<string> words = {"computer", "hangman", "programming", "science", "game", "keyboard", "engineer", "technology"};
    srand(time(0));
    string word = words[rand() % words.size()]; // Random word selection

    unordered_set<char> guessedLetters;
    int attempts = 6;
    char guess;

    cout << "🎉 Welcome to Hangman! Try to guess the word.\n";

    while (attempts >= 0) {
        cout << "\n" << HANGMAN_STAGES[6 - attempts] << endl;
        cout << "Word: " << getHiddenWord(word, guessedLetters) << endl;
        cout << "Attempts left: " << attempts << "\nGuessed letters: ";
        for (char c : guessedLetters) cout << c << ' ';
        cout << "\nEnter a letter: ";
        cin >> guess;
        guess = tolower(guess); // Convert to lowercase

        // Check if already guessed
        if (guessedLetters.count(guess)) {
            cout << "⚠️ You've already guessed that letter! Try again.\n";
            continue;
        }

        guessedLetters.insert(guess);

        // Check if the guessed letter is in the word
        if (word.find(guess) == string::npos) {
            cout << "❌ Incorrect guess!\n";
            attempts--;
        }

        // Check if the player has won
        bool allGuessed = true;
        for (char c : word) {
            if (!guessedLetters.count(c)) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\n🎉 Congratulations! You guessed the word: " << word << " 🎉\n";
            return 0;
        }

        if (attempts < 0) {
            cout << "\n☠️ Game over! The word was: " << word << " 😔\n";
            return 0;
        }
    }

    return 0;
}
