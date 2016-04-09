static SlotData data;

methodmap SlotID __nullable__ < Slot {
  property SlotStatus status {
    public get() {
      return data.slotArray.getSlotStatus(this);
    }

    public set(SlotStatus status) {
      data.slotArray.setSlotStatus(this, status);
    }
  }

  public bool isValid() {
    if (!(Slot_Invalid < this < view_as<SlotID>(data.slotArray.length)))
      return false;

    if (this.status == SlotStatus_Free)
      return false;

    return true;
  }

  public SlotID() {
    SlotID slotID = view_as<SlotID>(data.slotArray.findSlot(SlotStatus_Free));

    if (slotID == Slot_Invalid) {
      data.slotArray.resize(data.slotArray.length + RESIZE_BACKUP);
      slotID = view_as<SlotID>(data.slotArray.findSlot(SlotStatus_Free));
    }

    slotID.status = SlotStatus_Use;

#if defined SLOT_CREATE_FORWARD
    data.fwdCreate.send(slotID);
#endif

    return slotID;
  }

  public void remove() {
    this.status = SlotStatus_Free;

#if defined SLOT_REMOVE_FORWARD
    data.fwdRemove.send(this);
#endif
  }
}
