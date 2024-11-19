#pragma once
#include "Prerequisites.h"
class Window;
class Actor;

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
	barMenu();

	void
	Outliner(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

	void 
	console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);

	void 
  inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

	void
  vec2Control(const std::string& label,
              float* values,
              float resetValues = 0.0f,
              float columnWidth = 100.0f);

private:
	int selectedActorIndex = -1;
};