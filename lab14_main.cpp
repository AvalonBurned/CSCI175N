//Name: Christine Deidrich
//Lab 14 - Password Generator and Checker


#include <iostream>
#include<string>


//Function Prototypes
int getRandomValue(int max_array_length);

std::string getPassword();

bool check_password(std::string password);

std::string create_password();

//Constants
const int PASSWORD_MIN_LENGTH = 8;
const int PASSWORD_MAX_LENGTH = 24;
const std::string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string DIGITS = "0123456789";
const std::string SYMBOLS = "!#$%&'()*+,-./:;<=>?@[\]^_`{|}~"; //from ispunct definition

const int LETTERS_LOWER_MIN = 2;
const int LETTERS_UPPER_MIN = 2;
const int DIGITS_MIN = 2;
const int OTHER_MIN = 2;

const char NEW = 'n';
const char CHECK = 'c';


int main(int argc, const char* argv[]) {
    //example on how to iterate over argv[]
    /*
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    */

    srand(time(NULL));
    std::string password = "";

	//parse the command line argument 

    //note this has to be passed like this because arv is a pointer to a char
    if (*argv[1] == 'n') {
        password = create_password();
        std::cout << " Your password is: " << password;
    }


    else if (*argv[1] == 'c') {
        password = getPassword();
        std::cout << "You entered: " << password << std::endl;
        bool pwd_compliance = check_password(password);

        if (pwd_compliance == true) {
            std::cout << "Your password has been accepted!" << std::endl;
            std::exit(EXIT_SUCCESS);
        }

        else {
            std::cout << "Your provided password does not meet the minimum requirements. Generating compliant password." << std::endl;
            password = create_password();
            std::cout << "Your password is: " << password << std::endl;
        }
    }
    else {
        std::cout << "Invalid argument passed. Exiting..." << std::endl;
    }


}


int getRandomValue(int max_array_length){

    int randVal = rand() % ((max_array_length-1) + 1 - 0) + 0;
    return randVal;
}

std::string getPassword() {
    std::string password = "";
    std::cout << "Please enter your password. Your password must adhere to the following: " << std::endl;
    std::cout << "A minumum of " << LETTERS_UPPER_MIN << " upper case letters." << std::endl;
    std::cout << "A minimum of " << LETTERS_LOWER_MIN << " lower case letters." << std::endl;
    std::cout << "A minimum of " << DIGITS_MIN << " numbers." << std::endl;
    std::cout << "A minimum of " << OTHER_MIN << " special characters. Allowable special characters are: " << SYMBOLS << std::endl;
    std::cout << "Your password must be between " << PASSWORD_MIN_LENGTH << " and " << PASSWORD_MAX_LENGTH << " characters." << std::endl;
    std::cout << "Your password cannot include spaces." << std::endl;

    std::cin >> password;
    return password;
}


bool check_password(std::string password) {
    int pwd_length = password.length();
    bool pwd_compliance = false, min_upper_char = false, min_lower_char = false, min_digits = false, min_symbols = false, minmax_length = true;

    int count_letters_lower = 0, count_letters_upper = 0, count_digits = 0, count_symbols = 0;

    // min and max password length check
    if (pwd_length < PASSWORD_MIN_LENGTH || pwd_length > PASSWORD_MAX_LENGTH) {
        minmax_length = false;
    }
    // iterate over the string and check for character minimums
    for (auto it = password.cbegin(); it != password.cend(); ++it) {
        if (isupper(*it))
            count_letters_upper++;
        else if (isdigit(*it))
            count_digits++;
        else if (islower(*it))
            count_letters_lower++;
        else if (ispunct(*it))
            count_symbols++;
        else {
            std::cout << "Something has gone wrong. Exiting...." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    //check against minimums 
    //TODO (Improvement): provide use more granular feedback on what minimum wasn't met
    if (count_letters_upper > LETTERS_UPPER_MIN || count_letters_upper == LETTERS_UPPER_MIN)
        min_upper_char = true;
    if (count_letters_lower > LETTERS_LOWER_MIN || count_letters_lower == LETTERS_LOWER_MIN)
        min_lower_char = true;
    if (count_digits > DIGITS_MIN || count_digits == DIGITS_MIN)
        min_digits = true;
    if (count_symbols > OTHER_MIN || count_symbols == OTHER_MIN)
        min_symbols = true;

    if (min_upper_char == true && min_lower_char == true && min_digits == true && min_symbols == true && minmax_length == true)
        pwd_compliance = true;

    return pwd_compliance;

}

std::string create_password() {

    std::string password = "";
    int key, count_letters_lower = 0, count_letters_upper = 0, count_digits = 0, count_symbols = 0;
    int count = 0;
    int max_array_len = 0;
    char letter = ' ';

    while (count < PASSWORD_MAX_LENGTH) {

        // rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE
        int k = rand() % 5;

        switch (k) {
        case 1:
            // check if minimum reqs have been met for all values, if not - break and try again
            if ((count_letters_lower == LETTERS_LOWER_MIN) &&
                (count_digits < DIGITS_MIN || count_letters_upper < LETTERS_UPPER_MIN || count_symbols < OTHER_MIN))
                break;

            max_array_len = LETTERS.length(); 
            key = getRandomValue(max_array_len);
            letter = tolower(LETTERS[key]);
            password = password + letter;
            count_letters_lower++;
            count++;
            break;

        case 2:
            if ((count_letters_upper == LETTERS_UPPER_MIN) &&
                (count_digits < DIGITS_MIN || count_letters_lower < LETTERS_LOWER_MIN || count_symbols < OTHER_MIN))
                break;

            max_array_len = LETTERS.length();
            key = getRandomValue(max_array_len);
            letter = toupper(LETTERS[key]);
            password = password + letter;
            count_letters_upper++;
            count++;
            break;

        case 3:
            if ((count_digits == DIGITS_MIN) &&
                (count_letters_upper < LETTERS_UPPER_MIN || count_letters_lower < LETTERS_LOWER_MIN || count_symbols < OTHER_MIN))
                break;

            max_array_len = DIGITS.length();
            key = getRandomValue(max_array_len);
            password = password + DIGITS[key];
            count_digits++;
            count++;
            break;

        case 4:
            if ((count_symbols == OTHER_MIN) &&
                (count_letters_upper < LETTERS_UPPER_MIN || count_letters_lower < LETTERS_LOWER_MIN || count_digits < DIGITS_MIN))
                break;

            max_array_len = SYMBOLS.length();
            key = getRandomValue(max_array_len);
            password = password + SYMBOLS[key];
            count_symbols++;
            count++;
            break;

        }
    }
    return password;
}