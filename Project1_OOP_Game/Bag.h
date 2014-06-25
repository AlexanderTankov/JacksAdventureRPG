#pragma once
#include "Item.h"

class Bag
{
public:
	Bag();
	~Bag();
	Bag(const Bag& other);

	bool			operator == (const Bag& other);
	bool			operator != (const Bag& other);
	Bag&			operator = (const Bag& other);
	Item*			operator [] (const size_t idx);

	size_t			getCapacity() const;
	size_t			getFilledCells() const;
	Item**			getContentOfBag() const;

	void			setFilledCells(const size_t newNumOfFilledCells);

	void			addItemInBag(const Item* newItem);
	void			resizeBag(size_t newCapacity);
	void			copyBag(const Bag& other);
	void			clear();
	bool			isValid() const;

	void			printBag() const;
	std::ofstream&	saveBag(std::ofstream& fout) const;
	void			loadBag(std::ifstream& fin);

private:
	size_t			capacity;
	size_t			filledCells;
	Item**			contentOfBag;
};
