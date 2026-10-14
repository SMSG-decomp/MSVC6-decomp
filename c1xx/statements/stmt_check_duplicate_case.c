void __cdecl
stmt_check_duplicate_case(void **found,void **prev,uint value_lo,int value_hi,void **rec)

{
  if ((void *)value_hi == found[3]) {
    diag_error(0xc4,value_lo,value_hi);
    return;
  }
  *rec = found;
  if (prev != (void **)0x0) {
    *prev = rec;
    return;
  }
  g_switch_case_stack->cases = rec;
  return;
}

