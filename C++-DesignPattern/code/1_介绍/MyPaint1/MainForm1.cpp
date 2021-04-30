
class MainForm : public Form {
private:
	Point p1;
	Point p2;

	vector<Line> lineVector;
	vector<Rect> rectVector;
	//改变
	vector<Circle> circleVector;

public:
	MainForm(){
		//...
	}
protected:

	virtual void OnMouseDown(const MouseEventArgs& e);
	virtual void OnMouseUp(const MouseEventArgs& e);
	virtual void OnPaint(const PaintEventArgs& e);
};


void MainForm::OnMouseDown(const MouseEventArgs& e){
	p1.x = e.X;
	p1.y = e.Y;

	//...
	Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
	p2.x = e.X;
	p2.y = e.Y;

	if (rdoLine.Checked){
		Line line(p1, p2);
		lineVector.push_back(line);
	}
	else if (rdoRect.Checked){
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		Rect rect(p1, width, height);
		rectVector.push_back(rect);
	}
	//改变
	else if (...){
		//...
		circleVector.push_back(circle);
	}

	//...
	this->Refresh();

	Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e){

	//针对直线
	for (int i = 0; i < lineVector.size(); i++){
		e.Graphics.DrawLine(Pens.Red,
			lineVector[i].start.x, 
			lineVector[i].start.y,
			lineVector[i].end.x,
			lineVector[i].end.y);
	}

	//针对矩形
	for (int i = 0; i < rectVector.size(); i++){
		e.Graphics.DrawRectangle(Pens.Red,
			rectVector[i].leftUp,
			rectVector[i].width,
			rectVector[i].height);
	}

	//改变
	//针对圆形
	for (int i = 0; i < circleVector.size(); i++){
		e.Graphics.DrawCircle(Pens.Red,
			circleVector[i]);
	}

	//...
	Form::OnPaint(e);
}

