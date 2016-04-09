static ItemData data;
static Request request;

void itemCoreStart() {
  data = new ItemData();
  RegPluginLibrary("Cmod_ItemCore");
}

void itemCoreNative() {
  CreateNative("ItemID.ItemID", native_ItemID_ItemID);
  CreateNative("ItemID.remove", native_ItemID_remove);
  CreateNative("ItemID.isValid", native_ItemID_isValid);
  CreateNative("ItemID.setName", native_ItemID_setName);
  CreateNative("ItemID.getName", native_ItemID_getName);
  CreateNative("ItemID.setDesc", native_ItemID_setDesc);
  CreateNative("ItemID.getDesc", native_ItemID_getDesc);
  CreateNative("ItemID.hookEnable", native_ItemID_hookEnable);
  CreateNative("ItemID.unhookEnable", native_ItemID_unhookEnable);
  CreateNative("ItemID.hookDisable", native_ItemID_hookDisable);
  CreateNative("ItemID.unhookDisable", native_ItemID_unhookDisable);
  CreateNative("ItemID.sendEnable", native_ItemID_sendEnable);
  CreateNative("ItemID.sendDisable", native_ItemID_sendDisable);
  CreateNative("ItemID.hookRun", native_ItemID_hookRun);
  CreateNative("ItemID.unhookRun", native_ItemID_unhookRun);
  CreateNative("ItemID.sendRun", native_ItemID_sendRun);

  CreateNative("CmodItem.hookCreateItem", native_CmodItem_hookCreateItem)
  CreateNative("CmodItem.unhookCreateItem", native_CmodItem_unhookCreateItem)
  CreateNative("CmodItem.hookRemoveItem", native_CmodItem_hookRemoveItem)
  CreateNative("CmodItem.unhookRemoveItem", native_CmodItem_unhookRemoveItem)
  CreateNative("CmodItem.maxNameLength.get", native_CmodItem_maxNameLength_get);
  CreateNative("CmodItem.maxDescLength.get", native_CmodItem_maxDescLength_get);
  CreateNative("CmodItem.getIDByName", native_CmodItem_getIDByName);
  CreateNative("CmodItem.notifyWhenAvalible", native_CmodItem_notifyWhenAvalible);
}

public int native_ItemID_ItemID(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return view_as<int>(new ItemID(name));
}

public int native_ItemID_remove(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  itemID.remove();
}

public int native_ItemID_isValid(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.isValid();
}

public int native_ItemID_setName(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(2, name, MAX_SLOT_NAME_LENGTH);

  itemID.setName(name);
}

public int native_ItemID_getName(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  itemID.getName(name, MAX_SLOT_NAME_LENGTH);

  SetNativeString(2, name, GetNativeCell(3));
}

public int native_ItemID_setDesc(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  GetNativeString(2, desc, MAX_SLOT_DESC_LENGTH);

  itemID.setDesc(desc);
}

public int native_ItemID_getDesc(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  itemID.getDesc(desc, MAX_SLOT_DESC_LENGTH);

  SetNativeString(2, desc, GetNativeCell(3));
}

public int native_ItemID_hookEnable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdEnable.hook(plugin, GetNativeCell(2));
}

public int native_ItemID_unhookEnable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdEnable.unhook(plugin, GetNativeCell(2));
}

public int native_ItemID_hookDisable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdDisable.hook(plugin, GetNativeCell(2));
}

public int native_ItemID_unhookDisable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdDisable.unhook(plugin, GetNativeCell(2));
}

public int native_ItemID_sendEnable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  itemID.fwdEnable.send(itemID, GetNativeCell(2));
}

public int native_ItemID_sendDisable(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  itemID.fwdDisable.send(itemID, GetNativeCell(2));
}

public int native_ItemID_hookRun(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdRun.hook(plugin, GetNativeCell(2));
}

public int native_ItemID_unhookRun(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  return itemID.fwdRun.unhook(plugin, GetNativeCell(2));
}

public int native_ItemID_sendRun(Handle plugin, int numParams) {
  ItemID itemID = GetNativeCell(1);
  itemID.fwdRun.send(itemID, GetNativeCell(2));
}

public int native_CmodItem_hookCreateItem(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodItem_unhookCreateItem(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}

public int native_CmodItem_hookRemoveItem(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodItem_unhookRemoveItem(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}

public int native_CmodItem_maxNameLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_NAME_LENGTH;
}

public int native_CmodItem_maxDescLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_DESC_LENGTH;
}

public int native_CmodItem_getIDByName(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return data.nameArray.findString(name);
}

public int native_CmodItem_notifyWhenAvalible(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(2, name, MAX_SLOT_NAME_LENGTH);

  request.addToRequest(name, plugin, GetNativeCell(3));
}
