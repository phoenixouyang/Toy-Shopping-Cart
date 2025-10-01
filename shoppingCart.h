#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include "toy.h"


class ShoppingCart {
	std::string m_name{};
	size_t m_age{};
	const Toy** m_toys{};
public:
	ShoppingCart(const std::string& name, int age, const Toy* toys[], size_t count);
	ShoppingCart(const ShoppingCart& src);
	ShoppingCart& operator=(const ShoppingCart& src);
	ShoppingCart(ShoppingCart&& src);
	ShoppingCart& operator=(ShoppingCart&& src);
	~ShoppingCart();
	friend std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart);
};

#endif // SHOPPINGCART_H