#include <sourcemod>
#include <cmod/version>

#include "Cmod/SkillCore/Config"

#include "Cmod/Utility/Data/DataArray"

#include "Cmod/Utility/Forward/ForwardBase"

#include "Cmod/Utility/Slot/Enum/Slot"
#include "Cmod/Utility/Slot/Enum/SlotStatus"
#include "Cmod/Utility/Slot/Forward/ForwardCreateSlotID"
#include "Cmod/Utility/Slot/Forward/ForwardRemoveSlotID"
#include "Cmod/Utility/Slot/SlotArray"
#include "Cmod/Utility/Slot/SlotData"
#include "Cmod/Utility/Slot/SlotID"

#include "Cmod/Utility/NamedSlot/Enum/NamedSlotID"
#include "Cmod/Utility/NamedSlot/NamedSlotData"
#include "Cmod/Utility/NamedSlot/NamedSlotID"

#include "Cmod/SkillCore/Enum/SkillID"
#include "Cmod/SkillCore/SkillData"
#include "Cmod/SkillCore/SkillID"

#include "Cmod/SkillCore/Main"

public Plugin myinfo = {
  name = "Cmod_SkillCore",
  author = "plx211",
  description = "Base skill mangament system",
  version = CMOD_PLUGIN_VERSION,
  url = "https://github.com/plx211/Cmod"
};

public OnPluginStart() {
  skillCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  skillCoreNative();
  return APLRes_Success;
}
