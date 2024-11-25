#ifndef FILE_REPLACE_HPP
# define FILE_REPLACE_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>

enum errors
{
	NB_ARGS,
	INFILE,
	OUTFILE
};

void	print_error(errors e);
void	ft_replace(std::ofstream& out, std::string s1, std::string s2, std::string buf);

#endif