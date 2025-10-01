#ifndef TOY_H
#define TOY_H

#include <iostream>

class Toy {
	size_t m_id{};
	std::string m_name{};
	int m_numItems{};
	float m_price{};
	float m_hst{0.13};
public:
	Toy() {};
	Toy(const std::string& toy);
	void update(int numItems);
	friend std::ostream& operator<<(std::ostream& os, const Toy t);
};

#endif // TOY_H