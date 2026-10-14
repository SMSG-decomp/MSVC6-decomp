c2_operand * __fastcall reader_pop_operand(c2_reader_cell *cell)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_const_operand *pcVar4;
  c2_operand *op;
  c2_operand *pcVar5;
  c2_reader_cell *local_c;
  c2_tuple *local_8;
  c2_tuple *local_4;
  
  cell->flags = cell->flags & 0xdf;
  local_c = cell;
  if ((cell->flags & 4) != 0) {
    reader_extract_bitfield(cell,cell->tail->type);
    pcVar5 = reader_pop_operand(local_c);
    return pcVar5;
  }
  pcVar5 = (c2_operand *)cell->tail;
  if ((1 << (pcVar5->kind & 0x1f) & 0xffeU) == 0) {
    if (((cell->flags & 1) == 0) && ((g_reader_popping_tested_value != 0 || (pcVar5->op != 0x17d))))
    {
      op = (c2_operand *)pcVar5->tag;
      if (((op->kind == '\x06') &&
          ((pcVar2 = op->base, pcVar2 == (c2_operand *)0x0 ||
           (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))))) &&
         ((pcVar2 = op->index, pcVar2 == (c2_operand *)0x0 ||
          (((1 << (pcVar2->kind & 0x1f) & 6U) != 0 && (pcVar2->sym->def != (c2_tuple *)0x0)))))) {
        pcVar5 = reader_rematerialize_operand(op,(c2_tuple *)pcVar5,&local_8,&local_4);
        if ((((pcVar5->kind != '\x02') || (pcVar5->sym->cls != '\x03')) ||
            (pcVar5->sym->def != (c2_tuple *)0x0)) &&
           (((pcVar5->kind != '\x06' || (pcVar5->base->kind != '\x02')) ||
            ((pcVar3 = pcVar5->base->sym, pcVar3->cls != '\x03' || (pcVar3->def != (c2_tuple *)0x0))
            )))) {
          tuple_splice_after(local_c->tail,local_8);
          local_c->tail = local_4;
          return pcVar5;
        }
        tuple_splice_after(local_c->tail->prev,local_8);
        return pcVar5;
      }
      if (op->next != (c2_operand *)0x0) {
        pcVar5 = (c2_operand *)node_clone((c2_node *)op);
        pcVar5->next = (c2_operand *)0x0;
        return pcVar5;
      }
    }
    else {
      pcVar4 = operand_new_intconst(0x1004,1,0);
      reader_push(&local_c,(c2_node *)pcVar4);
      pcVar4 = operand_new_intconst(0x1004,0,0);
      reader_push(&local_c,(c2_node *)pcVar4);
      reader_read_conditional(&local_c);
      if (local_c != cell) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0x13a0);
      }
      op = reader_pop_operand(cell);
    }
    return op;
  }
  pcVar1 = (c2_tuple *)pcVar5->rank;
  pcVar5->rank = 0;
  cell->tail = pcVar1;
  cell->tail->next = (c2_tuple *)0x0;
  return pcVar5;
}

