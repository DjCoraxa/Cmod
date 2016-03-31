static SkillData data;

void skillCoreStart() {
  //data = new SkillData();
}

void skillCoreNative() {
  data = new SkillData();
  
  CreateNative("SkillID.SkillID", native_SkillID_SkillID);
  CreateNative("SkillID.remove", native_SkillID_remove);
  CreateNative("SkillID.isValid", native_SkillID_isValid);
  CreateNative("SkillID.setName", native_SkillID_setName);
  CreateNative("SkillID.getName", native_SkillID_getName);
  CreateNative("SkillID.setDesc", native_SkillID_setDesc);
  CreateNative("SkillID.getDesc", native_SkillID_getDesc);

  CreateNative("CmodSkill.hookCreateSkill", native_CmodSkill_hookCreateSkill)
  CreateNative("CmodSkill.unhookCreateSkill", native_CmodSkill_unhookCreateSkill)
  CreateNative("CmodSkill.hookRemoveSkill", native_CmodSkill_hookRemoveSkill)
  CreateNative("CmodSkill.unhookRemoveSkill", native_CmodSkill_unhookRemoveSkill)
  CreateNative("CmodSkill.maxNameLength.get", native_CmodSkill_maxNameLength_get);
  CreateNative("CmodSkill.maxDescLength.get", native_CmodSkill_maxDescLength_get);
  CreateNative("CmodSkill.getIDByName", native_CmodSkill_getIDByName);
}

public int native_SkillID_SkillID(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return view_as<int>(new SkillID(name));
}

public int native_SkillID_remove(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);
  skillID.remove();
}

public int native_SkillID_isValid(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);
  return skillID.isValid();
}

public int native_SkillID_setName(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(2, name, MAX_SLOT_NAME_LENGTH);

  skillID.setName(name);
}

public int native_SkillID_getName(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);

  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  skillID.getName(name, MAX_SLOT_NAME_LENGTH);

  SetNativeString(2, name, GetNativeCell(3));
}

public int native_SkillID_setDesc(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  GetNativeString(2, desc, MAX_SLOT_DESC_LENGTH);

  skillID.setDesc(desc);
}

public int native_SkillID_getDesc(Handle plugin, int numParams) {
  SkillID skillID = GetNativeCell(1);

  char[] desc = new char[MAX_SLOT_DESC_LENGTH + 1];
  skillID.getDesc(desc, MAX_SLOT_DESC_LENGTH);

  SetNativeString(2, desc, GetNativeCell(3));
}

public int native_CmodSkill_hookCreateSkill(Handle plugin, int numParams) {
  return data.fwdCreate.hook(plugin, GetNativeCell(2));
}

public int native_CmodSkill_unhookCreateSkill(Handle plugin, int numParams) {
  return data.fwdCreate.unhook(plugin, GetNativeCell(2));
}

public int native_CmodSkill_hookRemoveSkill(Handle plugin, int numParams) {
  return data.fwdRemove.hook(plugin, GetNativeCell(2));
}

public int native_CmodSkill_unhookRemoveSkill(Handle plugin, int numParams) {
  return data.fwdRemove.unhook(plugin, GetNativeCell(2));
}

public int native_CmodSkill_maxNameLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_NAME_LENGTH;
}

public int native_CmodSkill_maxDescLength_get(Handle plugin, int numParams) {
  return MAX_SLOT_DESC_LENGTH;
}

public int native_CmodSkill_getIDByName(Handle plugin, int numParams) {
  char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
  GetNativeString(1, name, MAX_SLOT_NAME_LENGTH);
  return data.nameArray.findString(name);
}
