#pragma once

#include <map>
#include <string>



#define TR_INPUT_MANAGER_READ_CHUNK_SIZE 512

namespace tr {
	enum class Key {
		eA = 0, eB, eC, eD, eE, eF, eG, eH, eI, eJ, eK, eL, eM, eN, eO, eP, eQ, eR, eS, eT, eU, eV, eW, eX, eY, eZ,
		e1, e2, e3, e4, e5, e6, e7, e8, e9, e0,
		eSpace,
		eEnter,
		eCtrl,
		eShift,
		eAlt,
		eUp, eDown, eLeft, eRight,
		eBackspace,
		eEscape,
		eTabs,
		eDelete,

		__maxEnumValue
	};

	class InputManager {
		public:
			static void load();
			static void update();

			static bool isKeyDown(tr::Key key);
			static bool isKeyUp(tr::Key key);
			static bool wasKeyPressed(tr::Key key);
			static bool wasKeyReleased(tr::Key key);

			static bool hasInput();
			static const std::string &getInput();

		private:
			static std::map<tr::Key, bool> s_keyStates;
			static std::map<tr::Key, bool> s_oldKeyStates;
			static std::string s_input;
	};

} // namespace tr
