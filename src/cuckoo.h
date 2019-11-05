
#ifndef __CUCKOO_H__
#define __CUCKOO_H__

#ifdef __cplusplus
extern "C" {
#endif 

    // 1. select a process, PTRACE_ATTACH PTRACE_GETREGS
    // 2. select a elf file
    // 3. parse elf file 
    // 4. modify the file content
    // 5. fina a target location to save the injected content 
    //      PTRACE_PEEKTEXT
    // 6. using ptrace write content into process memory 
    //      PTRACE_POKETEXT
    // 7. using ptrace execute content
    //      PTRACE_CONT
    // 8. execute finished, revocery
    //      PTRACE_SETREGS
    //
    //  others:
    //      1. using process_vm_readv()/process_vm_writev() replace PTRACE_PEEKTEXT/PTRACE_POKETEXT
    //      2. using mmap() to implement VirtualAllocEx() in linux
    //
    //
    //   TODO: Death under ptrace  link: http://man7.org/linux/man-pages/man2/ptrace.2.html

    #include <stdlib.h>
    #include "maps.h"
    typedef struct cuckoo_context_s {
        pid_t target_pid;
        maps_item *mem_maps;
        int inject_type;
        char *injected_filename;
    }cuckoo_context;
    
    int init_context(cuckoo_context *context, pid_t pid);
    void clean_context(cuckoo_context *context);

#ifdef __cplusplus
}
#endif

#endif /* __CUCKOO_H__ */
