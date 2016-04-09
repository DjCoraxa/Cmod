static NamedSlotData data;
static Request request;

methodmap NamedSlotID __nullable__ < SlotID {
  public int getName(char[] buffer, int maxLength) {
    return data.nameArray.getString(view_as<int>(this), buffer, maxLength);
  }

  public void setName(char[] name) {
    data.nameArray.setString(view_as<int>(this), name);
  }

  public int getDesc(char[] buffer, int maxLength) {
    return data.descArray.getString(view_as<int>(this), buffer, maxLength);
  }

  public void setDesc(char[] desc) {
    data.descArray.setString(view_as<int>(this), desc);
  }

  public NamedSlotID(char[] name) {
    if (data.nameArray.findString(name) != -1)
      return NamedSlotID_Invalid;

    NamedSlotID slotID = view_as<NamedSlotID>(new SlotID());

    slotID.setName(name);
    slotID.setDesc("");

#if defined NAMEDSLOT_CREATE_FORWARD
    data.fwdCreate.send(slotID, name);
#endif

    request.onNamedSlotCreate(slotID, name);

    return slotID;
  }

  public void remove() {
    SlotID slot = this;
    slot.remove();

#if defined NAMEDSLOT_REMOVE_FORWARD
    char[] name = new char[MAX_SLOT_NAME_LENGTH + 1];
    this.getName(name, MAX_SLOT_NAME_LENGTH);
    data.fwdRemove.send(this, name);
#endif
  }
};
