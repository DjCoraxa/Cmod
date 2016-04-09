static SlotArray slotArray;

#if defined SLOT_CREATE_FORWARD
static ForwardCreateSlotID fwdCreate;
#endif

#if defined SLOT_REMOVE_FORWARD
static ForwardRemoveSlotID fwdRemove;
#endif

methodmap SlotData __nullable__ {
  public SlotData() {
    slotArray = new SlotArray();

#if defined SLOT_CREATE_FORWARD
    fwdCreate = new ForwardCreateSlotID();
#endif

#if defined SLOT_REMOVE_FORWARD
    fwdRemove = new ForwardRemoveSlotID();
#endif
  }

  property SlotArray slotArray {
    public get() {
      return slotArray;
    }
  }

#if defined SLOT_CREATE_FORWARD
  property ForwardCreateSlotID fwdCreate {
    public get() {
      return fwdCreate;
    }
  }
#endif

#if defined SLOT_REMOVE_FORWARD
  property ForwardRemoveSlotID fwdRemove {
    public get() {
      return fwdRemove;
    }
  }
#endif
}
