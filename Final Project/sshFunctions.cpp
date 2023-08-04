// functions needed for ssh functionality 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <errno.h>
#include "libssh/libssh.h"
#include <io.h>

// at some point I need to go through and actually understand this
// borrowed from libssh examples

int sshConnect() {
    return 0;
}

//TODO: fix name
int verify_knownhost(ssh_session session)
{
    enum ssh_known_hosts_e state;
    unsigned char* hash = NULL;
    ssh_key srv_pubkey = NULL;
    size_t hlen;
    char buf[10];
    char* hexa;
    char* p;
    int cmp;
    int rc;

    rc = ssh_get_server_publickey(session, &srv_pubkey);
    if (rc < 0) {
        return -1;
    }

    rc = ssh_get_publickey_hash(srv_pubkey,
        SSH_PUBLICKEY_HASH_SHA1,
        &hash,
        &hlen);
    ssh_key_free(srv_pubkey);
    if (rc < 0) {
        return -1;
    }

    state = ssh_session_is_known_server(session);
    switch (state) {
    case SSH_KNOWN_HOSTS_OK:
        /* OK */

        break;
    case SSH_KNOWN_HOSTS_CHANGED:
        fprintf(stderr, "Host key for server changed: it is now:\n");
        ssh_print_hexa("Public key hash", hash, hlen);
        fprintf(stderr, "For security reasons, connection will be stopped\n");
        ssh_clean_pubkey_hash(&hash);

        return -1;
    case SSH_KNOWN_HOSTS_OTHER:
        fprintf(stderr, "The host key for this server was not found but an other"
            "type of key exists.\n");
        fprintf(stderr, "An attacker might change the default server key to"
            "confuse your client into thinking the key does not exist\n");
        ssh_clean_pubkey_hash(&hash);

        return -1;
    case SSH_KNOWN_HOSTS_NOT_FOUND:
        fprintf(stderr, "Could not find known host file.\n");
        fprintf(stderr, "If you accept the host key here, the file will be"
            "automatically created.\n");

        /* FALL THROUGH to SSH_SERVER_NOT_KNOWN behavior */

    case SSH_KNOWN_HOSTS_UNKNOWN:
        hexa = ssh_get_hexa(hash, hlen);
        fprintf(stderr, "The server is unknown. Do you trust the host key?\n");
        fprintf(stderr, "Public key hash: %s\n", hexa);
        ssh_string_free_char(hexa);
        ssh_clean_pubkey_hash(&hash);
        p = fgets(buf, sizeof(buf), stdin);
        if (p == NULL) {
            return -1;
        }

        cmp = strncmp(buf, "yes", 3);
        if (cmp != 0) {
            return -1;
        }

        rc = ssh_session_update_known_hosts(session);
        if (rc < 0) {
            fprintf(stderr, "Error %s\n", strerror(errno));
            return -1;
        }

        break;
    case SSH_KNOWN_HOSTS_ERROR:
        fprintf(stderr, "Error %s", ssh_get_error(session));
        ssh_clean_pubkey_hash(&hash);
        return -1;
    }

    ssh_clean_pubkey_hash(&hash);
    return 0;
}

int runCommand(ssh_session session, const char* command, std::string& command_output)
{
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
    nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
    // if nbytes is 0 there is no data, if it is -1 there is an error
    //TODO: clean up error catching
    if (nbytes < 0 || nbytes == 0) {
        std::cout << nbytes;
        std::cout << "potential invalid command" << std::endl;
        return SSH_ERROR;
    }

    //convert the buffer to a string and update the variable
    buffer[nbytes] = '\0';
    command_output = std::string(buffer);
    std::cout << command_output << std::endl;

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);

    return SSH_OK;
}