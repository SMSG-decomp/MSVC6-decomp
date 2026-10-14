void __fastcall x87_spill_stack_entries(c2_tuple *anchor,int count,int top_offset)

{
  c2_operand *pcVar1;
  int slot;
  int iVar2;
  
  iVar2 = 0;
  if (((anchor->op == 0x60) && ((anchor->next->flags & 1) != 0)) &&
     (pcVar1 = find_src_symbol_ref(anchor->next,g_fp_lower_stack_syms[g_fp_lower_depth]),
     pcVar1 != (c2_operand *)0x0)) {
    x87_spill_one_entry(anchor,g_fp_lower_depth + -1);
    return;
  }
  slot = g_fp_lower_depth - top_offset;
  while( true ) {
    if (slot < 0) {
      return;
    }
    x87_spill_one_entry(anchor,slot);
    iVar2 = iVar2 + 1;
    if (iVar2 == count) break;
    slot = slot + -1;
  }
  return;
}

