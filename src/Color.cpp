#include "Color.hpp"
#include <iostream>

Color::Color(const std::string &hex)
{
	// Ignore first character, which is a hash #
	int rgb = std::stoi(hex.substr(1), nullptr, 16);
	_red = (rgb >> 16) & 0xff;
	_green = (rgb >> 8) & 0xff;
	_blue = rgb & 0xff;
}

Color::Color(const int &red, const int &green, const int &blue)
	: _red(red), _green(green), _blue(blue)
{}

Color::~Color() {}

const std::string		Color::toANSI() const {
	return std::string(
		"38;2;" + std::to_string(_red) +
		";" + std::to_string(_green) +
		";" + std::to_string(_blue)
	);
}

std::ostream & operator<<(std::ostream &os, const Color &color) {
	return os << "\033[" << color.toANSI() << "m";
};

std::ostream & operator<<(std::ostream &os, const Color::code &code) {
	return os << "\033[" << static_cast<int>(code) << "m";
};