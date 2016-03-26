static DataArray preparedArray;

methodmap PreparedSkillData __nullable__ < SlotData {
  public PreparedSkillData() {
    preparedArray = new DataArray(view_as<int>(PreparedArray_Count));
    return view_as<PreparedSkillData>(new SlotData());
  }

  property DataArray preparedArray {
    public get() {
      return preparedArray;
    }
  }
};
