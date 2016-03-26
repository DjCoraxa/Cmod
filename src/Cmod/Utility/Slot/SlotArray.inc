methodmap SlotArray __nullable__ < DataArray {
  public SlotArray(int blocksize = 1, int startsize = 0) {
    return view_as<SlotArray>(new DataArray(blocksize, startsize));
  }

  public Slot findSlot(SlotStatus slotStatus) {
    return view_as<Slot>(this.findValue(slotStatus));
  }

  public void setSlotStatus(Slot slotID, SlotStatus slotStatus) {
    this.setValue(view_as<int>(slotID), slotStatus);
  }

  public SlotStatus getSlotStatus(Slot slotID) {
    return view_as<SlotStatus>(this.getValue(view_as<int>(slotID)));
  }

  public void resize(int newSize) {
    this.resizeAndSetValue(newSize, SlotStatus_Free);
  }
}
