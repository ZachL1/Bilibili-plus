//应用程序开发人员
class Application : public Library {
protected:
	virtual bool Step2(){
		//... 子类重写实现
    }

    virtual void Step4() {
		//... 子类重写实现
    }
};




int main()
	{
	    Library* pLib=new Application();
	    lib->Run();

		delete pLib;
	}
}




