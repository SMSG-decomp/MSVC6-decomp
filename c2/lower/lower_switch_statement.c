c2_tuple * __fastcall lower_switch_statement(c2_switch_case_range *cases,c2_tuple *anchor)

{
  uint ncases;
  c2_tuple *pcVar1;
  int saved_default_unreachable;
  
  saved_default_unreachable = g_switch_default_unreachable;
  g_switch_default_unreachable = switch_default_is_unreachable(cases);
  ncases = switch_prune_and_merge_cases(cases);
  pcVar1 = lower_switch_cases(cases->next,cases->label,ncases,anchor->dst,anchor);
  g_switch_default_unreachable = saved_default_unreachable;
  return pcVar1;
}

