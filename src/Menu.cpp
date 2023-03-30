
#include "Menu.h"
#include "ecs/EntityManager.h"
#include "gfx/Sprite.h"
#include "gfx/Color.h"
#include "ecs/component/Button.h"
#include "ecs/component/TextLabel.h"
#include "ecs/component/Transform.h"

Menu::Menu() {
}

Menu::~Menu() {
    unload();
}

void Menu::load() {
    background = EntityManager::getInstance()->createEntity(0, 0);
    background->addComponent(new Sprite("back129", true, (int)Tag::background));
    background->getComponent<Sprite>()->setOnCenterX();

    title = EntityManager::getInstance()->createEntity(350, 0);
    title->addComponent(new TextLabel("HemiHead.ttf", true, title->getComponent<Transform>()->position, "Only One dodoi engine", 60, Color::getRed()));
    title->getComponent<TextLabel>()->setOnCenterX();

	button = EntityManager::getInstance()->createEntity(352, 360);
	button->addComponent(new Sprite("hard", true, (int)Tag::ui));
	button->addComponent(new BoxCollider(button->getComponent<Sprite>()->getSize()));
	button->addComponent(new Button());

    isRunning = true;
}

short Menu::run() {
    load();
    while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void Menu::input() {
	SDL_Event sdlEvent;
	SDL_GetMouseState(&pointer.x, &pointer.y);
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			exit = QUIT;
			break;
		}
	}
}

void Menu::update() {
    lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (float)((currentTick - lastTick) * 1000.0f / (float)SDL_GetPerformanceFrequency());

	EntityManager::getInstance()->update();
	collisionSystem.update();
	mouseCollisionSystem.update(pointer);
}

void Menu::render() {
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
		
	renderSystem.update(&camera);
	renderTextSystem.update(&camera);

	SDL_RenderPresent(renderer);
}

void Menu::unload() {
    EntityManager::getInstance()->clear();
}
