#include <iostream>
#include <string>
#include <fstream>

int	open_files(std::ifstream &infile, std::ofstream &outfile)
{
	if (!infile && !outfile)
		return (1);
	if (!outfile)
	{
		infile.close();
		return (1);
	}
	if (!infile)
	{
		outfile.close();
		return (1);
	}
	return (0);
}

void	close_files(std::ifstream &infile, std::ofstream &outfile)
{
	infile.close();
	outfile.close();
}

void	getfile(std::ifstream &infile, std::string &file)
{
	std::string	line;

	while (std::getline(infile, line))
	{
		file.append(line);
		file.append("\n");
	}
}

void	replace_file(std::string &file, std::string old_str, std::string new_str)
{
	if (old_str == "")
		return ;
	for (size_t i = 0; i != file.length(); i++)
	{
		if(!file.compare(i, old_str.length(), old_str))
		{
			file.erase(i,  old_str.length());
			file.insert(i, new_str);
			i += new_str.length() - 1;
		}
	}
}


int	main(int argc, char **argv)
{
	std::string	file;
	std::string outfile_name;

	if (argc != 4)
		return (1);
	outfile_name = argv[1];
	outfile_name.append(".replace");
	std::ifstream infile(argv[1]);
	std::ofstream outfile(outfile_name.c_str());

	if (open_files(infile, outfile))
	{
		std::cout << "can't open file(s)" << std::endl;
		return (1);
	}
	getfile(infile, file);
	replace_file(file, argv[2], argv[3]);
	outfile << file;
	close_files(infile, outfile);	
	return (0);
}
