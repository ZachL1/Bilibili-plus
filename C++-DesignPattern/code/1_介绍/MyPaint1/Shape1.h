class Point{
public:
	int x;
	int y;
};

class Line{
public:
	Point start;
    Point end;

	Line(const Point& start, const Point& end){
        this->start = start;
        this->end = end;
    }

};

class Rect{
public:
	Point leftUp;
    int width;
	int height;

	Rect(const Point& leftUp, int width, int height){
        this->leftUp = leftUp;
        this->width = width;
		this->height = height;
    }

};

//Ôö¼Ó
class Circle{


};
 

