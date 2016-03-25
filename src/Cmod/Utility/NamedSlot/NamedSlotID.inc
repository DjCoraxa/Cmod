static NamedSlotData data;

methodmap NamedSlotID __nullable__ < SlotID {
  public int getName(char[] buffer, int maxLength) {
    return data.nameArray.getString(as<int>(this), buffer, maxLength);
  }

  public void setName(char[] name) {
    data.nameArray.setString(as<int>(this), name);
  }

  public int getDesc(char[] buffer, int maxLength) {
    return data.descArray.getString(as<int>(this), buffer, maxLength);
  }

  public void setDesc(char[] desc) {
    data.descArray.setString(as<int>(this), desc);
  }

  public NamedSlotID(char[] name) {
    if (data.nameArray.findString(name) != -1)
      return NamedSlotID_Invalid;

    NamedSlotID slotID = as<NamedSlotID>(new SlotID());

    slotID.setName(name);
    slotID.setDesc("");

    return slotID;
  }
};
