#include <string>
#include "toy.h"

using namespace std;

void Toy::update(int numItems) {
	m_numItems = numItems;
}

Toy::Toy(const string& toy) {
	string tempToy = toy;

	// use lambda to make a trim function
	auto trim = [&](string s) -> string {
		string trimS = s;
		bool done = false;
		size_t i = 0;

		// trim beginning
		do {
			if (trimS[i] == ' ')
				trimS = trimS.substr(i + 1);
			else
				done = true;
		} while (!done);

		// trim end
		done = false;
		i = trimS.length() - 1;
		do {
			if (trimS[i] == ' ')
				trimS = trimS.substr(0, i);
			else
				done = true;
			i--;
		} while (!done);

		return trimS;
	};

	// extract id
	size_t idx = tempToy.find(':');
	m_id = stoul(trim(tempToy.substr(0, idx)));
	tempToy.erase(0, idx + 1);

	// extract name
	idx = tempToy.find(':');
	m_name = trim(tempToy.substr(0, idx));
	tempToy.erase(0, idx + 1);

	// extract numItems
	idx = tempToy.find(':');
	m_numItems = stoi(trim(tempToy.substr(0, idx)));
	tempToy.erase(0, idx + 1);

	// extract price
	idx = tempToy.find(':');
	m_price = stof(trim(tempToy.substr(0, idx)));
}

std::ostream& operator<<(std::ostream& os, const Toy t) {
	float subtotal = t.m_price * t.m_numItems;
	float tax = subtotal * t.m_hst;
	float totalPrice = subtotal + tax;
	os << "Toy ";
	os.width(8);
	os.setf(ios::right);
	os.setf(ios::fixed);
	os.fill(0);
	os << t.m_id << ": ";
	os.width(24);
	os.fill('.');
	os << t.m_name << " ";
	os.width(2);
	os.fill(' ');
	os << t.m_numItems << " @ ";
	os.width(6);
	os.precision(2);
	os << t.m_price << "/item subtotal: ";
	os.width(7);
	os << subtotal << " tax: ";
	os.width(6);
	os << tax << " total: ";
	os.width(7);
	os << totalPrice << endl;

	os.unsetf(ios::fixed);
	os.unsetf(ios::right);

	return os;
}
