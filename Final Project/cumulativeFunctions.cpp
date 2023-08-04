// Functions that wrap the other functions to make main look clean

#include "cumulativeFunctions.h"
#include "libssh/libssh.h" 
#include "sshFunctions.h"

class Command {
public:
	const char* os = "hostnamectl | grep -i operating";
	const char* cpu_temp = "/usr/bin/vcgencmd measure_temp";
	const char* hostname = "hostname";
	const char* kernel = "hostnamectl | grep -i kernel";
	const char* sn = "cat /sys/firmware/devicetree/base/serial-number";
	const char* opfreq = "";
	const char* memory = "cat /proc/meminfo | grep -i MemTotal";
};

//TODO: how to pass a class to a function
void getHWStats(ssh_session my_ssh_session, const char* hostname_command, std::string hostname_command_output, Command commands) {
	//get hostname
	runCommand(my_ssh_session, command.hostname, hostname_command_output);
	//get memory
	//runCommand (my_ssh_session, memory_command, memory_command_output)
	//parse memory 
	//std::string memory = stringParse(memory_command_output, ":");
	//get storage 
	// runCommand(my_ssh_session, storage_command, storage_command_output)
	//parse storage
	//getCPUTemp
	//runCommand(my_ssh_session, command.cpu_temp, cpu_temp_command_output);
	//parse CPU temp
	//std::string cpu_temp = stringParse(cpu_temp_command_output, '=');
	//get freq
	//parse freq
	//display it all
}

void getSWStats() {
	//get hostname 

}