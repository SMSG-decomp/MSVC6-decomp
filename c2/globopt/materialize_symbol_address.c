c2_operand * __fastcall materialize_symbol_address(c2_tuple *anchor,c2_operand *mem,uint16_t type)

{
  uint8_t *puVar1;
  c2_symbol *sym;
  uint32_t lo;
  c2_tuple *pcVar2;
  c2_operand *b;
  c2_operand *a;
  
  sym = mem->base_sym;
  a = (c2_operand *)0x0;
  b = (c2_operand *)0x0;
  if (sym != (c2_symbol *)0x0) {
    a = operand_new_symaddr(g_symbol_class_address_op[sym->cls],sym);
  }
  lo = mem->disp;
  if (lo != 0) {
    b = operand_new_intconst(type,lo,(int)lo >> 0x1f);
  }
  if (a != (c2_operand *)0x0) {
    if (b == (c2_operand *)0x0) {
      return a;
    }
    pcVar2 = tuple_new_cse_binary(0x16d,type,a,b,tuple_insert_before,anchor);
    b = pcVar2->dst;
    puVar1 = &(b->sym->u30).sizeopt.width_facts;
    *puVar1 = *puVar1 | 2;
    bitset_set(g_invariant_expr_syms,b->sym->id);
  }
  return b;
}

