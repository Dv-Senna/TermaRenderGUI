#include "tr/inputManager.hpp"

#include <iostream>
#include <stdexcept>

#include <poll.h>
#include <unistd.h>

#include "tr/types.hpp"



namespace tr {
	void InputManager::load() {
		for (tr::Uint64 i {0}; i <  (tr::Uint64)tr::Key::__maxEnumValue; ++i) {
			s_keyStates[(tr::Key)i] = false;
			s_oldKeyStates[(tr::Key)i] = false;
		}
	}

	void InputManager::update() {
		std::string inputBuffer {};
		inputBuffer.reserve(TR_INPUT_MANAGER_READ_CHUNK_SIZE);

		struct pollfd stdin_poll {
			.fd = STDIN_FILENO,
			.events = POLLIN | POLLRDBAND | POLLRDNORM | POLLPRI
		};

		while (true) {
			if (poll(&stdin_poll, 1, 0)  != 1)
				break;

			int character {fgetc(stdin)};
			if (character != EOF) {
				inputBuffer.push_back((char)character);
				continue;
			}

			if (feof(stdin))
				break;
			throw std::runtime_error("ERROR while reading stdin : " + std::to_string(ferror(stdin)));
		}

		if (!inputBuffer.empty())
			std::cout << inputBuffer << std::endl;
	}

	bool InputManager::isKeyDown(tr::Key key) {
		return s_keyStates[key];
	}

	bool InputManager::isKeyUp(tr::Key key) {
		return !s_keyStates[key];
	}

	bool InputManager::wasKeyPressed(tr::Key key) {
		return s_keyStates[key] && !s_oldKeyStates[key];
	}

	bool InputManager::wasKeyReleased(tr::Key key) {
		return !s_keyStates[key] && s_oldKeyStates[key];
	}

	bool InputManager::hasInput() {
		return !s_input.empty();
	}

	const std::string &InputManager::getInput() {
		return s_input;
	}


	std::map<tr::Key, bool> InputManager::s_keyStates {};
	std::map<tr::Key, bool> InputManager::s_oldKeyStates {};
	std::string InputManager::s_input {};
} // namespace tr
