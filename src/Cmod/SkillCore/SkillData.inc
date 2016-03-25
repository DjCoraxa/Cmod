static DataArray fwdPrepareArray;
static DataArray fwdRunArray;

methodmap SkillData __nullable__ < NamedSlotData {
  public SkillData() {
    fwdPrepareArray = new DataArray();
    fwdRunArray = new DataArray();
    return as<SkillData>(new NamedSlotData());
  }

  property DataArray fwdPrepareArray {
    public get() {
      return fwdPrepareArray;
    }
  }

  property DataArray fwdRunArray {
    public get() {
      return fwdRunArray;
    }
  }
};
