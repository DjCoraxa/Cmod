methodmap ForwardCreateSlotID __nullable__ < ForwardBase {
  public ForwardCreateSlotID() {
    return as<ForwardCreateSlotID>(CreateForward(ET_Ignore, Param_Cell));
  }

  public void send(Slot slotID) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_Finish();
  }
}
