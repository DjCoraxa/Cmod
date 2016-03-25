methodmap ForwardRemoveSlotID __nullable__ < ForwardBase {
  public ForwardRemoveSlotID() {
    return as<ForwardRemoveSlotID>(CreateForward(ET_Ignore, Param_Cell));
  }

  public void send(Slot slotID) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_Finish();
  }
}
