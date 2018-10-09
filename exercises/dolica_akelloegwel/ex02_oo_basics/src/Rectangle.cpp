#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : Shape(w * 2 + h * 2, w * h, "Rectangle", 4)
{
	width = w;
	height = h;
}
double Rectangle::GetWidth()
{
	return width;
}
double Rectangle::GetHeight()
{
	return height;
}

void Rectangle::write(std::ostream & os) const
{
	os << "This is a rectangle." << std::endl;
}

/**
std::ostream & Rectangle::operator<<(std::ostream & os)
{
	return os << " is a " << this->GetType() << " with height " << this->GetHeight() << " and width " << this->GetWidth() << "." << std::endl;
}
**/