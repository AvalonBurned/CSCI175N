// functions needed for ssh functionality 

#include <iostream>
#include <string>
#include "libssh/libssh.h"

/*
The verbosity of the messages. Every log smaller or equal to verbosity will be shown.
SSH_LOG_NOLOG: No logging (0)
SSH_LOG_RARE: Rare conditions or warnings (1)
SSH_LOG_PROTOCOL: API-accessible entrypoints (2)
SSH_LOG_PACKET: Packet id and size (3)
SSH_LOG_FUNCTIONS: Function entering and leaving (4)
*/
const int VERBOSITY = SSH_LOG_RARE;
const int PORT = 22;

 ssh_session newSSHSession() {
     ssh_session session;
     session = ssh_new();
     if (session == NULL)
         exit(-1);
     return session;
}

 void setSSHOptions(ssh_session my_ssh_session, std::string hostname, std::string username) {
     ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, hostname.c_str());
     ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &VERBOSITY);
     ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, &PORT);
     ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, username.c_str());
 }

 void sshConnect(ssh_session session, std::string hostname) {
     int rc = 0;
     rc = ssh_connect(session);
     if (rc != SSH_OK)
     {
         std::cout << "Error connecting to " << hostname << ": "
             << ssh_get_error(session) << std::endl;
         ssh_free(session);

         exit(-1);
     }
 }

 void sshAuthenticate(ssh_session session, std::string username, std::string password) {
     int rc = 0;
     rc = ssh_userauth_password(session, username.c_str(), password.c_str());
     if (rc != SSH_AUTH_SUCCESS)
     {
         std::cout << "Error authenticating with password: "
             << ssh_get_error(session) << std::endl;
         ssh_disconnect(session);
         ssh_free(session);
         exit(-1);
     }
 }

int runCommand(ssh_session session, const char* command, std::string& command_output)
{
    ssh_channel channel;
    int rc;
    char buffer[10000];
    int nbytes = 0;

    channel = ssh_channel_new(session);
    if (channel == NULL)
        return SSH_ERROR;

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK)
    {
        ssh_channel_free(channel);
        return rc;
    }

    rc = ssh_channel_request_exec(channel, command);
    if (rc != SSH_OK)
    {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        return rc;
    }
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    // if nbytes is 0 there is no data, if it is -1 there is an error
    if (nbytes == 0) {
        std::cout << "Potential Invalid Command - No Data Returned" << std::endl;
        return SSH_ERROR;
    }
    else if (nbytes < 0) {
        std::cout << "Error running command." << std::endl;
        return SSH_ERROR;
    }

    //convert the buffer to a string and update the variable
    buffer[nbytes] = '\0';
    command_output = std::string(buffer);

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);

    return SSH_OK;
}

int runNoOutputCommand(ssh_session session, const char* command) {
    ssh_channel channel;
    int rc;
    char buffer[256];
    int nbytes = 0;

    channel = ssh_channel_new(session);
    if (channel == NULL)
        return SSH_ERROR;

    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK)
    {
        ssh_channel_free(channel);
        return rc;
    }

    rc = ssh_channel_request_exec(channel, command);
    if (rc != SSH_OK)
    {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        return rc;
    }

    while (!ssh_channel_is_eof(channel)) {
        nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 1);
        if (nbytes == SSH_ERROR) {
            return -1;
        }
        else if (nbytes == 0) {
            return SSH_OK;
        }
    }
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);

    return SSH_OK;
}