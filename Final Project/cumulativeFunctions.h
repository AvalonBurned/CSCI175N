#pragma once
#ifndef CUMULATIVE_H
#define CUMULATIVE_H

#include <iostream>
#include <string>
#include "libssh/libssh.h" 

struct Hardware_Status {
	std::string hostname;
	std::string serial_number;
	std::string total_memory;
	std::string cpu_temp_c;
	std::string total_storage;
	std::string avail_storage;
	std::string cpu_opfreq;
};

struct Software_Status {
	std::string hostname;
	std::string serial_number;
	std::string kernel_ver;
	std::string os_ver;
};

void hwDataDisplay(struct Hardware_Status);

void swDataDisplay(struct Software_Status);

void getHWStats(ssh_session my_ssh_session, Hardware_Status& HWStats);

void getSWStats(ssh_session my_ssh_session, Software_Status& SWStats);

void makeBlinkyBlink(ssh_session my_ssh_session);

std::string runCustomCommand(ssh_session my_ssh_session, std::string custom_command);

#endif CUMULATIVE_H