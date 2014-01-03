//Input.cpp

#include "Input.h"

KeyBoard::KeyBoard(){
	for(int i = 0; i < 256; i++){
		m_current[i] = false;
		m_previous[i] = false;
	}
}

bool KeyBoard::IsDown(int key) const{
	return m_current[key];
}

bool KeyBoard::IsDownOnce(int key) const{
	return m_current[key] && !m_previous[key];
}

void KeyBoard::PostUpdate(){
	for(int i = 0; i < 256; i++){
		m_previous[i] = m_current[i];
	}
}