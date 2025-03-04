# Hangman Game (C++)

## 🎮 Introduction
Hangman is a classic word-guessing game where players try to guess the hidden word letter by letter before running out of attempts. This C++ version of Hangman includes:

- **Random word selection** from a predefined list
- **Hangman ASCII visuals** for better gameplay experience
- **Input validation** (prevents duplicate guesses and handles case sensitivity)
- **Dynamic word display** with underscores for hidden letters

## 🛠️ How to Play
1. The program selects a random word from a list.
2. The player guesses letters one by one.
3. If the guessed letter is in the word, it is revealed.
4. If not, an attempt is deducted, and the hangman figure progresses.
5. The game ends when the word is fully guessed (win) or all attempts are used (loss).

## 🚀 Features
- ASCII-based **hangman visuals** for each incorrect guess
- **Set-based guessed letter tracking** (prevents duplicate entries)
- **More readable and structured code**
- **Lowercase conversion for consistent input handling**
- **Predefined dictionary with multiple words**

## 🖥️ Installation & Execution
1. **Clone or Download the Code**
```sh
https://github.com/yourusername/hangman-game.git
```
2. **Compile the Program** (Using g++)
```sh
g++ hangman.cpp -o hangman
```
3. **Run the Program**
```sh
./hangman
```

## 🔧 Example Gameplay
```
  +---+
  |   |
      |
      |
      |
      |
=========
Word: _ _ _ _ _ _
Attempts left: 6
Guessed letters:
Enter a letter: a
```

## 📜 License
This project is open-source and available under the MIT License.

## 📩 Contributing
Feel free to contribute by adding more words, improving the visuals, or optimizing the logic!

Enjoy playing Hangman! 🎉

