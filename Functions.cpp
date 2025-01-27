//Where would I put the Has_Been_in_Room variable? >.< ?

class Player {
private:
int Max_Player_Health;
int Player_Health;
int Max_Player_Stamina;
int Player_Stamina;
int Player_Mana;
int Player_Mana_Regen;


}

class Spell {
private:
int Mana_Cost;
int Damage;
string Damage_Type;
public:
void Set_Variables(int cost, int dam, string type) {Mana_Cost = cost; Damage = dam; Damage_Type = type}
}
int main()
{
Spell Light_Ball;
Light_Ball.Set_Variables(3, 2, "light");

}
