// functions needed for ssh functionality 

#pragma once
#ifndef SSHFUNCTIONS_H
#define SSHFUNCTIONS_H
#include <iostream>
#include <string>
#include "libssh/libssh.h"

int sshConnect();

//TODO: fix name
int verify_knownhost(ssh_session session);


int runCommand(ssh_session session, const char* command, std::string &command_output);


#endif