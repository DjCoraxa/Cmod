
methodmap SkillID __nullable__ < NamedSlotID {
  public SkillID(char[] name) {
    return as<SkillID>(new NamedSlotID(name));
  }
};
