// Main Function 
// Plan is to start with all the functionality here - then break out 

// Main sections: 
// GET System Status (combine multiple API Queries and synthesizes info)
// Temp
// Active Processes
// CPU Usage
// GET Host Info(Single API query)
	//Hostname
	//Kernel version
	// Etc…
//GET Active Processes
#include <iostream>
#include <cstdlib>
#include <string>
#include <errno.h>
#include <io.h>
#include "libssh/libssh.h" 
#include "sshFunctions.h"
#include "parsingFunctions.h"
#include "cumulativeFunctions.h"

//Function Prototypes 

// displays the menu
void displayMenu(); 

//gets the user's selection
char getChoice();

const char EXITING = '0';
const char HW_RETURN = '1';
const char SW_RETURN = '2';
const char CPU_TEMP_RETURN = '3';
const char BLINKY = '4';
const char VALID_CHOICES[] = { EXITING, HW_RETURN, SW_RETURN, CPU_TEMP_RETURN, BLINKY };


int main() {
    //connect to the remote host over SSH
    //TODO: move all variables up to the top
    //TODO: move consts out of main()
    ssh_session my_ssh_session;
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 22;
    //TODO: get the user to input this
    std::string hostname = "10.0.0.54";
    const char* username = "admin";
    //TODO: handle this not being hardcoded - use envvar or something
    const char* password = "admin";
    int rc;

 


    //Open Session and set options
    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
        exit(-1);
    
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "10.0.0.54");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, &username);

    //Connect to server
    rc = ssh_connect(my_ssh_session);
    if (rc != SSH_OK)
    {
        std::cout << "Error connecting to " << hostname << ": "
            << ssh_get_error(my_ssh_session) << std::endl;
            ssh_free(my_ssh_session);

        exit(-1);
    }

    // Verify the server's identity
    if (verify_knownhost(my_ssh_session) < 0)
    {
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }

    // Authenticate ourselves
    //char password[100];
    //strcpy_s(command, composite.c_str());
    //std::string pwd = "admin";
    //strcpy_s(password, pwd.c_str());
    //std::cout << password;

    
    rc = ssh_userauth_password(my_ssh_session, username, password);
    if (rc != SSH_AUTH_SUCCESS)
    {
        std::cout << "Error authenticating with password: "
            << ssh_get_error(my_ssh_session) << std::endl;
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }

    //One we've connected then the real fun begins
    char choice = 0;
    do {
        displayMenu();
        choice = getChoice();
        std::cout << "This is in Main: " << choice << std::endl;
        switch (choice)
        {
        case '0':
            std::cout << "Exiting..." << std::endl;
            return 0;
             
        case '1':
            std::cout << "HW Info" << std::endl;

            break;
        
        case '2':
            std::cout << "SW Info" << std::endl;
            break;
        
        case '3':
            std::cout << "CPU Temp" << std::endl;
            break;

        case '4':
            std::cout << "Blinky blink" << std::endl;
            std::cout << "Sorry, this is a firmware problem..." << std::endl;
            break;

        default:
            std::cout << "You did not select a valid option. Exiting...\n";
            return 1;
        }

    }
    while (choice != 0);

    Command command;

    std::string os_command_output = "", cpu_temp_command_output = "", 
        hostname_command_output = "", kernel_command_output = "",
        sn_command_output = "", opfreq_command_output = "", memory_command_input = "";

    // need to do some kind of error catching here since it returns an int, but not critical failure
    runCommand(my_ssh_session, command.os, os_command_output);
    runCommand(my_ssh_session, command.hostname, hostname_command_output);
    runCommand(my_ssh_session, command.kernel, kernel_command_output);
    //runCommand(my_ssh_session, command.sn, sn_command_output);


 
    std::cout << "This is in main: " << os_command_output << std::endl;
    std::string os = stringParse(os_command_output, ':');
    std::string kernel = stringParse(kernel_command_output, ':');


    //HW_Data raspi_hw_data;
    //SW_Data raspi_sw_data;
    
	return 0;
}


void displayMenu() {
    std::cout <<
        R"(
1. Get Hardware Information (SN)
2. Get Software Information (OS, Kernel)
3. Get CPU Temperature
4. Make the LED go blinky!
Please make your selection (0 to exit program):
)";
}

char getChoice() {
    char choice;
    while (true) {
        std::cin >> choice;
        std::cout << choice;

        if (std::strchr(VALID_CHOICES, choice) != NULL) {
            return choice;
        }
        std::cout << "Invalid Entry. Please enter another value." << std::endl;
        displayMenu();
    }
}