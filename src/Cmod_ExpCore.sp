#include <sourcemod>
#include <cmod/version>

#include "Cmod/ExpCore/Config"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/Utility/Forward/ForwardBase"

#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"

#if defined SLOT_CREATE_FORWARD
#include "Cmod/Utility/Slot/Forward/ForwardCreateSlotID"
#endif

#if defined SLOT_REMOVE_FORWARD
#include "Cmod/Utility/Slot/Forward/ForwardRemoveSlotID"
#endif

#include "Cmod/Utility/Slot/SlotArray"
#include "Cmod/Utility/Slot/SlotData"
#include "Cmod/Utility/Slot/SlotID"

#include "Cmod/ExpCore/Enum/ExpID"
#include "Cmod/ExpCore/Forward/ForwardLvlChange"
#include "Cmod/ExpCore/ExpData"
#include "Cmod/ExpCore/ExpID"

#include "Cmod/ExpCore/Main"

public Plugin myinfo = {
  name = "Cmod_ExpCore",
  author = "plx211",
  description = "Base exp mangament system",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

public OnPluginStart() {
  expCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  expCoreNative();
  return APLRes_Success;
}
