#include <sourcemod>

#include "Cmod/ItemCore/Config"

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

#include "Cmod/ItemCore/Enum/ItemID"
#include "Cmod/ItemCore/Forward/ForwardEnableSlotID"
#include "Cmod/ItemCore/Forward/ForwardDisableSlotID"
#include "Cmod/ItemCore/Forward/ForwardRunSlot"
#include "Cmod/ItemCore/ItemData"
#include "Cmod/ItemCore/ItemID"

#include "Cmod/ItemCore/Main"


public OnPluginStart() {
  itemCoreStart();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  itemCoreNative();
  return APLRes_Success;
}
