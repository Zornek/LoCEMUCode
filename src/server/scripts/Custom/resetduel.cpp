#include "ScriptPCH.h"
 
class Reset_OnDuelEnd : public PlayerScript
{
    public:
        Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}
 
    void OnDuelEnd(Player *Pw, Player *Pl, DuelCompleteType type)
    {                      
                        Pw->RemoveArenaSpellCooldowns();
                        Pl->RemoveArenaSpellCooldowns();
                        Pw->SetHealth(Pw->GetMaxHealth());
                        Pw->SetPower(POWER_MANA, Pw->GetMaxPower(POWER_MANA));
                        Pl->SetHealth(Pl->GetMaxHealth());
                        Pl->SetPower(POWER_MANA, Pl->GetMaxPower(POWER_MANA));
    }
};
 
void AddSC_Reset()
{
    new Reset_OnDuelEnd;
}
