#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *GetNewFileName(char *a,char *b){
    int len1 = strlen(a);
    int len2 = strlen(b);
    char *new = (char *)malloc(sizeof(char)*(len1+len2+1));
    strcpy(new, a);
    strcpy(new+len1, b);
    return new;
}

int main(int argc,char *argv[]){
    argc --;
    argv ++;

    int no_main = 0;
    char *filename = NULL;
    for(int i = 0;i < argc; ++i){
        if(strcmp(argv[i], "-no") == 0)
            no_main = 1;
        else if(strcmp(argv[i], "-nom") == 0)
            no_main = 1;
        else if(strcmp(argv[i], "-nomain") == 0)
            no_main = 1;
        else{
            /* filename = argv[i]; */
            filename = GetNewFileName(argv[i], ".c");
        }

    }
    /* printf("no_main:%d\n",no_main); */
    /* printf("filename:%s\n",filename); */

    FILE *file = fopen(filename, "r");
    if(file != NULL)
        printf("该文件已经存在\n");
    else{

        file = fopen(filename, "a+");

        time_t curtime = time(0);
        struct tm curtm = *localtime(&curtime);

        char time_buff[80];
        strftime(time_buff, sizeof(time_buff), "%D %T", &curtm);

        fprintf(file, 
                "/*\n"
                " *    Time: %s\n"
                " *    Create by yongheng\n"
                " */\n" 
                "\n"
                ,time_buff);
        if(no_main == 0){
            fprintf(file, 
                "#include <stdio.h>\n"
                "\n"
                "int main(int argc,char *argv[]){\n"
                "\n"
                "\n"
                "\n"
                "    return 0;\n"
                "}\n"
            );

        }
        else{
            fprintf(file, "\n");
        }
        
    }
    free(filename);
    fclose(file);
    



    return 0;
}
