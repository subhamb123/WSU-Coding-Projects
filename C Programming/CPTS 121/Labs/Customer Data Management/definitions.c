#include "parent.h"

void initProfile(Profile* customers) {
	for (int i = 0; i < 100; i++) {
		strcpy(customers[i].name, "");
		customers[i].plan = '\0';
		customers[i].talk_minutes = 0;
		customers[i].data_MB = 0;
		customers[i].charges = 0;
	}
}