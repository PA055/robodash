// #include "main.h"
#include "robodash/api.h"

#ifdef SIMULATOR
#include "../simulator/init.h"
#endif

// ============================= Example autons ============================= //

void best_auton() { std::cout << "Running best auton" << std::endl; }
void simple_auton() { std::cout << "Running simple auton " << std::endl; }
void good_auton() { std::cout << "Running good auton" << std::endl; }

// ================================= Views ================================= //

// Create robodash selector
rd::Selector selector({
    {"Best auton", &best_auton},
    {"Simple auton", &simple_auton},
    {"Good auton", &good_auton},
});

// Create robodash console
rd::Console console;

// ========================= Competition Functions ========================= //

void initialize() {}

void disabled() {}

void competition_initialize() {
	// Focus auton selector on screen
	selector.focus();
}

void autonomous() {
	// Run the selected autonomous function
	selector.run_auton();
}

void opcontrol() {
	// Print hello 0-99 to the robodash console
	for (int i = 0; i < 100; i++) {
		console.printf("Hello %d\n", i);
		pros::delay(200);
	}
}

// ========================== Simulator Entrypoint ========================== //

#ifdef SIMULATOR
int main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	/*Initialize LVGL*/
	lv_init();

	/*Initialize the HAL (display, input devices, tick) for LVGL*/
	hal_init();

	while (1) {
		/* Periodically call the lv_task handler.
		 * It could be done in a timer interrupt or an OS task too.*/
		lv_timer_handler();
		usleep(5 * 1000);
	}

	return 0;
}
#endif