#pragma once

class BasicFeatures
{
public:
	BasicFeatures();
	~BasicFeatures();
	BasicFeatures(const BasicFeatures& other);
	BasicFeatures(const char* Name, size_t Attack, size_t Defense);

	bool			operator == (const BasicFeatures& other);
	bool			operator != (const BasicFeatures& other);
	BasicFeatures&	operator = (const BasicFeatures& other);

	char*			getName() const;
	size_t			getAttack() const;
	size_t			getDefense() const;

	void			setName(const char* Name);
	void			setAttack(size_t Attack);
	void			setDefense(size_t Defense);

	void			clear();
	void			copy(const BasicFeatures& other);

	void			printBasicFeatures() const;
	void			loadBasicFeatures(std::ifstream& fin);
	std::ostream&	saveBasicFeatures(std::ofstream& out) const;

private:
	char*			Name;
	size_t			Attack;
	size_t			Defense;
};
