#pragma once
class Color {
public:
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	unsigned char r, g, b, a;
};