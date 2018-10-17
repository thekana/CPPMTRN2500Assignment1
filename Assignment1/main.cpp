#include <iostream>
#include "XBoxController.h"

int main(void) {
	XInputWrapper xinput;
	DWORD id = 0;
	int instance = 0;
	bool quit = TRUE;
	GamePad::XBoxController player0(&xinput, 0);
	GamePad::XBoxController player1(&xinput, 1);
	GamePad::XBoxController player2(&xinput, 2);
	GamePad::XBoxController player3(&xinput, 3);
	CheckConnection(player0, instance);
	CheckConnection(player1, instance);
	CheckConnection(player2, instance);
	CheckConnection(player3, instance);
	Sleep(3000);
	player0.SetDeadzone(25000);
	player0.SetVibrateButton(bA+bUP);
	player1.SetDeadzone(10000);
	player1.SetVibrateButton(bBACK);

	if (instance > 0) {
		quit = FALSE;
	}
	while (!quit) {
		if (player0.PressedStart()) {
			while (!quit) {
				if (StartConsole(player0) + StartConsole(player1) + StartConsole(player2) + StartConsole(player3)) {
					Sleep(100);
				}
				else {
					quit = TRUE;
				}
			}
		}
		else {
			std::cout << "Press START to START" << std::endl;
		}
	}
	return EXIT_SUCCESS;
}