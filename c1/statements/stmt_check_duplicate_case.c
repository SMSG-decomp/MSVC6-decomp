void __cdecl
stmt_check_duplicate_case
          (c1_case_record *prev,c1_case_record *next,int value_hi,c1_case_record *rec)

{
  if (value_hi == next->value_hi) {
    diag_error(0xc4);
    return;
  }
  rec->next = next;
  if (prev != (c1_case_record *)0x0) {
    prev->next = rec;
    return;
  }
  g_switch_case_stack->cases = rec;
  return;
}

