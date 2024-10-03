#include <hardware/clocks.h>
#include <pico/stdio.h>
#define DELAY 500
int main() { set_sys_clock_khz(18000, true); }
