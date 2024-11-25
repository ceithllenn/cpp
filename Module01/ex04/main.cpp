#include "file_replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		s1;
	std::string		s2;
	std::string		file;
	std::string		new_file;
	std::string		buf;

	if (argc != 4)
		return (print_error(NB_ARGS), 0);

	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	new_file = file + ".replace";

	infile.open(file.c_str(), std::_S_in);
	if (!infile.good())
		return (print_error(INFILE), 0);

	outfile.open(new_file.c_str(), std::_S_out);
	if (!outfile.good())
		return (print_error(OUTFILE), 0);

	while (getline(infile, buf))
			ft_replace(outfile, s1, s2, buf + '\n');

	infile.close();
	outfile.close();
	return (0);
}
