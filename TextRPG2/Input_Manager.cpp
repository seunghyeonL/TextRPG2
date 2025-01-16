#include "Input_Manager.h"

Input_Manager::Input_Manager()
{
    memset(m_byKeyState, 0, sizeof(m_byKeyState));
    memset(m_byPrevKeyState, 0, sizeof(m_byPrevKeyState));
    memset(m_bKeyState, false, sizeof(m_bKeyState));
}

Input_Manager* Input_Manager::Create(HINSTANCE hInst, HWND hWnd)
{
    return new Input_Manager();
}

void Input_Manager::Update()
{
    memcpy(m_byPrevKeyState, m_byKeyState, sizeof(m_byKeyState));

    for (int i = 0; i < 256; ++i)
    {
        m_byKeyState[i] = GetKeyState(i);

        // 0x8000 ��Ʈ�� ���� ������ Ű�� ���� �ִٰ� �Ǵ�
        m_bKeyState[i] = (m_byKeyState[i] & 0x8000) != 0;
    }
}

bool Input_Manager::Key_Pressing(unsigned int _iKey)
{
    return (m_bKeyState[_iKey]);
}

bool Input_Manager::Key_Down(unsigned int _iKey)
{
    return (m_bKeyState[_iKey] && !(m_byPrevKeyState[_iKey] & 0x8000));
}

bool Input_Manager::Key_Up(unsigned int _iKey)
{
    return (!m_bKeyState[_iKey] && (m_byPrevKeyState[_iKey] & 0x8000));
}

bool Input_Manager::KeyPressedThisFrame()
{
    // ���� Ű ���¿��� ������ Ű�� �ϳ��� ������ true�� ��ȯ
    for (int i = 0; i < 256; ++i) 
    {
        if (m_bKeyState[i])
            return true;
    }
    return false;
}

void Input_Manager::Free()
{
    delete this;
}
