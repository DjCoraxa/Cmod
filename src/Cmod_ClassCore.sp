#include <sourcemod>

#include "Cmod/ClassCore/Config"

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

#include "Cmod/ClassCore/Enum/ClassID"
#include "Cmod/ClassCore/Forward/ForwardEnableSlotID"
#include "Cmod/ClassCore/Forward/ForwardDisableSlotID"
#include "Cmod/ClassCore/ClassData"
#include "Cmod/ClassCore/ClassID"

#include "Cmod/ClassCore/Main"


public OnPluginStart() {
  classCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  classCoreNative();
  return APLRes_Success;
}
