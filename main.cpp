#include "ui.h"
int main() {
	Registry r;

	GUI ui(r);
	ui.InitNC();

	ui.RunMenu();

    return 0;
}
