
methodmap SkillID __nullable__ < NamedSlotID {
  public SkillID(char[] name) {
    return view_as<SkillID>(new NamedSlotID(name));
  }
};
