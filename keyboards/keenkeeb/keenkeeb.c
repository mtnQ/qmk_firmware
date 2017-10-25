#include "keenkeeb.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    //MCUCR |= (1<<JTD);
    //MCUCR |= (1<<JTD);
    
    matrix_init_user();
}
