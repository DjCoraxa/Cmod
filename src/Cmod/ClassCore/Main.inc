static ClassData data;

void classCoreStart() {
  //data = new ClassData();
}

void classCoreNative() {
  data = new ClassData();

  CreateNative("ClassID.ClassID", native_ClassID_ClassID);
  CreateNative("ClassID.remove", native_ClassID_remove);
  CreateNative("ClassID.isValid", native_ClassID_isValid);
  CreateNative("ClassID.setName", native_ClassID_setName);
  CreateNative("ClassID.getName", native_ClassID_getName);
  CreateNative("ClassID.setDesc", native_ClassID_setDesc);
  CreateNative("ClassID.getDesc", native_ClassID_getDesc);
  CreateNative("ClassID.hookEnable", native_ClassID_hookEnable);
  CreateNative("ClassID.unhookEnable", native_ClassID_unhookEnable);
  CreateNative("ClassID.hookDisable", native_ClassID_hookDisable);
  CreateNative("ClassID.unhookDisable", native_ClassID_unhookDisable);
  CreateNative("ClassID.sendEnable", native_ClassID_sendEnable);
  CreateNative("ClassID.sendDisable", native_ClassID_sendDisable);
  CreateNative("ClassID.hookRun", native_ClassID_hookRun);
  CreateNative("ClassID.unhookRun", native_ClassID_unhookRun);
  CreateNative("ClassID.sendRun", native_ClassID_sendRun);

  CreateNative("CmodClass.hookCreateClass", native_CmodClass_hookCreateClass)
  CreateNative("CmodClass.unhookCreateClass", native_CmodClass_unhookCreateClass)
  CreateNative("CmodClass.hookRemoveClass", native_CmodClass_hookRemoveClass)
  CreateNative("CmodClass.unhookRemoveClass", native_CmodClass_unhookRemoveClass)
  CreateNative("CmodClass.maxNameLength.get", native_CmodClass_maxNameLength_get);
  CreateNative("CmodClass.maxDescLength.get", native_CmodClass_maxDescLength_get);
  CreateNative("CmodClass.getIDByName", native_CmodClass_getIDByName);
}

public int native_ClassID_ClassID(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return view_as<int>(new ClassID(name));
}

public int native_ClassID_remove(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  classID.remove();
}

public int native_ClassID_isValid(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.isValid();
}

public int native_ClassID_setName(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(2, name, MAX_SLOT_NAME_LENGTH);

  classID.setName(name);
}

public int native_ClassID_getName(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  classID.getName(name, MAX_SLOT_NAME_LENGTH);

  SetNativeString(2, name, GetNativeCell(3));
}

public int native_ClassID_setDesc(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  GetNativeString(2, desc, MAX_SLOT_DESC_LENGTH);

  classID.setDesc(desc);
}

public int native_ClassID_getDesc(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  classID.getDesc(desc, MAX_SLOT_DESC_LENGTH);

  SetNativeString(2, desc, GetNativeCell(3));
}

public int native_ClassID_hookEnable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdEnable.hook(plugin, GetNativeCell(2));
}

public int native_ClassID_unhookEnable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdEnable.unhook(plugin, GetNativeCell(2));
}

public int native_ClassID_hookDisable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdDisable.hook(plugin, GetNativeCell(2));
}

public int native_ClassID_unhookDisable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdDisable.unhook(plugin, GetNativeCell(2));
}

public int native_ClassID_sendEnable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  classID.fwdEnable.send(classID, GetNativeCell(2));
}

public int native_ClassID_sendDisable(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  classID.fwdDisable.send(classID, GetNativeCell(2));
}

public int native_ClassID_hookRun(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdRun.hook(plugin, GetNativeCell(2));
}

public int native_ClassID_unhookRun(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  return classID.fwdRun.unhook(plugin, GetNativeCell(2));
}

public int native_ClassID_sendRun(Handle plugin, int numParams) {
  ClassID classID = GetNativeCell(1);
  classID.fwdRun.send(classID, GetNativeCell(2));
}

public int native_CmodClass_hookCreateClass(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodClass_unhookCreateClass(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}

public int native_CmodClass_hookRemoveClass(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodClass_unhookRemoveClass(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}

public int native_CmodClass_maxNameLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_NAME_LENGTH;
}

public int native_CmodClass_maxDescLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_DESC_LENGTH;
}

public int native_CmodClass_getIDByName(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return data.nameArray.findString(name);
}
