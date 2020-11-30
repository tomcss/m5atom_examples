#include "M5Atom.h"
#include <list>

/*
 * Show a matrix of falling green dots at different speeds
 */


class Dot {
    public:
        float speed;
        int brightness;
        float x;
        float y;

        Dot() {
            this->x = random(0,5);
            this->y = -random(1,5);

            this->speed = random(100,1000)/1000.0;
            this->brightness = random(50,200);
        }

        void update() {
            this->y += this->speed;
        }
};

std::list<Dot> dots;

const int TICK_DURATION = 100;
const int DOT_COUNT = 20;

void setup()
{
    M5.begin(true, false, true);
    delay(50);

    for(int i=0; i<2; i++) {
        Dot dot;

        dots.push_back( dot);
    }
}

void clear_screen() {
    for(int i=0; i<25; i++) M5.dis.drawpix( i, 0);
}

bool is_gone(const Dot& dot) { // Is the dot no longer visible?
    return (dot.y>=6);
}

void fill_dots() { // Add dots until we're at DOT_COUNT dots
    while( dots.size()<DOT_COUNT) {
        Dot dot;
        dots.push_back( dot);
    }
}

void loop()
{
    clear_screen();

    fill_dots();

    for( std::list<Dot>::iterator it=dots.begin(); it != dots.end(); ++it) {

        it->update();

        if( it->y>=0) {
            M5.dis.drawpix( int(it->x)+int(it->y)*5, it->brightness*256*256);
        }
    }

    dots.remove_if( is_gone);

    delay(TICK_DURATION); // Tick
    M5.update();
}
