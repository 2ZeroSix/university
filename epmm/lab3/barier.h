#include <pthread.h>

class Barrier {
	int* m_flags;
	size_t m_offset;
	size_t m_count;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	Barrier(size_t count, size_t offset = 1) : m_count(count), m_offset(offset) {
		m_flags = new int[count*offset];
		mutex = PTHREAD_MUTEX_INITIALIZER;
		cond = PTHREAD_COND_INITIALIZER;
	}

	void wait() {
		
	}

	~Barrier() {
		delete[] m_flags;
		pthread_mutex_destroy(&mutex);
		pthread_cond_destroy(&cond);
	}
};
