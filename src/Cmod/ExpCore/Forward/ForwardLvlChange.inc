methodmap ForwardLvlChange __nullable__ < ForwardBase {
  public ForwardLvlChange() {
    return view_as<ForwardLvlChange>(CreateForward(ET_Ignore, Param_Cell, Param_Cell, Param_Cell));
  }

  public void send(SlotID expID, int oldLvl, int newLvl) {
    Call_StartForward(this);
    Call_PushCell(expID);
    Call_PushCell(oldLvl);
    Call_PushCell(newLvl);
    Call_Finish();
  }
}
