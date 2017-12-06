#include<list>
#include<mutex>
#include<iostream> 
#include<utility> //forward
template<typename T>
class SyncQueue{
public:
	SyncQueue(int maxsize):m_maxSize(maxsize),
				m_needStop(false){}
	void Put(const T& x){
		Add(x);
	}
	void Put(T&& x){
		Add(std::forward<T>x);
	}
	void Take(std::list<T>& list){
		
	}
	void Take(T& t){
		
	}
	void Stop(){
		
	}
	bool Empty(){
		
	}
	bool Full(){
	}
	size_t Size(){
	}
private:
	int m_maxSize;
	bool m_needStop;	
};
