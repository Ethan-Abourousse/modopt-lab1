#include "Countdown.h"

void Countdown::count(void) {
	//for (int i = 3; i >= 1; --i) {
		//std::cout << "Countdown: " << i << std::endl;
		//wait(1, SC_NS);
	//}
     for (int i = 20; i>=1; --i){
          std::cout << "Countdown: " << i << std::endl;
          wait(20, SC_NS);
     }
}
