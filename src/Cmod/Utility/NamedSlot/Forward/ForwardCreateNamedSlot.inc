methodmap ForwardCreateNamedSlot __nullable__ < ForwardBase {
  public ForwardCreateNamedSlot() {
    return view_as<ForwardCreateNamedSlot>(CreateForward(ET_Ignore, Param_Cell));
  }

  public void send(Slot slotID, char[] name) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_PushString(name);
    Call_Finish();
  }
}
