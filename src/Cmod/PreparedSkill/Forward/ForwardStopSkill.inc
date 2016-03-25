methodmap ForwardStopSkill __nullable__ < ForwardBase {
  public ForwardStopSkill() {
    return as<ForwardStopSkill>(CreateForward(ET_Ignore, Param_Cell, Param_Cell, Param_Cell));
  }

  public void send(SkillID skillID, PreparedSkill preparedSkill, int entity) {
    Call_StartForward(this);
    Call_PushCell(skillID);
    Call_PushCell(preparedSkill);
    Call_PushCell(entity);
    Call_Finish();
  }
};
