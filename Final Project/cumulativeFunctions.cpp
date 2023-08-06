// Functions that wrap the other functions to make main look clean
#include <iostream>
#include <iomanip>
#include <string>
#include "cumulativeFunctions.h"
#include "parsingFunctions.h" 
#include "sshFunctions.h"

//Raspberry Pi Commands 
// need to pass to ssh functions with c_str()
const std::string OS_COMMAND = "hostnamectl | grep -i operating";
const std::string CPUTEMP_COMMAND = "/usr/bin/vcgencmd measure_temp";
const std::string HOSTNAME_COMMAND = "hostname";
const std::string KERNEL_COMMAND = "hostnamectl | grep -i kernel";
const std::string SN_COMMAND = "cat /sys/firmware/devicetree/base/serial-number";
const std::string OPFREQ_COMMAND = "cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq";
const std::string TOTALMEM_COMMAND = "cat /proc/meminfo | grep -i MemTotal";
const std::string BLINKY_BLINK_COMMAND = "i=0; while [ $i -le 5 ]; do gpioset --mode=time --sec=1 0 21=1; gpioset --mode=time --sec=1 0 21=0; echo $((i++)); done";
//const std::string BASIC_LED_ON = "gpioset 0 21=1";
//const std::string BASIC_LED_OFF = "gpioset 0 21=0";


void hwDataDisplay(Hardware_Status HWStats) {
	std::cout << "\nHardware Data\n";
	std::cout << "- - - - - - - - - - - - - - - -\n";
	std::cout << std::right << std::setw(25) << "Hostname: " << std::left << HWStats.hostname << std::endl;
	std::cout << std::right << std::setw(25) << "Serial Number: " << std::left << HWStats.serial_number << std::endl;
	std::cout << std::right << std::setw(25) << "Total Memory: " << std::left << HWStats.total_memory << std::endl;
	std::cout << std::right << std::setw(25) << "CPU Temperature: " << std::left << HWStats.cpu_temp_c << std::endl;
	std::cout << std::right << std::setw(25) << "CPU Operating Frequency: " << std::left << HWStats.cpu_opfreq << std::left << " kHz" << std::endl;

}

void getHWStats(ssh_session my_ssh_session, Hardware_Status& HWStats) {
	std::string command_output = "";

	//get hostname and update struct
	runCommand(my_ssh_session, HOSTNAME_COMMAND.c_str(), command_output);
	HWStats.hostname = removeSpace(command_output);

	//get serial number, parse, and update struct
	runCommand(my_ssh_session, SN_COMMAND.c_str(), command_output);
	HWStats.serial_number = removeSpace(command_output);

	//get memory, parse, and update struct
	runCommand(my_ssh_session, TOTALMEM_COMMAND.c_str(), command_output);
	command_output = stringParse(command_output, ':');
	HWStats.total_memory = removeSpace(command_output);

	//get CPUTemp, parse, and update struct
	runCommand(my_ssh_session, CPUTEMP_COMMAND.c_str(), command_output);
	command_output = stringParse(command_output, '=');
	HWStats.cpu_temp_c = removeSpace(command_output);

	//get freq, parse, and update struct
	runCommand(my_ssh_session, OPFREQ_COMMAND.c_str(), command_output);
	command_output = stringParse(command_output, '=');
	HWStats.cpu_opfreq = removeSpace(command_output);

	hwDataDisplay(HWStats);
}

void swDataDisplay(Software_Status SWStats) {
	std::cout << "\nSoftware Data\n";
	std::cout << "- - - - - - - - - - - - - - - -\n";
	std::cout << std::right << std::setw(18) << "Hostname: " << std::right << SWStats.hostname << std::endl;
	std::cout << std::right << std::setw(18) << "Operating System: " << std::right << SWStats.os_ver << std::endl;
	std::cout << std::right << std::setw(18) << "Kernel: " << std::right << SWStats.kernel_ver << std::endl;
}

void getSWStats(ssh_session my_ssh_session, Software_Status& SWStats) {
	//get hostname, parse, and update struct
	std::string command_output;
	runCommand(my_ssh_session, HOSTNAME_COMMAND.c_str(), command_output);
	SWStats.hostname = removeSpace(command_output);

	//get serialnumber, parse, and update struct
	runCommand(my_ssh_session, SN_COMMAND.c_str(), command_output);
	SWStats.serial_number = command_output;

	// get kernel version, parse, and store in struct
	runCommand(my_ssh_session, KERNEL_COMMAND.c_str(), command_output);
	command_output = stringParse(command_output, ':');
	SWStats.kernel_ver = removeSpace(command_output);

	// get os version, parse, and store in struct 
	runCommand(my_ssh_session, OS_COMMAND.c_str(), command_output);
	command_output = stringParse(command_output, ':');
	SWStats.os_ver = removeSpace(command_output);

	swDataDisplay(SWStats);
}

void makeBlinkyBlink(ssh_session my_ssh_session) {
	runNoOutputCommand(my_ssh_session, BLINKY_BLINK_COMMAND.c_str());
	//std::cout << "Sorry, this is a firmware problem..." << std::endl;
}

std::string runCustomCommand(ssh_session my_ssh_session, std::string command) {
	std::string command_output = "";
	runCommand(my_ssh_session, command.c_str(), command_output);
	return command_output;
}

