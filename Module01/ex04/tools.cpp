#include "file_replace.hpp"

/*
 * Prints an error message
 *
 * @param e error code
 */
void	print_error(errors e)
{
	switch (e)
	{
	case NB_ARGS:
		std::cerr << "Error: wrong number of arguments. Usage: ./replace filename s1 s2" << std::endl;
		break;
	case INFILE:
		std::cerr << "Error: incorrect infile" << std::endl;
		break;
	case OUTFILE:
		std::cerr << "Error: incorrect outfile" << std::endl;
	default:
		break;
	}
}

/*
 * Copies a string into a file, replacing any occurence
 * of a given string by another
 *
 * @param out file to write into
 * @param s1 string to be replaced
 * @param s2 string to replace it with
 * @param buf string to copy
 */
void	ft_replace(std::ofstream& out, std::string s1, std::string s2, std::string buf)
{
	size_t	pos;
	size_t	end_pos;

	pos = buf.find(s1);
	if (pos == std::string::npos)
		out << buf;
	else
	{
		out << buf.substr(0, pos);
		out << s2;
		end_pos = pos + s1.length();
		ft_replace(out, s1, s2, buf.substr(end_pos));
	}
}
