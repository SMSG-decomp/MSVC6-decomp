int __fastcall
switch_narrow_int64_selector_thunk
          (c2_switch_case_range *cases,c2_tuple *selector_copy,int ncases,c2_tuple *default_label)

{
  int iVar1;
  
  iVar1 = switch_narrow_int64_selector(cases,selector_copy,ncases,default_label);
  return iVar1;
}

