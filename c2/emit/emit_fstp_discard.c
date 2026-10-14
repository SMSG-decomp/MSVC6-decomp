c2_tuple * __fastcall emit_fstp_discard(c2_tuple *t)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  c2_operand *dst;
  c2_tuple *pcVar2;
  c2_insert_fn *insert_fn;
  
  sym = symbol_new_temp(0x4008);
  sym->def = t;
  pcVar1 = operand_new_reg(0x149,0x4008,sym,g_reg_symbols + 0x1f);
  tuple_append_dst(t,pcVar1);
  insert_fn = tuple_insert_after;
  pcVar1 = operand_new_reg(0x149,0x4008,sym,g_reg_symbols + 0x1f);
  dst = operand_new_hardreg(0x1f,0x4008);
  pcVar2 = tuple_new(99,0x4008,dst,pcVar1,insert_fn,t);
  return pcVar2;
}

