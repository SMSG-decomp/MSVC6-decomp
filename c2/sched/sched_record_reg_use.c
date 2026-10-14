void __fastcall sched_record_reg_use(c2_symbol *reg,c2_sched_node *n)

{
  sched_record_access(&g_sched_reg_use_list,reg,n);
  return;
}

