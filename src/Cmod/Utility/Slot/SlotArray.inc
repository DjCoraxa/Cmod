methodmap SlotArray __nullable__ < DataArray {
  public SlotArray(int blocksize = 1, int startsize = 0) {
    return as<SlotArray>(new DataArray(blocksize, startsize));
  }

  public Slot findSlot(SlotStatus slotStatus) {
    return as<Slot>(this.findValue(slotStatus));
  }

  public void setSlotStatus(Slot slotID, SlotStatus slotStatus) {
    this.setValue(as<int>(slotID), slotStatus);
  }

  public SlotStatus getSlotStatus(Slot slotID) {
    return as<SlotStatus>(this.getValue(as<int>(slotID)));
  }

  public void resize(int newSize) {
    this.resizeAndSetValue(newSize, SlotStatus_Free);
  }
}
