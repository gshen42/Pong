#pragma once

class InputHandler
{
public:
	~InputHandler();
	static InputHandler& getInstance();
	void update();
	int yOffset();

private:
	InputHandler();
	InputHandler(const InputHandler&) = delete;
	void operator=(const InputHandler&) = delete;
	int y_offset;
};
