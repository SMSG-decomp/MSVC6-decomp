void __fastcall lower_call_results_and_clobbers(c2_tuple *call)

{
  ushort type;
  bool bVar1;
  c2_operand *dst;
  c2_bitset *bs;
  c2_operand *pcVar2;
  c2_symbol *sym;
  c2_operand *src;
  c2_symbol *storage;
  c2_tuple *pcVar3;
  
  pcVar2 = call->dst;
  while( true ) {
    if (pcVar2 == (c2_operand *)0x0) {
      bs = bitset_new(8);
      if (g_opt_global == 0) {
        bitset_set(bs,1);
        bitset_set(bs,2);
        bitset_set(bs,3);
        bitset_set(bs,4);
        bitset_set(bs,7);
        bitset_set(bs,8);
      }
      else {
        collect_clobbered_registers((call->u20).default_label,bs);
      }
      pcVar2 = operand_new_regset(bs);
      tuple_append_dst(call,pcVar2);
      bVar1 = false;
      pcVar2 = call->dst;
      while (dst = pcVar2, dst != (c2_operand *)0x0) {
        pcVar2 = dst->next;
        if ((1 << (dst->kind & 0x1f) & 6U) != 0) {
          sym = symbol_new_temp(dst->type);
          sym->def = call;
          if (bVar1) {
            src = operand_new_reg(0x149,dst->type,sym,g_reg_symbols + 3);
            tuple_new(1,dst->type,dst,src,tuple_insert_after,call);
            bitset_clear(bs,3);
          }
          else {
            type = dst->type;
            if ((type & 0xf000) == 0x4000) {
              src = operand_new_reg(0x149,type,sym,g_reg_symbols + 0x1f);
              tuple_new(99,dst->type,dst,src,tuple_insert_after,call);
            }
            else {
              storage = reg_find_subreg(g_reg_symbols + 1,(type & 0xfff) << 3,0);
              src = operand_new_reg(0x149,dst->type,sym,storage);
              pcVar3 = tuple_new(1,dst->type,dst,src,tuple_insert_after,call);
              if (((1 << (dst->kind & 0x1f) & 6U) != 0) && (dst->sym->def != (c2_tuple *)0x0)) {
                dst->sym->def = pcVar3;
              }
              bitset_clear(bs,1);
              bVar1 = true;
            }
          }
          tuple_replace_dst(call,dst,src);
        }
      }
      return;
    }
    if (pcVar2->kind == '\n') break;
    pcVar2 = pcVar2->next;
  }
  return;
}

