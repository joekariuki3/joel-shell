printf("PathNAme is valid -> %s\n", pathName);
/* Create a child process*/
pid = fork();
/*  Check if fork was a success */
if (pid == -1)
{
    perror("Fork failed");
    exit(1);
}
if (pid == 0)
{
    printf("start child process\n");
    /* execute a program using exec function */
    if (execve(pathName, wordArray, envp) == -1)
    {
        perror("Execution failed");
        exit(1);
    }
    /*  free pathName memory*/
    free(pathName);
}
if (waitpid(pid, &status, 0) == -1)
{
    perror("Error on Wait");
    exit(1);
}
break;

/* free each index memory */
i = 0;
while (pathArray[i])
{
    free(pathArray[i]);
    i++;
}
/* free the pathArray */
free(pathArray);
break;

/* loop through envp vector to find the path variable */
for (i = 0; envp[i] != NULL; i++)
{
    /*look for PATH using strncmp*/
    if (strncmp(envp[i], "PATH=", 5) == 0)
    {
        allPath = envp[i] + 5; /*remove PATH=*/
        break;
    }
}
tempAllPath = strdup(allPath);
printf(" before strtok tempAllPath  %s\n", tempAllPath);
path = strtok(tempAllPath, ":");
printf(" after 1st strtok tempAllPath %s\n", tempAllPath);
while (path)
{
    printf("path-> : %s\n", path);
    path = strtok(NULL, ":");
}
free(tempAllPath);