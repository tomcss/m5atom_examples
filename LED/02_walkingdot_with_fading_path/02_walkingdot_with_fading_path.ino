#include "M5Atom.h"

int shadow_lights[25]; // This will hold our fading path data

void setup()
{
    M5.begin(true, false, true);
    delay(50);

    for( int i=0; i<25; i++) {
        shadow_lights[i] = 0;
    }
}

uint8_t FSM = 0;
int xpos = 0;
int ypos = 0;

void draw_shadow() {
    for(int i=0; i<25; i++) {
        M5.dis.drawpix( i, shadow_lights[i]*256);
    }
}

void fade_shadow() {
    for(int i=0; i<25; i++) {
        shadow_lights[i] *= 0.9; // Reducing the path brightness by 10% every tick
        if( shadow_lights[i]<40) {
            shadow_lights[i] = 0;

        }
    }
}

void move_dot() {

    int mov = random(2);
    if( mov == 0) mov = -1;

    if( random(2)==1) { // move horizontally
        if( (xpos+mov>=0) && (xpos+mov<=4)) xpos += mov;
    } else {            // move vertically
        if( (ypos+mov>=0) && (ypos+mov<=4)) ypos += mov;
    }

    shadow_lights[ xpos+ypos*5] = 200; // Setting the path brightness to 200
}

void loop()
{
    draw_shadow();
    fade_shadow();

    move_dot();

    M5.dis.drawpix(xpos+ypos*5, 0xf00000);
    
    delay(100);
    M5.update();
}
