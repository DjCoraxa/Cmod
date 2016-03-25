static DataArray preparedArray;

methodmap PreparedSkillData __nullable__ < SlotData {
  public PreparedSkillData() {
    preparedArray = new DataArray(as<int>(PreparedArray_Count));
    return as<PreparedSkillData>(new SlotData());
  }

  property DataArray preparedArray {
    public get() {
      return preparedArray;
    }
  }
};
