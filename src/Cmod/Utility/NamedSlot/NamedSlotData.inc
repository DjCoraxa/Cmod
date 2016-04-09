static DataArray nameArray;
static DataArray descArray;

#if defined NAMEDSLOT_CREATE_FORWARD
static ForwardCreateNamedSlot fwdCreate;
#endif

#if defined NAMEDSLOT_REMOVE_FORWARD
static ForwardRemoveNamedSlot fwdRemove;
#endif

methodmap NamedSlotData __nullable__ < SlotData {
  public NamedSlotData() {
    nameArray = new DataArray(MAX_SLOT_NAME_LENGTH + 1);
    descArray = new DataArray(MAX_SLOT_DESC_LENGTH + 1);

#if defined NAMEDSLOT_CREATE_FORWARD
    fwdCreate = new ForwardCreateNamedSlot();
#endif

#if defined NAMEDSLOT_REMOVE_FORWARD
    fwdRemove = new ForwardRemoveNamedSlot();
#endif

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

  #if defined NAMEDSLOT_CREATE_FORWARD
    property ForwardCreateNamedSlot fwdCreate {
      public get() {
        return fwdCreate;
      }
    }
  #endif

  #if defined NAMEDSLOT_REMOVE_FORWARD
    property ForwardRemoveNamedSlot fwdRemove {
      public get() {
        return fwdRemove;
      }
    }
  #endif
}
