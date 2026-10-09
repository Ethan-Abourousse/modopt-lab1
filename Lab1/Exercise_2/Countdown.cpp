#include "Countdown.h"

void Countdown::count(void) {
	for (int i = 3; i >= 1; --i) {
		std::cout << "Countdown: " << i << std::endl;
		wait(1, SC_NS);
	}
}
