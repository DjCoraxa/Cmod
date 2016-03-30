#include <sourcemod>
#include <cmod>

public void OnPluginStart() {
  RegConsoleCmd("cmodtest_allowawp", cmd_cmodtest_allowawp);
  RegConsoleCmd("cmodtest_denyawp", cmd_cmodtest_denyawp);
  RegConsoleCmd("cmodtest_addawptogive", cmd_cmodtest_addawptogive);
  RegConsoleCmd("cmodtest_removeawpfromgive", cmd_cmodtest_removeawpfromgive);
  RegConsoleCmd("cmodtest_awprank", cmd_cmodtest_awprank);
  RegConsoleCmd("cmodtest_giveweapon", cmd_cmodtest_giveweapon);
}

public Action cmd_cmodtest_allowawp(int client, int argc) {
  PrintToConsole(client, "Allow awp");
  Client cmodClient = view_as<Client>(client);
  cmodClient.allowWeapon("weapon_awp");
}

public Action cmd_cmodtest_denyawp(int client, int argc) {
  PrintToConsole(client, "Deny awp");
  Client cmodClient = view_as<Client>(client);
  cmodClient.denyWeapon("weapon_awp");
}

public Action cmd_cmodtest_addawptogive(int client, int argc) {
  PrintToConsole(client, "Add to give list awp");
  Client cmodClient = view_as<Client>(client);
  cmodClient.addWeaponToGiveList("weapon_awp");
}

public Action cmd_cmodtest_removeawpfromgive(int client, int argc) {
  PrintToConsole(client, "Remove from give list awp");
  Client cmodClient = view_as<Client>(client);
  cmodClient.removeWeaponFromGiveList("weapon_awp");
}

public Action cmd_cmodtest_awprank(int client, int argc) {
  Client cmodClient = view_as<Client>(client);
  PrintToConsole(client, "awp rank = %d", cmodClient.getWeaponRank("weapon_awp"));
}

public Action cmd_cmodtest_giveweapon(int client, int argc) {
  PrintToConsole(client, "Give weapon from give list");
  Client cmodClient = view_as<Client>(client);
  cmodClient.giveWeapons();
}
