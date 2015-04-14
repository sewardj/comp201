#include "controller.h"
#include <map>
#include <iostream>

using namespace std;

Controller::Controller() {
    model = new Model();
    view = new View("Game", 1024, 768);
}

Controller::~Controller() {
    delete model;
    delete view;
}
/**
References:
https://wiki.libsdl.org/SDL_PollEvent
https://wiki.libsdl.org/SDL_Event
*/
void Controller::loop() {
    SDL_Event e;
    unsigned int lastTime = 0, currentTime;
    std::map<SDL_Keycode, char> letter;
    letter[SDLK_a] = 'A';
    letter[SDLK_b] = 'B';
    letter[SDLK_c] = 'C';
    letter[SDLK_d] = 'D';
	letter[SDLK_e] = 'E';
	letter[SDLK_f] = 'F';
	letter[SDLK_g] = 'G';
	letter[SDLK_h] = 'H';
	letter[SDLK_i] = 'I';
	letter[SDLK_j] = 'J';
	letter[SDLK_k] = 'K';
	letter[SDLK_l] = 'L';
    letter[SDLK_m] = 'M';
	letter[SDLK_n] = 'N';
	letter[SDLK_o] = 'O';
	letter[SDLK_p] = 'P';
	letter[SDLK_q] = 'Q';
	letter[SDLK_r] = 'R';
	letter[SDLK_s] = 'S';
	letter[SDLK_t] = 'T';
	letter[SDLK_u] = 'U';
	letter[SDLK_v] = 'V';
	letter[SDLK_w] = 'W';
	letter[SDLK_x] = 'X';
	letter[SDLK_y] = 'Y';
	letter[SDLK_z] = 'Z';

	SDL_Rect choice[3];
	for (int i = 0; i < 3; i++) {
		choice[i].x = 100 * i + 20*i;
		choice[i].y = 80;
		choice[i].w = 100;
		choice[i].h = 30;
	}

    while(!model->gameOver() || model->state == NEW_GAME) {
        currentTime = SDL_GetTicks();
        // Do stuff here to animate as necessary
        view->show(model);
        if (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                return;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym) {
                    model->makeGuess(letter[e.key.keysym.sym]);
                break;
                default:
                break;
                }
            case SDL_MOUSEBUTTONDOWN:
				if (model->state == NEW_GAME) {
					SDL_Rect mouse;
					mouse.x = e.button.x;
					mouse.y = e.button.y;
					mouse.w = 1;
					mouse.h = 1;
					for (int i = 0; i < 3; i++) {
						if (SDL_HasIntersection(&mouse, &choice[i])) {
							model->makeChoice(i);
							cout << i<< endl;
						}
					}
					// set the choice
				}
                break;
            }
        }
    }
    // TODO: show something nice?
    view->show(model);
    SDL_Delay(3000);
}
