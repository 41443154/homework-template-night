
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Game
{
public:
    string name;
    int hp;
    int level;

    // 建構子
    Game(string n, int h, int l)
    {
        name = n;
        hp = h;
        level = l;
    }

    // 受到傷害
    void damage(int value)
    {
        hp -= value;
    }

    // 回復生命值
    void heal(int value)
    {
        hp += value;
    }

    // 升級
    void levelUp()
    {
        level++;
        hp = 100;
        cout << "角色升級成功！" << endl;
    }

    // 顯示角色資料
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Level: " << level << endl;
    }
};

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int n;
    cout << "請輸入角色人數：";
    cin >> n;

    vector<Game> players;

    for (int i = 0; i < n; i++)
    {
        string name;
        int hp, level;

        cout << "\n== 角色 " << i + 1 << " ==" << endl;

        cout << "名稱 ";
        cin >> name;

        cout << "血量 ";
        cin >> hp;

        cout << "等級 ";
        cin >> level;

        players.push_back(Game(name, hp, level));
    }

    int choice;

    while (1)
    {
        cout << "\n======= 選單 =======" << endl;
        cout << "1. 扣血" << endl;
        cout << "2. 回血" << endl;
        cout << "3. 升級" << endl;
        cout << "4. 顯示角色資料" << endl;
        cout << "5. 顯示全部角色" << endl;
        cout << "0. 結束程式" << endl;
        cout << "====================" << endl;
        cout << "請選擇：";

        if (!(cin >> choice))
            break;

        if (choice == 0)
        {
            cout << "程式結束！" << endl;
            break;
        }

        if (choice == 5)
        {
            for (int i = 0; i < players.size(); i++)
            {
                cout << "\n===== 角色 " << i + 1 << " =====" << endl;
                players[i].show();
            }
            continue;
        }

        int id;

        cout << "選擇角色編號 (1 ~ " << n << ")：";
        if (!(cin >> id))break;

        id--;

        int value;

        switch (choice)
        {
        case 1:
            cout << "輸入傷害值：";
            if (!(cin >> value))return 0;

            players[id].damage(value);
            break;

        case 2:
            cout << "輸入回血量：";
            if (!(cin >> value))return 0;

            players[id].heal(value);
            break;

        case 3:
            players[id].levelUp();
            break;

        case 4:
            break;
        }

        cout << "\n===== 角色目前狀態 =======" << endl;
        players[id].show();
    }
    return 0;
}
