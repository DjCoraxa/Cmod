static WeaponData data;
static WeaponMan weaponMan;

void weaponCoreStart() {
  data = new WeaponData();
  RegPluginLibrary("Cmod_WeaponCore");
}

public void OnClientConnected(int client) {
  WeaponClient weaponClient = view_as<WeaponClient>(client);
  weaponClient.clear();
}

public void OnClientPutInServer(int client) {
  WeaponClient weaponClient = view_as<WeaponClient>(client);
  weaponClient.clear();
  SDKHook(client, SDKHook_SpawnPost, onSpawn);
  SDKHook(client, SDKHook_WeaponCanUse, onWeaponCanUse);
}

public void OnClientDisconnect(int client) {
  SDKUnhook(client, SDKHook_SpawnPost, onSpawn);
  SDKUnhook(client, SDKHook_WeaponCanUse, onWeaponCanUse);
}

public void onSpawn(int entity) {
  if (!(0 < entity <= MaxClients) || !IsClientInGame(entity) || !IsPlayerAlive(entity))
    return;

  WeaponClient weaponClient = view_as<WeaponClient>(entity);
  weaponClient.giveWeapons();
}

public Action onWeaponCanUse(int client, int weapon) {
  WeaponClient weaponClient = view_as<WeaponClient>(client);
  char[] weaponName = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetEdictClassname(weapon, weaponName, MAX_WEAPON_NAME_LENGTH);
  if (weaponClient.checkWeaponPermByName(weaponName))
    return Plugin_Continue;
  return Plugin_Handled;
}

void weaponCoreNative() {
  CreateNative("ClientID.allowWeapon", native_ClientID_allowWeapon);
  CreateNative("ClientID.denyWeapon", native_ClientID_denyWeapon);
  CreateNative("ClientID.setWeaponRank", native_ClientID_setWeaponRank);
  CreateNative("ClientID.getWeaponRank", native_ClientID_getWeaponRank);
  CreateNative("ClientID.addWeaponToGiveList", native_ClientID_addWeaponToGiveList);
  CreateNative("ClientID.removeWeaponFromGiveList", native_ClientID_removeWeaponFromGiveList);
  CreateNative("ClientID.giveWeapons", native_ClientID_giveWeapons);
  CreateNative("ClientID.checkWeaponPerm", native_ClientID_checkWeaponPerm);
}

public native_ClientID_allowWeapon(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, client.getWeaponRank(weaponID) + 1);
}

public native_ClientID_denyWeapon(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, client.getWeaponRank(weaponID) - 1);
}

public native_ClientID_setWeaponRank(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, GetNativeCell(3));
}

public native_ClientID_getWeaponRank(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  return client.getWeaponRank(weaponID);
}

public native_ClientID_addWeaponToGiveList(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponGiveRank(weaponID, client.getWeaponGiveRank(weaponID) + 1);
}

public native_ClientID_removeWeaponFromGiveList(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponGiveRank(weaponID, client.getWeaponGiveRank(weaponID) - 1);
}

public native_ClientID_giveWeapons(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);
  client.giveWeapons();
}

public native_ClientID_checkWeaponPerm(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  return client.checkWeaponPerm(weaponID);
}
