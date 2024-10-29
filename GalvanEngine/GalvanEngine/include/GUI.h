#pragma once
#include "Prerequisites.h"

class Window;

class 
GUI {
public:
	GUI() = default;
	~GUI() = default;

	void
	init();

	void
	update();

	void
	render();

	void
	destroy();

	void 
	setupGUIStyle();

	void 
	console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);

private:
};