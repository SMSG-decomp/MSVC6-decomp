c1_ovl_candidate * __fastcall ovl_operator_no_best(c1_ovl_resolution *res)

{
  ovl_set_failure_reason(res,7,0);
  ovl_report_call_failure(res,(c1_ovl_candidate *)0x0,(c1_node *)0x0);
  return (c1_ovl_candidate *)0x0;
}

