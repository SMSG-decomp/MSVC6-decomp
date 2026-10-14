void reset_lowering_state(void)

{
  int iVar1;
  c2_symbol **slot;
  
  slot = g_fp_lower_stack_syms;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *slot = (c2_symbol *)0x0;
    slot = slot + 1;
  }
  g_fp_lower_depth = -1;
  g_double_align_bias = 0;
  return;
}

