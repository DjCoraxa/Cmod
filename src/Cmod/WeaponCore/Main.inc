static WeaponData data;

void weaponCoreStart() {
  data = new WeaponData();
}

void weaponCoreNative() {
  CreateNative("Client.allowWeapon", native_Client_allowWeapon);
  CreateNative("Client.denyWeapon", native_Client_denyWeapon);
  CreateNative("Client.setWeaponRank", native_Client_setWeaponRank);
  CreateNative("Client.getWeaponRank", native_Client_getWeaponRank);
  CreateNative("Client.addWeaponToGiveList", native_Client_addWeaponToGiveList);
  CreateNative("Client.removeWeaponFromGiveList", native_Client_removeWeaponFromGiveList);
  CreateNative("Client.giveWeapons", native_Client_giveWeapons);
  CreateNative("Client.checkWeaponPerm", native_Client_checkWeaponPerm);
}

public native_Client_allowWeapon(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, client.getWeaponRank(weaponID) + 1);
}

public native_Client_denyWeapon(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, client.getWeaponRank(weaponID) - 1);
}

public native_Client_setWeaponRank(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponRank(weaponID, GetNativeCell(3));
}

public native_Client_getWeaponRank(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.getWeaponRank(weaponID);
}

public native_Client_addWeaponToGiveList(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponGiveRank(weaponID, client.getWeaponGiveRank(weaponID) + 1);
}

public native_Client_removeWeaponFromGiveList(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  client.setWeaponGiveRank(weaponID, client.getWeaponGiveRank(weaponID) - 1);
}

public native_Client_giveWeapons(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);
  client.giveWeapons();
}

public native_Client_checkWeaponPerm(Handle plugin, int numParams) {
  WeaponClient client = GetNativeCell(1);

  char[] weapon = new char[MAX_WEAPON_NAME_LENGTH + 1];
  GetNativeString(2, weapon, MAX_WEAPON_NAME_LENGTH);

  Weapon weaponID = new Weapon(weapon);

  return client.checkWeaponPerm(weaponID);
}
