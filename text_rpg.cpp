#include <iostream>
#include <string>
using namespace std;


class Monster;

void PrintStatus(string name, int stat[])
{
    cout << "" << endl;
    cout << "=========================================" << endl;
    cout << "\n당신의 이름은" << endl;
    cout << "이름: " << name << endl;
    cout << "HP: " << stat[0] << " MP: " << stat[1] << endl;
    cout << "공격력: " << stat[2] << " 방어력: " << stat[3] << endl;
    cout << "\n=========================================" << endl;
}


class Player
{
protected:
    string name;
    string job;
    int level;
    int HP;
    int MP;
    int power;
    int defence;

    Player(string name, int level, int HP, int MP, int 공격력, int 방어력)
        : name(name), level(level), HP(HP), MP(MP), power(공격력), defence(방어력) {
    }

public:
   
    string getName() { return name; }
    string getJob() { return job; }
    int getHP() { return HP; }
    int getMP() { return MP; }
    int getPower() { return power; }
    int getDefence() { return defence; }

    void setHP(int hp) { HP = hp; }
    void setMP(int mp) { MP = mp; }
    void setPower(int power) { this->power = power; }
    void setDefence(int defence) { this->defence = defence; }

    void printPlayerStatus()
    {
        cout << "\n=============================================" << endl;
        cout << "이름:" << name << " l 직업:" << job << " l LV." << level << endl;
        cout << "HP:" << HP << " l MP:" << MP << " l 공격력:" << power << " l 방어력:" << defence << endl;
        cout << "=============================================" << endl;
    }

    
    virtual void attack(Monster* monster) = 0;
    virtual ~Player() {}
};


class Monster
{
protected:
    string name;
    int HP;
    int power;
    int defence;
    string dropItemName;
    int dropItemPrice;

public:
    Monster(string name, int HP, int power, int defence, string dropItemName, int dropItemPrice)
        : name(name), HP(HP), power(power), defence(defence),
        dropItemName(dropItemName), dropItemPrice(dropItemPrice) {
    }

    string getName() { return name; }
    int getHP() { return HP; }
    int getPower() { return power; }
    int getDefence() { return defence; }
    string getDropItemName() { return dropItemName; }
    int getDropItemPrice() { return dropItemPrice; }

    void setHP(int hp) { this->HP = hp; }

    void printMonsterStatus()
    {
        cout << "몬스터: " << name << endl;
        cout << "HP: " << HP << " 공격력: " << power << " 방어력: " << defence << endl;
        cout << "드롭 아이템: " << dropItemName << " (가격: " << dropItemPrice << ")" << endl;
    }

    
    void attack(Player* player)
    {
        int damage = power - player->getDefence();
        if (damage <= 0) damage = 1;  

        cout << name << "이(가) " << player->getName() << "을(를) 공격합니다! (데미지: " << damage << ")" << endl;

        player->setHP(player->getHP() - damage);
        if (player->getHP() < 0) player->setHP(0);
    }
};

class Warrior : public Player
{
public:
    Warrior(string name, int level, int HP, int MP, int power, int defence)
        : Player(name, level, HP, MP, power, defence)
    {
        job = "전사";
        cout << "* 전사로 전직하셨습니다 (공격력 +30)" << endl;
        this->power += 30;
    }

    void attack(Monster* monster) override
    {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;

        cout << name << "이(가) 검으로 강하게 베어버립니다! (데미지: " << damage << ")" << endl;

        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() < 0) monster->setHP(0);
    }
};

class Magician : public Player
{
public:
    Magician(string name, int level, int HP, int MP, int power, int defence)
        : Player(name, level, HP, MP, power, defence)
    {
        job = "마법사";
        cout << "* 마법사로 전직하셨습니다 (MP +30)" << endl;
        this->MP += 30;
    }

    void attack(Monster* monster) override
    {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;

        cout << name << "이(가) 강력한 파이어볼을 시전합니다! (데미지: " << damage << ")" << endl;

        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() < 0) monster->setHP(0);
    }
};

class Thief : public Player
{
public:
    Thief(string name, int level, int HP, int MP, int power, int defence)
        : Player(name, level, HP, MP, power, defence)
    {
        job = "도적";
        cout << "* 도적으로 전직하셨습니다! (방어력 +30)" << endl;
        this->defence += 30;
    }

    void attack(Monster* monster) override
    {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;

        cout << name << "이(가) 조용히 뒤에서 단검으로 찌릅니다! (데미지: " << damage << ")" << endl;

        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() < 0) monster->setHP(0);
    }
};

class Archer : public Player
{
public:
    Archer(string name, int level, int HP, int MP, int power, int defence)
        : Player(name, level, HP, MP, power, defence)
    {
        job = "궁수";
        cout << "* 궁수로 전직하셨습니다 (HP +30)" << endl;
        this->HP += 30;
    }

    void attack(Monster* monster) override
    {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;

        cout << name << "이(가) 정확하게 화살을 명중시킵니다! (데미지: " << damage << ")" << endl;

        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() < 0) monster->setHP(0);
    }
};

int main() {

    cout << "=========================================" << endl;
    cout << "              [RPG게임]                  " << endl;
    cout << "=========================================" << endl;
    string name;

    cout << "이름을 입력해주세요:  ";
    getline(cin, name);
    cout << "" << endl;

    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];
        cout << "\nHP: " << stat[0] << " MP: " << stat[1] << endl;

        if (stat[0] > 50 && stat[1] > 50) break;
        cout << "HP나 MP이 너무 적습니다. 다시 입력해주세요." << endl;
    }

    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];
        cout << "\n공격력: " << stat[2] << " 방어력: " << stat[3] << endl;

        if (stat[2] > 50 && stat[3] > 50) break;
        cout << "공격력이나 방어력이 너무 적습니다. 다시 입력해주세요." << endl;
    }

    PrintStatus(name, stat);

    int HP포션 = 5;
    int MP포션 = 5;

    cout << "\n* HP 포션 5개, MP 포션 5개가 기본으로 지급되었습니다." << endl;

    bool isGameStart = false;
    int choice = 0;

    while (!isGameStart)
    {
        cout << "\n===== 메뉴 =====" << endl;
        cout << "\n1. HP UP" << "  2. MP UP" << endl;
        cout << "\n3. 공격력 2배" << "  4. 방어력 2배" << endl;
        cout << "\n5. 현재 능력치" << "  6. 게임을 시작합니다" << endl;
        cout << "\n선택: ";

        cin >> choice;

        cout << "\n=======<< 캐릭터 강화 >>=======" << endl;

        switch (choice)
        {
        case 1:
            cout << "HP +20, HP 포션 차감됩니다." << endl;
            stat[0] += 20;
            HP포션 -= 1;
            break;

        case 2:
            cout << "MP +20, MP 포션 차감됩니다." << endl;
            stat[1] += 20;
            MP포션 -= 1;
            break;

        case 3:
            cout << "공격력이 2배로 증가합니다." << endl;
            stat[2] *= 2;
            break;

        case 4:
            cout << "방어력이 2배로 증가합니다." << endl;
            stat[3] *= 2;
            break;

        case 5:
            cout << "\n현재 능력치 출력." << endl;
            cout << "HP:" << stat[0] << " MP:" << stat[1] << endl;
            cout << "공격력:" << stat[2] << " 방어력:" << stat[3] << endl;
            cout << "남은 HP포션:" << HP포션 << " 남은 MP포션:" << MP포션 << endl;
            break;

        case 6:
            cout << "게임을 시작합니다!" << endl;
            isGameStart = true;
            break;

        default:
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            break;
        }
    }

   
    cout << "\n <전직 시스템> " << endl;
    cout << name << "님, 직업을 선택해주세요!" << endl;
    cout << "1. 전사" << " 2. 마법사" << " 3. 도적" << " 4. 궁수" << endl;
    cout << "\n선택: ";
    cin >> choice;

    Player* player = nullptr;

    switch (choice)
    {
    case 1:
        player = new Warrior(name, 1, stat[0], stat[1], stat[2], stat[3]);
        break;
    case 2:
        player = new Magician(name, 1, stat[0], stat[1], stat[2], stat[3]);
        break;
    case 3:
        player = new Thief(name, 1, stat[0], stat[1], stat[2], stat[3]);
        break;
    case 4:
        player = new Archer(name, 1, stat[0], stat[1], stat[2], stat[3]);
        break;
    default:
        cout << "잘못된 선택입니다. 기본값으로 전사가 선택됩니다." << endl;
        player = new Warrior(name, 1, stat[0], stat[1], stat[2], stat[3]);
        break;
    }

    player->printPlayerStatus();

   
    Monster slime("슬라임", 30, 20, 10, "슬라임 젤리", 50);
   

    cout << "\n===== 등장한 몬스터들 =====" << endl;
    slime.printMonsterStatus();
   

   
    Monster monster = slime;

    cout << "\n===== 전투 시작! " << player->getName() << " VS " << monster.getName() << " =====" << endl;

    while (player->getHP() > 0 && monster.getHP() > 0)
    {
        
        player->attack(&monster);
        cout << monster.getName() << " 남은 HP: " << monster.getHP() << endl;

        if (monster.getHP() <= 0) break;

        
        monster.attack(player);
        cout << player->getName() << " 남은 HP: " << player->getHP() << endl;
    }

   
    cout << "\n=============================================" << endl;
    if (player->getHP() <= 0)
    {
        cout << player->getName() << "님이 쓰러졌습니다... 패배!" << endl;
    }
    else
    {
        cout << monster.getName() << "을(를) 물리쳤습니다! 승리!" << endl;
        cout << "획득 아이템: " << monster.getDropItemName()
            << " (가치: " << monster.getDropItemPrice() << ")" << endl;
    }
    cout << "=============================================" << endl;

    delete player;

    return 0;
}