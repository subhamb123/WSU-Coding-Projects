#include "parent.h"

void init_employee(Employee* payroll) {
	for (int i = 0; i < 200; i++) {
		payroll[i].hours_worked = 0;
		strcpy(payroll[i].name, "");
		payroll[i].payment = 0;
		payroll[i].payrate = 0;
		payroll[i].title = '\0';
	}
}