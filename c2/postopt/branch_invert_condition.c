void __fastcall branch_invert_condition(c2_tuple *br)

{
  *(byte *)&br->type = g_cond_inverse[(byte)br->type];
  return;
}

