// Main Function 

#include <iostream>
#include <cstdlib>
#include <string>
#include "sshFunctions.h"
#include "cumulativeFunctions.h"
#include "userFunctions.h"

int main() {
    ssh_session my_ssh_session;
    std::string hostname = "";
    std::string username = "";
    std::string pwd = "";
    std::string custom_command_output = "";
    std::string custom_command = "";

    // Get hostname to connect to from user
    std::cout << "Please enter the hostname or IP of the device you want to connect to: " << std::endl;
    hostname = getInput();

    // Get username from user
    std::cout << "Please enter your username: " << std::endl;
    username = getInput();

    //Open Session and set options
    my_ssh_session = newSSHSession();
    setSSHOptions(my_ssh_session, hostname, username);

    //Connect to server
    sshConnect(my_ssh_session, hostname);

    // Authenticate
    // I recognize that this is insecure
    std::cout << "Please enter your password (WARNING: Will be displayed in plaintext): " << std::endl;
    pwd = getInput();
    sshAuthenticate(my_ssh_session, username, pwd);

    struct Hardware_Status HWStats;
    struct Software_Status SWStats;
    //One we've connected then the real fun begins
    char choice = 0;
    do {
        displayMenu();
        choice = getChoice();
        std::cin.ignore();
        switch (choice)
        {
        case '0':
            std::cout << "Exiting..." << std::endl;
            return 0;
             
        case '1':
            getHWStats(my_ssh_session, HWStats);
            break;
        
        case '2':
            getSWStats(my_ssh_session, SWStats);
            break;

        case '3':
            std::cout << "Blinking the LED..." << std::endl;
            makeBlinkyBlink(my_ssh_session);
            break;

        case '4':
            std::cout << "A brave soul I see...Please input the command you would like to run: " << std::endl;
            custom_command = getInput();
            std::cout << "You entered: " << custom_command << std::endl;
            // I don't understand enough about commands passed over ssh to be able to do error handling here
            // this is susciptable to a buffer overflow
            custom_command_output = runCustomCommand(my_ssh_session, custom_command);
            std::cout << "- - - - - COMMAND OUTPUT BELOW - - - - -" << std::endl;
            std::cout << custom_command_output << std::endl;
            break;

        case '5':
            // gotta have a little fun
            std::cout << "You've accessed the super secret area!" << std::endl;
            custom_command = "cowsay C++ is cool!";
            custom_command_output = runCustomCommand(my_ssh_session, custom_command);
            std::cout << custom_command_output << std::endl;
            break; 

        default:
            std::cout << "You did not select a valid option. Exiting...\n";
            return 1;
        }

    }
    while (choice != 0);
    
	return 0;
}


