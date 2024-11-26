int main()
{
	int i = 0;
	char *line;
	int fd = open("test");
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}