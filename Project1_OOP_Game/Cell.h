#pragma once
#include <fstream>

class Cell
{
public:
	Cell();
	~Cell();
	Cell(size_t Row, size_t Column, char Symbol);
	Cell(char Symbol);
	Cell(const Cell& other);

	bool	operator == (const Cell& other);
	bool	operator != (const Cell& other);
	Cell&	operator = (const Cell& other);

	size_t	getRow() const;
	size_t	getColumn() const;
	char	getSymbol() const;

	void	setRow(size_t Row);
	void	setColumn(size_t Column);
	void	setSymbol(char Symbol);

	void	saveCell(std::ofstream& fout) const;
	Cell	loadCell(std::ifstream& fin);

	void	printCell() const;

private:
	size_t	row;
	size_t	column;
	char symbol;
};
