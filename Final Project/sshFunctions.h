// functions needed for ssh functionality 

#pragma once
#ifndef SSHFUNCTIONS_H
#define SSHFUNCTIONS_H
#include <iostream>
#include <string>
#include "libssh/libssh.h"

ssh_session newSSHSession();

void setSSHOptions(ssh_session my_ssh_session, std::string hostname, std::string username);

void sshConnect(ssh_session session, std::string hostname);

void sshAuthenticate(ssh_session session, std::string username, std::string password);

int runCommand(ssh_session session, const char* command, std::string &command_output);

int runNoOutputCommand(ssh_session session, const char* command);


#endif