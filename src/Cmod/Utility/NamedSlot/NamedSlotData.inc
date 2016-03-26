
static DataArray nameArray;
static DataArray descArray;

methodmap NamedSlotData __nullable__ < SlotData {
  public NamedSlotData() {
    nameArray = new DataArray(MAX_SLOT_NAME_LENGTH + 1);
    descArray = new DataArray(MAX_SLOT_DESC_LENGTH + 1);
    return view_as<NamedSlotData>(new SlotData());
  }

  property DataArray nameArray {
    public get() {
      return nameArray;
    }
  }

  property DataArray descArray {
    public get() {
      return descArray;
    }
  }
}
