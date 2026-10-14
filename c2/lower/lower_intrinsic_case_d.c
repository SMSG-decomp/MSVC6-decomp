c2_tuple * lower_intrinsic_case_d(c2_tuple *t)

{
  c2_operand *dst;
  c2_symbol *sym;
  c2_tuple *pcVar1;
  c2_operand *pcStack00000010;
  c2_operand *pcStack00000014;
  c2_tuple *pcStack00000018;
  
  pcVar1 = t->prev;
  pcStack00000014 = pcVar1->src;
  pcStack00000010 = operand_new_temp(0x1001);
  pcStack00000018 = emit_sign_extend_high(0x1001,pcVar1,pcStack00000010,&stack0x00000014);
  pcVar1 = tuple_new_binary_temp
                     (0x34,0x1001,pcStack00000014,pcStack00000010,tuple_insert_after,pcStack00000018
                     );
  pcStack00000010 = bind_value_to_new_temp(pcVar1,pcStack00000010->sym,1);
  dst = t->dst;
  pcVar1 = tuple_new_binary(0x32,0x1001,dst,pcVar1->dst,pcStack00000010,tuple_insert_after,pcVar1);
  if (((1 << (dst->kind & 0x1f) & 6U) != 0) && (sym = dst->sym, sym->def != (c2_tuple *)0x0)) {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = pcVar1;
    }
    else {
      symbol_mark_overlapping_parts(sym,pcVar1);
    }
  }
  (dst->u18).reg = g_reg_symbols + 1;
  tuple_free_src_defs(t);
  t->op = 0x145;
  return pcStack00000018;
}

