#include "../ft_pipex.h"

int main()
{
	int fds[2];
	int fd1= open("a", O_RDONLY);
	if (fd1 < 0)
		perror("FILE1 Open Error");
	int fd2= open("b", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd2 < 0)
		perror("FILE2 Open Error");
	dup2(fd2, STDOUT_FILENO);
	write(STDOUT_FILENO, "hi", 2);
	// if (pipe(fds) < 0)
	// 	perror("pipe");
	// int pid = fork();
	// if (pid < 0)
	// 	perror("fork");
	// printf("pid: %d\n", pid);
	// // 부모 프로세스 : cmd1 출력 결과를 fd[WRITE]
	// if (pid != 0)
	// {
	// 	close(fds[READ]);
	// 	printf("parent pid: %d\n", pid);
	// 	if (dup2(fd1, STDIN_FILENO) < 0)
	// 		perror("*parent dup");
	// 	if (dup2(fd1, fds[WRITE]) < 0)
	// 		perror("**parent dup");
	// 	close(fd1);
	// 	close(fds[WRITE]);
	// }
	// // 자식 프로세스 : cmd2의 입력을 fd[READ] 하고 STDOUT 으로 출력
	// else
	// {
	// 	close(fds[WRITE]);
	// 	printf("child pid: %d\n", pid);
	// 	if (dup2(STDOUT_FILENO, fds[READ]) < 0)
	// 		perror("*parent dup");
	// 	if (dup2(fds[READ], fd2) < 0)
	// 		perror("**parent dup");
	// 	close(fd2);
	// 	close(fds[READ]);
	// }
	return 0;
}