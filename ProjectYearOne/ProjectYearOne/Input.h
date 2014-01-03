//Input.h

#pragma once

class KeyBoard{
	friend class Engine;
public:
	KeyBoard();

	bool IsDown(int key) const;
	bool IsDownOnce(int key) const;

	void PostUpdate();

private:
	bool m_current[256];
	bool m_previous[256];
};