static NamedSlotData data;

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

    return slotID;
  }
};
