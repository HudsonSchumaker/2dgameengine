/*
	Windows 10 - 11
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "System.h"

class RenderSystem final : public System {
private:
	SDL_Renderer* renderer = nullptr;

public:
	RenderSystem();
	~RenderSystem() = default;
	void update(float dt) override;
};