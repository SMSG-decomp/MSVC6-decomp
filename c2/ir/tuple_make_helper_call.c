c2_tuple * __fastcall tuple_make_helper_call(c2_tuple *t,uint32_t op,c2_operand *fn,uint8_t flag)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *sym;
  c2_tuple *t_00;
  
  t_00 = (c2_tuple *)node_alloc('\x0e');
  bVar1 = fn->kind;
  t_00->op = op;
  t_00->flags = t_00->flags | 1;
  t_00->type = t->type;
  (t_00->u24).call.conv = flag;
  if ((1 << (bVar1 & 0x1f) & 0xffeU) != 0) {
    if ((fn->flags & 0x10) != 0) {
      fn = (c2_operand *)node_clone((c2_node *)fn);
    }
    fn->flags = fn->flags | 0x10;
  }
  t_00->src = fn;
  tuple_link_mem_subops(t_00);
  pcVar2 = t->src;
  t_00->line = g_cur_line;
  pcVar3 = t->dst;
  t_00->src->next = pcVar2;
  t_00->dst = pcVar3;
  t->src = (c2_operand *)0x0;
  t->dst = (c2_operand *)0x0;
  for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
    if (((1 << (pcVar3->kind & 0x1f) & 6U) != 0) && (sym = pcVar3->sym, sym->def != (c2_tuple *)0x0)
       ) {
      if (sym->storage->part_next == (c2_symbol *)0x0) {
        sym->def = t_00;
      }
      else {
        symbol_mark_overlapping_parts(sym,t_00);
      }
    }
  }
  tuple_replace(t,(c2_node *)t_00);
  return t_00;
}

