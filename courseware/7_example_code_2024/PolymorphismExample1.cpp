#include <iostream>
using namespace std;

class Point {public: float x, y;};    // (x,y) point

class Shape {
public:
	Shape(){};
	virtual ~Shape() {}
	virtual void render() { cout << "Shape::render is called" <<endl;}
	virtual void resize() {}
	void move(const Point& p) {center = p;}
protected:
	Point center;
};

class Ellipse: public Shape {
public:
	Ellipse(float major, float minor):major_axis(major), minor_axis(minor) {}
	virtual ~Ellipse() {}
	virtual void render() {cout << "Ellipse:: render called" << endl << "major_axis: " << major_axis << " minor_axis: " << minor_axis <<endl;}
protected:
	float major_axis, minor_axis;
};

class Circle: public Ellipse {
public:
	Circle(float radius) : Ellipse(radius, radius), m_radius(radius) {}
	virtual ~Circle() {}
	virtual void render(){cout << "Circle:: render called" << endl;}
protected:
	float m_radius;
};


void render(Shape* p) {
    p->render(); // calls correct render function
} // for given Shape!


int main() {
    Ellipse ell(20, 10);
    ell.render(); // static -- Ellipse::render();

    Circle circ(40);
    circ.render(); // static -- Circle::render();

    cout << "----------1------" <<endl;
    render(&ell); // dynamic -- Ellipse::render();
    render(&circ); // dynamic -- Circle::render()

	cout << "----------2------" <<endl;
    Shape &s = circ;
    s.render();
	
	Shape *s1 = &circ;
    s1->render();
	
	cout << "----------3------" <<endl;
	// Sliced
	ell = circ;
	ell.render();
	
}
