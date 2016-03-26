static DataArray fwdEnableArray;
static DataArray fwdDisableArray;

methodmap ClassData __nullable__ < NamedSlotData {
  public ClassData() {
    fwdEnableArray = new DataArray();
    fwdDisableArray = new DataArray();
    return view_as<ClassData>(new NamedSlotData());
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
