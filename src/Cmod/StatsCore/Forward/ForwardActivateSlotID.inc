methodmap ForwardActivateSlotID < ForwardBase {
  public ForwardActivateSlotID() {
    return as<ForwardActivateSlotID>(CreateForward(ET_Ignore, Param_Cell, Param_Cell, Param_Cell));
  }

  public void send(Slot slotID, int client, int points) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_PushCell(client);
    Call_PushCell(points);
    Call_Finish();
  }
};
