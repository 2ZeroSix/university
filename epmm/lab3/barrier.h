#include <pthread.h>
#include <omp.h>
#include <iostream>
template <size_t offset>
class BarrierOMP {
	volatile int (*m_flags)[offset];
	size_t m_count;
	volatile bool m_complete;
public:
	BarrierOMP(size_t count) : m_count(count - 1) {
		m_complete = false;
		m_flags = new int [m_count][offset];
	}

	void wait() {
		int id = omp_get_thread_num();
		if (id == 0) {
			do {
				bool complete = true;
				for (size_t i = 0; i < m_count; ++i) {
					if (!(complete = m_flags[i][0])) {
						break;
					}
				}
				m_complete = complete;
			} while (!m_complete);
			do {
				bool complete = false;
				for (size_t i = 0; i < m_count; ++i) {
					if ((complete = m_flags[i][0])) {
						break;
					}
				}
				m_complete = complete;
			} while (m_complete);
		} else {
			m_flags[(id - 1)][0] = true;
			while (!m_complete) {
			}
			m_flags[(id - 1)][0] = false;
			while (m_complete) {
			}
		}
	}

	~BarrierOMP() {
		delete[] m_flags;
	}
};
