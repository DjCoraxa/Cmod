#include <sourcemod>
#include <sdktools>

#include "Cmod/Utility/BasicMacro/view_as"

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

public void OnPluginStart() {
  weaponCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  weaponCoreNative();
  return APLRes_Success;
}
