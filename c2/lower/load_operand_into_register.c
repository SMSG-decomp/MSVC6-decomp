c2_operand * __fastcall load_operand_into_register(c2_tuple *t,c2_operand *op,c2_symbol *reg)

{
  c2_tuple *pcVar1;
  c2_operand *new_op;
  c2_operand *pcVar2;
  
  if ((reg != g_reg_symbols) && ((op->type & 0xfff) < 4)) {
    reg = reg_find_subreg(g_reg_symbols + reg->id,(op->type & 0xfff) << 3,0);
  }
  new_op = emit_load_into_register(1,t,op,reg);
  if (op->kind == '\x06') {
    pcVar2 = op->base;
    if ((((pcVar2 != (c2_operand *)0x0) && (pcVar2->kind == '\x01')) && (pcVar2->sym->cls == '\x03')
        ) && ((pcVar2->sym->def != (c2_tuple *)0x0 && (((pcVar2->u18).reg)->cls == '\x03')))) {
      pcVar2 = find_dst_reg_operand((pcVar2->u18).reg,t);
      if (pcVar2 != (c2_operand *)0x0) {
        pcVar1 = new_op->sym->def;
        pcVar2->sym->def = pcVar1;
        tuple_append_dst(pcVar1,pcVar2);
        tuple_remove_dst(t,pcVar2);
      }
    }
    pcVar2 = op->index;
    if (((pcVar2 != (c2_operand *)0x0) && (pcVar2->kind == '\x01')) &&
       ((pcVar2->sym->cls == '\x03' &&
        ((pcVar2->sym->def != (c2_tuple *)0x0 && (((pcVar2->u18).reg)->cls == '\x03')))))) {
      pcVar2 = find_dst_reg_operand((pcVar2->u18).reg,t);
      if (pcVar2 != (c2_operand *)0x0) {
        pcVar1 = new_op->sym->def;
        pcVar2->sym->def = pcVar1;
        tuple_append_dst(pcVar1,pcVar2);
        tuple_remove_dst(t,pcVar2);
      }
    }
  }
  try_substitute_operand(t,op,new_op,tuple_replace_src);
  return new_op;
}

