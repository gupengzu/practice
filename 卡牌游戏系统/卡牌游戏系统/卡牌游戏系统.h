#include<iostream>
#include<string>
#include<vector>
using namespace std;

//卡的总类
class card
{
public:
};

//怪兽类
class Monster :public card
{
public:
	Monster();
	void appearOnTheStage();
	~Monster();
	void skill();
	int m_attack;
	int m_defence;
	int m_sacrifice;
};
//魔法卡类
class magic :public card
{
public:
	magic();
	~magic();
	void use();
	void cover();
};
//陷阱卡类
class trap :public card
{
public:
	trap();
	~trap();
	void use();
	void cover();
};
//双方玩家类
class player
{
public:
	//抽牌
	void drawCard();
	//放置怪兽卡
	void putMonster();
	//覆盖魔法陷阱卡
	void coverMagicAndTrap();
	//使用魔法陷阱卡
	void useMagicAndTrap();
	//跳过准备阶段，进入战斗阶段
	void skipPreparationStage();
	//使用怪兽进行战斗
	void useMonsterAttack();
	//跳过战斗阶段
	void skipAttack();
	int HP;
	vector<card> cardInHand;
};
//场地类


//各类卡牌的容器
vector<Monster> v_Monster;
vector<magic> v_magic;
vector<trap> v_trap;