#pragma once

#include "Client_Defines.h"

class Input_Manager
{
private:
    Input_Manager(void);
    virtual ~Input_Manager(void) = default;

public:
    int8_t Get_KeyState(BYTE byKeyID) { return m_byKeyState[byKeyID]; }

    bool Key_Pressing(unsigned int _iKey);
    bool Key_Down(unsigned int _iKey);
    bool Key_Up(unsigned int _iKey);

    bool KeyPressedThisFrame();
    
public:
    void Update(void);

private:
    int8_t m_byKeyState[256] = {}; // Ű���忡 �ִ� ��� Ű���� �����ϱ� ���� 
    BYTE m_byPrevKeyState[256];   // ���� Ű ���º���
    bool m_bKeyState[256] = { false }; // Ű�� ���� ���¸� �����ϱ� ���� ����

public:
    static Input_Manager* Create(HINSTANCE hInst, HWND hWnd);
    virtual void Free(void);

};

