methodmap ForwardPrepareSkill __nullable__ < ForwardBase {
  public ForwardPrepareSkill() {
    return as<ForwardPrepareSkill>(CreateForward(ET_Ignore, Param_Cell, Param_Cell));
  }

  public void send(SkillID skillID, int preparedSkill) {
    Call_StartForward(this);
    Call_PushCell(skillID);
    Call_PushCell(preparedSkill);
    Call_Finish();
  }
};
