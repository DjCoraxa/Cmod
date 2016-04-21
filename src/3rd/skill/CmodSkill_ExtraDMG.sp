#include <sourcemod>
#include <sdkhooks>
#include <cmod>

const int WEAPON_SLOT_NUMBER = 128;
const int WEAPON_NAME_LENGTH = 64;
const int STATS_NAME_LENGTH = 128;

static SkillID extraDMG;
static CmodStats cmodStats;

PreparedSkill preparedSlot[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];
char skillWeapon[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1][WEAPON_NAME_LENGTH + 1];
char statsName[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1][STATS_NAME_LENGTH + 1];
float statsMultiply[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];
float bonusDMG[MAXPLAYERS + 1][WEAPON_SLOT_NUMBER + 1];


public void OnAllPluginsLoaded() {
  // This loop is to change in future
  for (int client = 0; client < MAXPLAYERS; ++client)
    for (int i = 0; i < WEAPON_SLOT_NUMBER; ++i)
      preparedSlot[client][i] = PreparedSkill_Invalid;

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

  StatsID statsID = cmodStats.getIDByName(statsName[attacker][slot]);
  if (statsID.isValid()) {
    damage += attackerID.getStatsAllPts(statsID) * statsMultiply[attacker][slot];
  }

  damage += bonusDMG[attacker][slot];
  return Plugin_Changed;
}

public void onSkillPrepare(SkillID skillID, PreparedSkill preparedSkill) {
  preparedSkill.setString("stats", "");
  preparedSkill.setFloat("stats_multiply", 1.0);
  preparedSkill.setFloat("dmg", 0.0);
  preparedSkill.setString("weapon", "");
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
  preparedSkill.getString("stats", statsName[entity][slot], STATS_NAME_LENGTH);
  statsMultiply[entity][slot] = preparedSkill.getFloat("stats_multiply");
}

public void onSkillStop(SkillID skillID, PreparedSkill preparedSkill, int entity) {
  int slot = findSlot(entity);
  if (slot == -1)
    return

  preparedSlot[entity][slot] = PreparedSkill_Invalid;
  skillWeapon[entity][slot] = "";
}
