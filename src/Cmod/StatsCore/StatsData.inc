static DataArray fwdActivateArray;

methodmap StatsData __nullable__ < NamedSlotData {
  public StatsData() {
    fwdActivateArray = new DataArray();
    return view_as<StatsData>(new NamedSlotData());
  }

  property DataArray fwdActivateArray {
    public get() {
      return fwdActivateArray;
    }
  }
};
