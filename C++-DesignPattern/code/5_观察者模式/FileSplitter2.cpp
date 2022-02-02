class IProgress{
public:
	virtual void DoProgress(float value)=0;
	virtual ~IProgress(){}
};


class FileSplitter
{
	string m_filePath;
	int m_fileNumber;

	List<IProgress*>  m_iprogressList; // 抽象通知机制，支持多个观察者
	
public:
	FileSplitter(const string& filePath, int fileNumber) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber){

	}


	void split(){

		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...

			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);//发送通知
		}

	}


	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress);
	}

	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}


protected:
	virtual void onProgress(float value){
		
		List<IProgress*>::iterator itor=m_iprogressList.begin();

		while (itor != m_iprogressList.end() )
			(*itor)->DoProgress(value); //更新进度条
			itor++;
		}
	}
};