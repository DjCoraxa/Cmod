#include <sourcemod>
#include <cmod/version>
#include <sdktools>
#include <sdkhooks>

#include "Cmod/WeaponCore/Config"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"
#include "Cmod/Utility/Slot/SlotArray"

#include "Cmod/WeaponCore/WeaponData"
#include "Cmod/WeaponCore/WeaponMan"
#include "Cmod/WeaponCore/Weapon"
#include "Cmod/WeaponCore/WeaponClient"

#include "Cmod/WeaponCore/Main"

public Plugin myinfo = {
  name = "Cmod_WeaponCore",
  author = "plx211",
  description = "Base weapon mangament system",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

public void OnPluginStart() {
  weaponCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  weaponCoreNative();
  return APLRes_Success;
}
