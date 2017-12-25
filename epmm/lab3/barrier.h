#include <pthread.h>
#include <omp.h>
#include <iostream>
template <size_t offset>
class BarrierOMP {
	volatile int (*m_flags)[offset];
	size_t m_count;
	volatile bool m_expected_val;
public:
	BarrierOMP(size_t count) : m_count(count) {
		m_expected_val = true;
		m_flags = new int [m_count][offset];
	}

	void wait() {
		int id = omp_get_thread_num();
		if (id == 0) {
			while(true) {
				bool complete = true;
				bool expected_val = m_expected_val;
				for (size_t i = 1; i < m_count; ++i) {
					if (!(complete = (m_flags[i][0] == expected_val))) {
						break;
					}
				}
				if (complete) {
					m_expected_val = !expected_val;
					m_flags[0][0] = expected_val;
					break;
				}
			}
		} else {
			bool expected_val = m_expected_val;
			m_flags[id][0] = m_expected_val;
			while (m_flags[0][0] != expected_val);
		}
	}

	~BarrierOMP() {
		delete[] m_flags;
	}
};
template<>
class BarrierOMP<0> {
	public:
		BarrierOMP(size_t count){}
		inline void wait() {
			#pragma omp barrier
		}
};
