static DataArray fwdEnableArray;
static DataArray fwdDisableArray;

methodmap ItemData __nullable__ < NamedSlotData {
  public ItemData() {
    fwdEnableArray = new DataArray();
    fwdDisableArray = new DataArray();
    return view_as<ItemData>(new NamedSlotData());
  }

  property DataArray fwdEnableArray {
    public get() {
      return fwdEnableArray;
    }
  }

  property DataArray fwdDisableArray {
    public get() {
      return fwdDisableArray;
    }
  }
};
