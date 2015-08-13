#include <iostream>
#include <fstream>
#include "Cell.h"

using namespace std;

//Constructor
Cell::Cell()
{
	this->row = 0;
	this->column = 0;
	this->symbol = NULL;
}

//Destructor
Cell::~Cell()
{
}

//Constructor for easy creating a Cell
Cell::Cell(size_t Row, size_t Column, char Symbol)
{
	this->row = Row;
	this->column = Column;
	this->symbol = Symbol;
}

//Constructor for easy creating a Cell
Cell::Cell(char Symbol)
{
	this->row = 1;
	this->column = 1;
	this->symbol = Symbol;
}

//Constructor for copy one Cell to other
Cell::Cell(const Cell& other)
{
	this->row = other.getRow();
	this->column = other.getColumn();
	this->symbol = other.getSymbol();
}


//Compares that two cells are equal
bool Cell::operator == (const Cell& other)
{
	if((this->row == other.getRow()) && (this->column == other.getColumn()) && (this->symbol = other.getSymbol()))
		return true;
	else
		return false;
}

//Compares that two cells are not equal
bool Cell::operator != (const Cell& other)
{
	return !(*this == other);
}

//Equated two cells
Cell& Cell::operator = (const Cell& other)
{
	if(*this != other)
	{
		this->row = other.getRow();
		this->column = other.getColumn();
		this->symbol = other.getSymbol();
	}
	return *this;
}


//Get cell row
size_t Cell::getRow() const
{
	return this->row;
}

//Get cell column
size_t Cell::getColumn() const
{
	return this->column;
}

//Get cell symbol
char Cell::getSymbol() const
{
	return this->symbol;
}


//Set row to cell
void Cell::setRow(size_t Row)
{
	this->row = Row;
}

//Set column to cell
void Cell::setColumn(size_t Column)
{
	this->column = Column;
}

//Set symbol to cell
void Cell::setSymbol(char Symbol)
{
	if(Symbol != NULL)
		this->symbol = Symbol;
	else
		cout << "Dont have symbol to set! " << endl;
}


//Save Cell in flow
void Cell::saveCell(ofstream& fout) const
{
	fout << getRow() << endl;
	fout << getColumn() << endl;
}

//Load cell from flow
Cell Cell::loadCell(ifstream& fin)
{
	fin >> this->row;
	fin >> this->column;
	return *this;
}

//Print cell
void Cell::printCell() const
{
	cout << this->symbol;
}


