int __fastcall tuple_reads_eax_not_first(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  pcVar1 = find_src_overlapping_reg(t,g_reg_symbols + 1);
  if ((pcVar1 != (c2_operand *)0x0) && (pcVar1 != t->src)) {
    return 1;
  }
  return 0;
}

