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
    if (!(Slot_Invalid < this < as<SlotID>(data.slotArray.length)))
      return false;

    if (this.status == SlotStatus_Free)
      return false;

    return true;
  }

  public SlotID() {
    SlotID slotID = as<SlotID>(data.slotArray.findSlot(SlotStatus_Free));

    if (slotID == Slot_Invalid) {
      data.slotArray.resize(data.slotArray.length + RESIZE_BACKUP);
      slotID = as<SlotID>(data.slotArray.findSlot(SlotStatus_Free));
    }

    slotID.status = SlotStatus_Use;

    data.fwdCreate.send(slotID);

    return slotID;
  }

  public void remove() {
    this.status = SlotStatus_Free;

    data.fwdRemove.send(this);
  }
}
