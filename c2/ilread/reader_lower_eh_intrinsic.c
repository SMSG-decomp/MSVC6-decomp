c2_tuple * __fastcall reader_lower_eh_intrinsic(c2_function *fn,c2_tuple *t)

{
  uint16_t uVar1;
  c2_operand *op;
  c2_operand *new_op;
  c2_operand *pcVar2;
  c2_symbol *chain;
  c2_tuple *t_00;
  c2_symbol *pcVar3;
  c2_eh_alloca_marker *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *scan_def;
  c2_tuple *scan;
  
  if ((t->type & 0xf000) != 0x4000) {
    uVar1 = (t->u20).intrinsic.id;
    if (uVar1 == 0xa8) {
      operand_retype(t->dst,0x1001,0);
      t->type = 0x1001;
    }
    else if (uVar1 == 0xdf) {
      op = t->src->next;
      new_op = op->sym->def->src;
      pcVar5 = new_op->sym->def;
      pcVar4 = arena_alloc(1,0xc);
      pcVar4->addr_def = pcVar5;
      pcVar4->next = g_eh_alloca_markers;
      pcVar4->intrinsic = t;
      pcVar2 = pcVar5->src->next;
      chain = pcVar2->sym;
      t_00 = chain->def;
      pcVar3 = t_00->src->sym;
      g_eh_alloca_markers = pcVar4;
      if ((fn->flags & 0x8000) == 0) {
        tuple_unlink_free(t_00);
        symbol_free_chain(chain);
        tuple_remove_src(pcVar5,pcVar2);
      }
      pcVar5 = t->src->sym->def->src->sym->def;
      if (pcVar5->op == 0x1a0) {
        pcVar5 = pcVar5->src->sym->def;
      }
      pcVar2 = pcVar5->src->next;
      scan = (c2_tuple *)pcVar3;
      while ((scan_def = scan, pcVar2 != (c2_operand *)0x0 &&
             (((((1 << (pcVar2->kind & 0x1f) & 6U) == 0 ||
                (scan_def = pcVar2->sym->def, scan_def == (c2_tuple *)0x0)) ||
               ((scan = scan_def, scan_def->op != 0x15a && (scan_def->op != 0x16a)))) ||
              ((scan_def->src->kind != '\x02' || (scan_def->src->sym != pcVar3))))))) {
        pcVar2 = pcVar2->next;
      }
      tuple_replace_src(scan_def,scan_def->src,new_op);
      tuple_unlink_free(op->sym->def);
      symbol_free_chain(op->sym);
      tuple_remove_src(t,op);
      pcVar5 = t->src->next->sym->def;
      tuple_unlink(pcVar5);
      tuple_insert_before(t,pcVar5);
      return t;
    }
  }
  return t;
}

