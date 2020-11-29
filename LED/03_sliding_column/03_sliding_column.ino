#include "M5Atom.h"

/*
 * A sliding column that alernates between a row and a column
 */

/*
 * Positions 0-4 are horizontal columns,
             5-9 vertical
 */

int position = 0; 
int tick_duration = 100; // milliseconds

void setup()
{
    M5.begin(true, false, true);
    delay(50);
}

void clear_display() {
    for(int i=0; i<25; i++) M5.dis.drawpix( i, 0);
}

void draw_vertical( int pos) {
    for(int y=0; y<5; y++) M5.dis.drawpix( pos+y*5, 0x0000f0);
}

void draw_horizontal( int pos) {
    for(int x=0; x<5; x++) M5.dis.drawpix( x+pos*5, 0x00f000);
}

void loop()
{
    clear_display();

    if( position<5) {
        draw_horizontal( position);
    } else {
        draw_vertical( position%5);
    }
    
    delay( tick_duration);
    position = (position+1)%10;

    M5.update();
}
