#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("Usage: touch <file>\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        int fd = open(argv[i], O_CREATE | O_WRONLY);
        if(fd < 0){
            printf("touch: cannot create %s\n", argv[i]);
            continue;
        }
        close(fd);
    }

    exit(0);
}
