
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

struct FILE_ {
    int fd;
    char buffer[1024];
    int end;
};
typedef struct FILE_ FILE_;

FILE_* fopen_(char *pathname, char *mode) {
    assert(pathname);
    assert(mode);

    FILE_ *fp = NULL;
    
    //
    if (strcmp(mode, "r") == 0) {
        int fd = open(pathname, O_RDONLY | O_CREAT | O_TRUNC, 0666);
        if (fd >= 0 ) {
            fp = (FILE_*)malloc(sizeof (FILE_));
            memset(fp, 0, sizeof (FILE_));
            fp->fd = fd;
        }

    }
    else if (strcmp(mode, "r+") == 0) {
        
    }


    else if (strcmp(mode, "w") == 0) {
        int fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd >= 0 ) {
            fp = (FILE_*)malloc(sizeof (FILE_));
            memset(fp, 0, sizeof (FILE_));
            fp->fd = fd;
        }
    }
    else if (strcmp(mode, "w+") == 0) {
        
    }
    else if (strcmp(mode, "a") == 0) {
        
    }
    else if (strcmp(mode, "a+") == 0) {
        
    }


    return fp;
}

void fputs_(char *s, FILE_* fp) {
    assert(s);
    assert(fp);

    strcpy(fp->buffer + fp->end, s);
    // printf("%s %d\n", fp->buffer, fp->end);
    fp->end += strlen(s);
    if (fp->fd == 0) {

    }
    else if (fp->fd == 1) {
        if (fp->buffer[fp->end - 1] == '\n') {
            write(fp->fd, fp->buffer, fp->end);
            fp->end = 0;
        }
    }
    else if (fp->fd == 2) {
        
    }

}


void fflush_(FILE_* fp) {
    assert(fp);

    if (fp->end > 0) {
        write(fp->fd, fp->buffer, fp->end);
        syncfs(fp->fd);
        fp->end = 0;
    }
}


void fclose_(FILE_* fp) {
    assert(fp);
    fflush_(fp);
    close(fp->fd);
    free(fp);
}

int main() {

    FILE_* fp = fopen_("text.txt", "w");

    fputs_("string1", fp);

    fputs_("string2\n", fp);   

    fputs_("string3", fp);    
    
    fputs_("string4\n", fp);
    

    printf("%d\n", fp->end);
    fclose_(fp);
    return 0;

}
