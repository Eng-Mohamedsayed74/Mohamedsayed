#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void morseCodeConverter(char choice) {
    string alpha[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." }; // Array storing Morse code representations for each character
    string number[10] = { "-----",".----","..---","...--","....-",".....","-....","--...","---..","----." }; // Array storing Morse code representations for numbers
    string symbols[15] = { "-.-.--" , ".-..-." ," ", "...-..-" , " " , ".-..." , ".----." , "-.--." , "-.--.-" , " ", ".-.-." , "--..--" " -....- " , ".-.-.- " , " -..-." }; // Array storing Morse code representations for symbols

    string result;
    if (choice == 'A') {
        string TheWord;  // Variable to store user input
        string TheNewstring = "";  // Variable to store converted Morse code
        cout << "Enter your sentence for encryption: ";
        cin.ignore();
        getline(cin, TheWord);  // Get input from the user
        for (int i = 0; i < TheWord.size(); i++) { // Loop through each character in the input
            if (isalpha(TheWord[i])) { // If the character is a letter
                TheWord[i] = toupper(TheWord[i]); // Convert the letter to uppercase
                int asciiValue = int(TheWord[i]); // Get ASCII value of the letter
                asciiValue -= 65;  // Adjust ASCII value to match array index
                TheNewstring += alpha[asciiValue] + " "; // Add Morse code for the letter to output string
            }
            else if (isdigit(TheWord[i])) { // If the character is a digit
                int value = int(TheWord[i]) - 48; // Get numerical value of the digit
                TheNewstring += number[value] + " "; // Add Morse code for the digit to output string
            }
            else if (TheWord[i] == ' ') { // If the character is a space 
                TheNewstring += " "; // Add space to output string
            }
            else { // If the character is a symbol
                int value_sym = int(TheWord[i]) - 33;
                TheNewstring += symbols[value_sym] + " ";
            }
        }
        cout << "The Encryption: " << TheNewstring << endl; // Print the encrypted message
    }
    else if (choice == 'B') {
        string morse[48] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." , "-----",".----","..---","...--","....-",".....","-....","--...","---..","----." , "-.-.--" , ".-..-." ,"...-..-" , ".-..." , ".----." , "-.--.-" , "-.--." ,".-.-." , "--..--" " -....- " , ".-.-.- " , " -..-." }; // Array storing Morse code representations
        string real[48] = {
                "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P",
                "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5",
                "6", "7", "8", "9", "!", "\"", "$", "&", "'", ")", "(", "+", ",", "-", ".", " "   // Array storing real characters
        };

        string Theword2; // Variable to store user input in Morse code
        string Thenewchar = ""; // Variable to store converted message
        string check = ""; // Variable used for verification

        cout << "Enter your morse Encryption: ";
        cin.ignore();
        getline(cin, Theword2); // Get input from user
        if (string(1, Theword2[Theword2.size() - 1]) != " ") {
            Theword2 += " "; // Add space to input if it doesn't end with a space
        }
        for (int i = 0; i < Theword2.size(); i++) { // Loop through each character in the input
            if (string(1, Theword2[i]) != " ") { // If the character is not a space
                toupper(Theword2[i]); // Convert character to uppercase
                check += Theword2[i]; // Add character to check variable
            }
            if (string(1, Theword2[i]) == " ") { // If the character is a space
                for (int k = 0; k < 48; k++) { // Loop through Morse code array
                    if (check == morse[k]) { // If Morse code matches
                        Thenewchar += real[k]; // Add corresponding character to output
                        check = ""; // Clear check variable for next character
                        break;
                    }
                }
            }
        }
        cout << "The Decryption: " << Thenewchar << endl; // Print the decrypted message
    }
    else {
        cout << "Invalid choice. Exiting..." << endl; // Display error message for invalid choice
    }
}

int main() {
    char choice;
    cout << "Welcome to the Morse Code Encryption and Decryption Program" << endl;
    cout << "Enter your choice (a for encryption, b for decryption): ";
    cin >> choice; // Prompt user to enter choice
    choice = toupper(choice); // Convert choice to uppercase
    morseCodeConverter(choice);
    return 0;
}