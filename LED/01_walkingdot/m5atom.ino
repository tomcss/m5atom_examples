#include "M5Atom.h"

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    M5.dis.drawpix(0, 0xf00000);
}

uint8_t FSM = 0;
int xpos = 0;
int ypos = 0;

void loop()
{

    M5.dis.drawpix(xpos+ypos*5, 0);

    int mov = random(2);
    if( mov == 0) mov = -1;
    if( random(2)==1) { // move horizontally
        if( (xpos+mov>=0) && (xpos+mov<=4)) xpos += mov;
    } else { // move vertically
        if( (ypos+mov>=0) && (ypos+mov<=4)) ypos += mov;
    }

    M5.dis.drawpix(xpos+ypos*5, 0xf00000);
    
    delay(50);
    M5.update();
}
