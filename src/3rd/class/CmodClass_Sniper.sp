#include <sourcemod>
#include <cmod>

CmodSkill cmodSkill;

char allowWeapons[][] = {
  "weapon_awp",
  "weapon_deagle",
  "weapon_knife"
};

const int allowWeaponsCount = 3;

char giveWeapons[][] = {
  "weapon_awp",
  "weapon_deagle"
};

const int giveWeaponsCount = 2;

ClassID sniper = ClassID_Invalid;
PreparedSkill extraDMG = PreparedSkill_Invalid;

public void OnAllPluginsLoaded() {
  sniper = new ClassID("Sniper");
  sniper.setDesc("Dmg from awp 150 + 1/4INT");
  sniper.hookEnable(onClassEnable);
  sniper.hookDisable(onClassDisable);

  cmodSkill.notifyWhenAvalible("extra_dmg", extraDMGAvalible);
}

public void OnPluginEnd() {
  if (sniper.isValid())
    sniper.remove()

  if (extraDMG.isValid())
    extraDMG.remove();
}

public void extraDMGAvalible(SkillID skillID, char[] name) {
  extraDMG = new PreparedSkill(skillID);
  extraDMG.setString("weapon", "weapon_awp", true);
  extraDMG.setFloat("dmg", 150.0, true);
  extraDMG.setString("stats", "Inteligence", true);
  extraDMG.setFloat("stats_multiply", 0.25, true);
}

public void onClassEnable(ClassID classID, int client) {
  ClientID clientID = view_as<ClientID>(client);

  for (int i = 0; i < allowWeaponsCount; ++i)
    clientID.allowWeapon(allowWeapons[i]);

  for (int i = 0; i < giveWeaponsCount; ++i)
    clientID.addWeaponToGiveList(giveWeapons[i]);

  if (extraDMG.isValid())
    extraDMG.start(client);
}

public void onClassDisable(ClassID classID, int client) {
  ClientID clientID = view_as<ClientID>(client);

  for (int i = 0; i < allowWeaponsCount; ++i)
    clientID.denyWeapon(allowWeapons[i]);

  for (int i = 0; i < giveWeaponsCount; ++i)
    clientID.removeWeaponFromGiveList(giveWeapons[i]);

  if (extraDMG.isValid())
    extraDMG.stop(client);
}
