void __thiscall ovl_set_failure_reason(c1_ovl_resolution *res,int reason,int argument)

{
  res->failure = reason;
  switch(reason) {
  case 4:
  case 5:
    if (res->failure_count != 0) goto switchD_10412fc5_caseD_0;
  default:
    res->failure_count = res->live;
  case 0:
  case 3:
switchD_10412fc5_caseD_0:
    if ((2 < reason) && (reason < 6)) {
      res->failure_argument = argument;
    }
    return;
  }
}

