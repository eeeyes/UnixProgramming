#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#define MAXLINE 100
int main(int argc,char* argv[])
{
	char buf[MAXLINE];
	pid_t pid;

	while ( fgets(buf,MAXLINE,stdin) != NULL )
	{
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]='\0';

		if( (pid=fork()) < 0 )
		{
			fprintf(stderr,"print error");
			exit(3);
		}

		else if ( pid == 0 )
		{
			execlp(buf,buf,(char*)0);
			exit(127);
		}
		
		waitpid(pid,NULL,0);
	}	
}
