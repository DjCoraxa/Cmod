methodmap ForwardEnableSlotID < ForwardBase {
  public ForwardEnableSlotID() {
    return view_as<ForwardEnableSlotID>(CreateForward(ET_Ignore, Param_Cell, Param_Cell));
  }

  public void send(Slot slotID, int client) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_PushCell(client);
    Call_Finish();
  }
};
