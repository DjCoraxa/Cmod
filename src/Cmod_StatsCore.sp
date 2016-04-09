#include <sourcemod>
#include <cmod/version>

#include "Cmod/StatsCore/Config"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/Utility/Forward/ForwardBase"

#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"
#include "Cmod/Utility/Slot/SlotArray"
#include "Cmod/Utility/Slot/SlotData"
#include "Cmod/Utility/Slot/SlotID"

#include "Cmod/Utility/NamedSlot/Forward/ForwardCreateNamedSlot"
#include "Cmod/Utility/NamedSlot/Forward/ForwardRemoveNamedSlot"
#include "Cmod/Utility/NamedSlot/Enum/NamedSlotID"
#include "Cmod/Utility/NamedSlot/NamedSlotData"
#include "Cmod/Utility/NamedSlot/NamedSlotID"

#include "Cmod/StatsCore/Enum/StatsID"
#include "Cmod/StatsCore/Forward/ForwardActivateSlotID"
#include "Cmod/StatsCore/StatsData"
#include "Cmod/StatsCore/StatsID"

#include "Cmod/StatsCore/Main"

public Plugin myinfo = {
  name = "Cmod_StatsCore",
  author = "plx211",
  description = "Base stats mangament system",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

public OnPluginStart() {
  statsCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  statsCoreNative();
  return APLRes_Success;
}
