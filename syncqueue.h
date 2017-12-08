#include<list>
#include<mutex>
#include<iostream> 
#include<utility> //forward
#include<condition_variable>

template<typename T>
class SyncQueue{
public:
	SyncQueue(int maxsize):m_maxSize(maxsize),
				m_needStop(false){}
	void Put(const T& x){
		Add(x);
	}
	void Put(T&& x){
		Add(std::forward<T>(x));
	}
	void Take(std::list<T>& list){
		std::unique_lock<mutex> locker(m_mutex);
		m_notEmpty.wait(locker,[this]{ return m_needStop||NotEmpty();});
		//while (!pred()) wait(locker);
		if(m_needStop)
			return;
		list=std::move(m_queue);
		m_notFull.notify_one();
	}
	void Take(T& t){
		std::unique_lock<mutex> locker(m_mutex);
		m_notEmpty.wait(locker,[this]{return m_needStop||NotEmpty();});
		if(m_needStop)
			return;
		t=m_queue.front();
		m_queue.pop_front();
		m_notFull.notify_one();
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
	bool NotEmpty()const{
		
	}
private:
	std::list<T> m_queue;
	std::mutex m_mutex;
	std::condition_variable m_notEmpty;//不空的信号
	std::condition_variable m_notFull;//不满的信号
	int m_maxSize;
	bool m_needStop;	
};
