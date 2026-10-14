void __fastcall rebind_def_to_register(c2_operand *use,c2_operand *reg,c2_symbol *old)

{
  uint8_t uVar1;
  c2_tuple *t;
  c2_symbol *sym;
  c2_operand *to;
  c2_operand *op;
  
  t = use->sym->def;
  to = find_dst_symbol_ref(t,use->sym);
  sym = (reg->u18).reg;
  uVar1 = sym->cls;
  (to->u18).reg = sym;
  if ((uVar1 == '\x03') && (sym->def == (c2_tuple *)0x0)) {
    if (sym->storage->part_next == (c2_symbol *)0x0) {
      sym->def = t;
    }
    else {
      symbol_mark_overlapping_parts(sym,t);
    }
  }
  op = operand_list_find_reg(t->src,old);
  if (op != (c2_operand *)0x0) {
    retie_register_chain(op,to);
  }
  return;
}

