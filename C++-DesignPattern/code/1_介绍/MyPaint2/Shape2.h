class Shape{
public:
	virtual void Draw(const Graphics& g)=0;
	virtual ~Shape() { }
};


class Point{
public:
	int x;
	int y;
};

class Line: public Shape{
public:
	Point start;
	Point end;

	Line(const Point& start, const Point& end){
		this->start = start;
		this->end = end;
	}

	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawLine(Pens.Red, 
			start.x, start.y,end.x, end.y);
	}

};

class Rect: public Shape{
public:
	Point leftUp;
	int width;
	int height;

	Rect(const Point& leftUp, int width, int height){
		this->leftUp = leftUp;
		this->width = width;
		this->height = height;
	}

	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawRectangle(Pens.Red,
			leftUp,width,height);
	}

};

//增加
class Circle : public Shape{
public:
	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawCircle(Pens.Red,
			...);
	}

};






