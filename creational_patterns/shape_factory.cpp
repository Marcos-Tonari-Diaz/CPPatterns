#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Shape{
	public:
		string shape_name = "Shape";
		Shape(string name): shape_name{name}{};
		virtual void drawShape() = 0;
		string getName(){return shape_name;};
};

class Square: public Shape{
	int lenght;
	public:
		Square(int lenght): Shape{"Square"}, lenght{lenght}{};
		void drawShape() override {
			cout << "Square, area: " << lenght*lenght << endl;	
		}
};

class Circle: public Shape{
	int radius;
	public:
		Circle(int radius): Shape{"Circle"}, radius{radius}{};
		void drawShape() override {
			cout << "Circle, area: " << M_PI*radius*radius << endl;	
		}
};

class ShapeFactory{
	public:
	virtual Shape* createShape(int size) = 0;
};

class SquareFactory : public ShapeFactory{
	public:
	Shape* createShape(int size) override {return new Square(size);}
};

class CircleFactory : public ShapeFactory{
	public:
	Shape* createShape(int size) override {return new Circle(size);}
};

class Canvas{
	vector<Shape*> shape_vector;
	public:
		void addShape(ShapeFactory* shape_creator, int size){
			shape_vector.push_back(shape_creator->createShape(size));
			cout << "Added shape: " + shape_vector.back()->getName() << endl;
		}
		void renderAllShapes(){
			for (Shape* shape: shape_vector)
				shape->drawShape();
		}
};

int main(){
	ShapeFactory* square_factory = new SquareFactory();
	ShapeFactory* circle_factory = new CircleFactory();
	Canvas canvas;
	canvas.addShape(square_factory, 5);
	canvas.addShape(circle_factory, 10);
	canvas.renderAllShapes();
	return 0;
}
