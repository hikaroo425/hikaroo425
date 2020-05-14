#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <getopt.h>
#include <dirent.h>

int main(int argc, char **argv){
       
	    DIR *dp;
        char *dir;
        struct dirent *d;
        struct stat st;
        char path[BUFSIZ+1];
        int opt_a;
        int c;

        while(1){//getopt_long 옵션지정
                static struct option long_options[] =
                {
                        {"all", no_argument, 0 , 'a'},
                        {0, 0, 0, 0}
                };

        dir = "."; //현재 디렉토리를 경로를 설정
        int option_index = 0;
        c = getopt_long(argc, argv, "a", long_options, &option_index);

        switch(c){
                
	case 'a': //a를 입력받을 시
	 opt_a = 1; //opt_a 1로 변환
	 break;
                
	default:                        
	 printf("option error");  //아닐시 에러 메세지 출력                      
	 return 0;
        	}

        if(opt_a == 1){
                if ((dp = opendir(dir)) == NULL) {  // 디렉터리 열기
                        perror(dir);
                        exit(1);
                	}
                
	while ((d = readdir(dp)) != NULL)  /*디렉터리 내의 각 엔트리에 대해*/                   		    printf("%s ", d->d_name);
                	closedir(dp); 

			printf("\n");
               
		exit(0);
        		}
        	 }	
    }
