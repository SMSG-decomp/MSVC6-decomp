void __fastcall branch_swap_condition(c2_tuple *br)

{
  *(byte *)&br->type = g_cond_swapped_operands[(byte)br->type];
  return;
}

