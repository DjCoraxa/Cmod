static DataArray fwdActivateArray;

methodmap StatsData __nullable__ < NamedSlotData {
  public StatsData() {
    fwdActivateArray = new DataArray();
    return as<StatsData>(new NamedSlotData());
  }

  property DataArray fwdActivateArray {
    public get() {
      return fwdActivateArray;
    }
  }
};
