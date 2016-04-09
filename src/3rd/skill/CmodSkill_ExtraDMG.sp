#include <sourcemod>
#include <sdkhooks>
#include <cmod>

const int WEAPON_SLOT_NUMBER = 64;
const int WEAPON_NAME_LENGTH = 64;

SkillID extraDMG;

PreparedSkill preparedSlot[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];
char skillWeapon[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1][WEAPON_NAME_LENGTH + 1];
StatsID stats[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];
float statsMultiply[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];
float bonusDMG[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];


public void OnAllPluginsLoaded() {
  extraDMG = new SkillID("extra_dmg");
  extraDMG.setDesc("Increse weapon DMG");
  extraDMG.hookPrepare(onSkillPrepare);
  extraDMG.hookStart(onSkillStart);
  extraDMG.hookStop(onSkillStop);
}

public void OnClientPutInServer(int client) {
  SDKHook(client, SDKHook_OnTakeDamageAlive, onTakeDMG);
}

public Action onTakeDMG(int victim, int &attacker, int &inflictor, float &damage, int &damagetype, int &weapon, float damageForce[3], float damagePosition[3]) {
  ClientID attackerID = view_as<ClientID>(attacker);
  if (!attackerID.isValid())
    return Plugin_Continue;

  char[] weaponName = new char[WEAPON_NAME_LENGTH + 1];
//  GetEdictClassname(weapon, weaponName, WEAPON_NAME_LENGTH);
  GetClientWeapon(attacker, weaponName, WEAPON_NAME_LENGTH);

  int slot = findSlotByWeapon(attacker, weaponName);

  if (slot == -1)
    return Plugin_Continue;

  if (stats[attacker][slot].isValid()) {
    damage += attackerID.getStatsAllPts(stats[attacker][slot]) * statsMultiply[attacker][slot];
  }

  damage += bonusDMG[attacker][slot];
  return Plugin_Changed;
}

public void onSkillPrepare(SkillID skillID, PreparedSkill preparedSkill) {
  preparedSkill.setValue("stats_id", StatsID_Invalid);
  preparedSkill.setFloat("stats_multiply", 1.0);
  preparedSkill.setFloat("dmg", 0.0);
  preparedSkill.setString("weapon", "weapon_none");
}

int findSlot(int client, PreparedSkill preparedSkill = PreparedSkill_Invalid) {
  for (int i = 0; i < WEAPON_SLOT_NUMBER; ++i)
    if (preparedSlot[client][i] == preparedSkill)
      return i;
  return -1;
}

int findSlotByWeapon(int client, char[] weapon) {
  for (int i = 0; i < WEAPON_SLOT_NUMBER; ++i)
    if (StrEqual(skillWeapon[client][i], weapon))
      return i;
  return -1;
}

public void onSkillStart(SkillID skillID, PreparedSkill preparedSkill, int entity) {
  int slot = findSlot(entity);
  if (slot == -1)
    return

  preparedSkill.getString("weapon", skillWeapon[entity][slot], WEAPON_NAME_LENGTH);
  bonusDMG[entity][slot] = preparedSkill.getFloat("dmg")

  StatsID statsID = preparedSkill.getValue("stats_id");
  if (statsID.isValid()) {
    stats[entity][slot] = statsID;
    statsMultiply[entity][slot] = preparedSkill.getFloat("stats_multiply");
  }
}

public void onSkillStop(SkillID skillID, PreparedSkill preparedSkill, int entity) {
  int slot = findSlot(entity);
  if (slot == -1)
    return

  preparedSlot[entity][slot] = PreparedSkill_Invalid;
}
