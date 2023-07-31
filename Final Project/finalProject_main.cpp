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

//Function Prototypes 

// displays the menu
void displayMenu(); 


int main() {
    //connect to the remote host over SSH
    //TODO: move all variables up to the top
    //TODO: move consts out of main()
    ssh_session my_ssh_session;
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 22;
    std::string hostname = "raspberrypi";
    const char* username = "admin";
    //TODO: handle this not being hardcoded - use envvar or something
    const char* password = "admin";
    int rc;

    //Open Session and set options
    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
        exit(-1);

    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "raspberrypi");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, &username);

    //Connect to server
    rc = ssh_connect(my_ssh_session);
    if (rc != SSH_OK)
    {
        //TODO: stop using fprint
        fprintf(stderr, "Error connecting to localhost: %s\n",
            ssh_get_error(my_ssh_session));
        // do not remove above until std::cout method is validated
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
        //TODO: fix to not use printf
        fprintf(stderr, "Error authenticating with password: %s\n",
            ssh_get_error(my_ssh_session));
        // do not remove above until std::cout method is validated
        std::cout << "Error authenticating with password: "
            << ssh_get_error(my_ssh_session) << std::endl;
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);
    }
    const char* os_command = "hostnamectl | grep -i operating";
    const char* cpu_temp_command = "/usr/bin/vcgencmd measure_temp";
    const char* hostname_command = "hostname";
    const char* kernel_command = "hostnamectl | grep -i kernel";
    std::string os_command_output = "", cpu_temp_command_output = "", 
        hostname_command_output = "", kernel_command_output = "";

    runCommand(my_ssh_session, os_command, os_command_output);
    runCommand(my_ssh_session, cpu_temp_command, cpu_temp_command_output);
    runCommand(my_ssh_session, hostname_command, hostname_command_output);
    runCommand(my_ssh_session, kernel_command, kernel_command_output);

    std::cout << "This is in main: " << os_command_output << std::endl;

    
	return 0;
}


void displayMenu() {

}