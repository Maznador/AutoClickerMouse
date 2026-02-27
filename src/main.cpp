#include <windows.h>
#include <iostream>
#include <map>

std::map<int, std::string> button_map = {
    {VK_LBUTTON, "1. Левая кнопка мыши (лкм)"},
    {VK_RBUTTON, "2. Правая кнопка мыши (пкм)"}
};

bool keyDown(int vk)
{
    if (GetKeyState(vk) & 0x8000)
        return true;
    return false;
}

bool keyUp(int vk)
{
    if (!(GetKeyState(vk) & 0x8000))
        return true;
    return false;
}

void Clicker(int btn, int cps)
{
    DWORD down_flag = 0;
    DWORD up_flag = 0;

    if (btn == VK_LBUTTON)
    {
        down_flag = MOUSEEVENTF_LEFTDOWN;
        up_flag = MOUSEEVENTF_LEFTUP;
    }else if (btn == VK_RBUTTON)
    {
        down_flag = MOUSEEVENTF_RIGHTDOWN;
        up_flag = MOUSEEVENTF_RIGHTUP;
    }    

    while(!keyDown(VK_F4))
    {
        if(keyDown(btn))
        {
            mouse_event(up_flag, 0, 0, 0, 0);
            mouse_event(down_flag, 0, 0, 0, 0);
            Sleep(1000 / cps);

            if (keyUp(btn))
                mouse_event(up_flag, 0, 0, 0, 0);
        }
        else
            Sleep(1);
    }
}

// Для решения проблем с точностью функции Speed() сдлеть функцию округления и уведомления об этом игрока

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int click_per_second;
    int btn_choise;

    std::cout << "Выберите кнопку для автоклика: \n";

    for(const auto& pair : button_map)
        std::cout << pair.second << "\n";

    std::cout << "\nВведите номер для выбора кнопки: ";
    std::cin >> btn_choise;

    int selected_btn = VK_LBUTTON;

    switch (btn_choise)
    {
    case 1:
        selected_btn = VK_LBUTTON;
        break;
    case 2:
        selected_btn = VK_RBUTTON;
        break;
    default:
        std::cout << "Ошибка! Будет установлена кнопка по умолчанию (лкм)!\n"; 
    }

    std::cout << "Клики в секунду (не может быть больше 10 или меньше 1): ";
    std::cin >> click_per_second;

    if (click_per_second > 10)
        click_per_second = 10;

    if (click_per_second < 1)
        click_per_second = 1;

    std::cout << "Нажмите F4 чтобы остановить работу...";
    FreeConsole();
    Clicker(selected_btn, click_per_second);
    Sleep(10);
    
    return 0;
}