methodmap ForwardRequestAvalible __nullable__ < ForwardBase {
  public ForwardRequestAvalible() {
    return view_as<ForwardRequestAvalible>(CreateForward(ET_Ignore, Param_Cell, Param_String));
  }

  public void send(Slot slotID, char[] name) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_PushString(name);
    Call_Finish();
  }
}
