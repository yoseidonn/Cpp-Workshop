#ifndef CUSTOMLIB
#define CUSTOMLIB

#include "string"
#include "sstream"
#include "limits"

using namespace std;


namespace customlib {

bool is_numeric(string text);
bool is_numeric(char ch);

int to_int(string text) {
	if (!is_numeric(text)) {
		throw "No numeric input!";
	}
	
	int k = 1; // To hold base number to multiply
	int num = 0; // Our number to return
	
	// Reverse iteration
	for(size_t i = text.length()-1; i != (size_t) -1 ; --i) {
		num += (int) text[i]*k; // Base arithmetic k = 10^n
		k*=10; // k = 1, 10, 100 ...
	}		
	
	return num;
}

bool is_numeric(string text) {
	for(char ch : text) {
		if (!is_numeric(ch)) {
			return false;
		}
	} 
	return true;
}

bool is_numeric(char ch) {
	if (('0' <= ch) && (ch <= '9')) {	
		return true;
	} else {
		return false;
	}
}

int get_validated_int(string message) {
	int num;
    string input;

    while (true){
    	cout << message;
		cin >> input;
        
        // Use a stringstream to try converting the entire input to an integer
        stringstream ss(input);
        if ((ss >> num) && ss.eof()){  // ss.eof() checks if there's nothing left after parsing an integer
            return num;
        } else{
            cout << "Invalid input! Please enter an integer." << endl;
        }
       
        // Clear both the ss and the input buffer
        ss.clear(); // Reset stringstream state
        input.clear(); // Clear input string
        cin.clear(); // Clear cin error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }    
    
    return num;
}

char get_validated_char(string message) {
	string input;

    while (true) { // Loop until a valid char is passed
		cout << message;
        cin >> input;
        
        if (input.length())
			return input[0]; // Return the valid char
			
        cout << "Invalid choice! Please enter a valid operation (1-5 or q)." << endl;			
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input in cin's buffer;	
	}
}

template <typename T>
bool contains(vector<T>& arr, T& target) {
	for(T item : arr) {
		if (target == item)
			return 1;
	}
	return 0;
}
}

#endif