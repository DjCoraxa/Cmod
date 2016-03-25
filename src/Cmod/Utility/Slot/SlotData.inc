static SlotArray slotArray;
static ForwardCreateSlotID fwdCreate;
static ForwardRemoveSlotID fwdRemove;

methodmap SlotData __nullable__ {
  public SlotData() {
    slotArray = new SlotArray();
    fwdCreate = new ForwardCreateSlotID();
    fwdRemove = new ForwardRemoveSlotID();
  }

  property SlotArray slotArray {
    public get() {
      return slotArray;
    }
  }

  property ForwardCreateSlotID fwdCreate {
    public get() {
      return fwdCreate;
    }
  }

  property ForwardRemoveSlotID fwdRemove {
    public get() {
      return fwdRemove;
    }
  }
}
