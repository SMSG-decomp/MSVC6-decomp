void __fastcall
switch_choose_split(c2_switch_case_range *cases,int values_covered,int ncases,uint32_t span_low,
                   int32_t span_high,c2_switch_case_range **split_node,int *split_count)

{
  int iVar1;
  c2_switch_case_range *pcVar2;
  
  iVar1 = switch_find_dense_prefix(cases,ncases,values_covered,span_low,span_high);
  *split_count = iVar1 + -1;
  if (iVar1 + -1 == ncases) {
    *split_count = ncases / 2;
  }
  pcVar2 = (c2_switch_case_range *)list_nth((c2_link *)cases,*split_count);
  *split_node = pcVar2;
  return;
}

