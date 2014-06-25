#pragma once
#include "Cell.h"
#include "BasicFeatures.h"

class Monster : public BasicFeatures , public Cell
{
public:
	Monster();
	~Monster();
	Monster(const Monster& other);
	Monster(const char* Name, size_t Attack, size_t Defense, size_t MaxLife, size_t Experience, size_t Row, size_t Column);

	size_t			getLife() const;
	size_t			getMaxLife() const;
	size_t			getExperience() const;
	
	void			setLife(size_t Life);
	void			setMaxLife(size_t MaxLife);
	void			setExperience(size_t Experience);

	std::ostream&	saveMonster(std::ofstream& fout) const;
	void			loadMonster(std::ifstream& fin);

	void			removeHealth(size_t Attack);
	size_t			reduceAttack(size_t Defense);
	void			printMonster() const;

private:
	size_t			Life;
	size_t			MaxLife;
	size_t			Experience;
};