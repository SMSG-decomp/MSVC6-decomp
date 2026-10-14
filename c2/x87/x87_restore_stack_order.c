void __fastcall x87_restore_stack_order(c2_tuple *t)

{
  int n;
  int iVar1;
  
  iVar1 = 0;
  if (-1 < g_x87_tos) {
    do {
      if (g_x87_stack_ids[iVar1] != g_x87_saved_stack_ids[iVar1]) {
        n = x87_depth_of_value(g_x87_saved_stack_ids[iVar1]);
        x87_insert_fxch(t,n);
        x87_insert_fxch(t,g_x87_tos - iVar1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= g_x87_tos);
  }
  return;
}

