methodmap ForwardRequestComplete < ForwardBase {
  public ForwardRequestComplete() {
    return CreateForward(ET_Ignore, Param_Cell);
  }

  public void send(Slot slot) {
    Call_StartForward(this);
    Call_PushCell(slot);
    Call_Finish();
  }
};
