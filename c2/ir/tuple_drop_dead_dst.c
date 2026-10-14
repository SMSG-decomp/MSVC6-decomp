int __fastcall tuple_drop_dead_dst(c2_tuple *t,c2_operand *op)

{
  ushort type;
  c2_symbol *chain;
  c2_operand *pcVar1;
  
  type = op->type;
  chain = op->sym->storage;
  if (((type & 0xfff) == chain->size) &&
     ((op == t->dst || (pcVar1 = operand_list_find_reg(t->src,op->sym), pcVar1 == (c2_operand *)0x0)
      ))) {
    symbol_free_chain(chain);
  }
  if (((op->u18).reg)->cls == '\x01') {
    pcVar1 = operand_new_hardreg(((op->u18).reg)->id,type);
    tuple_replace_dst(t,op,pcVar1);
    return 0;
  }
  tuple_remove_dst(t,op);
  return 1;
}

