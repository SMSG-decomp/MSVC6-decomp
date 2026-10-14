void __fastcall switch_attach_case_targets(c2_tuple *sw,c2_switch_case_range *cases,int ncases)

{
  if ((cases != (c2_switch_case_range *)0x0) && (ncases != 0)) {
    switch_attach_case_targets(sw,cases->next,ncases + -1);
    switch_add_case(sw,cases->label,cases->last,cases->first);
  }
  return;
}

