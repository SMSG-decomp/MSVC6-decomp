void __fastcall reader_flush_and_fold_copy(c2_reader_cell *cell)

{
  byte bVar1;
  ushort type;
  c2_reader_cell *pcVar2;
  c2_symbol *pcVar3;
  c2_reader_cell *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *first;
  c2_node *node;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  
  bVar1 = cell->flags;
  if ((bVar1 & 1) != 0) {
    pcVar5 = (cell->u10).label;
    tuple_splice_after(cell->tail,pcVar5);
    pcVar5 = (c2_tuple *)list_last((c2_link *)pcVar5);
    cell->tail = pcVar5;
    (cell->u10).bitfield = (c2_operand *)0x0;
    cell->flags = bVar1 & 0xfe;
  }
  pcVar5 = cell->tail;
  if ((((((1 << (pcVar5->kind & 0x1f) & 6U) != 0) &&
        (pcVar3 = (pcVar5->u14).expr, pcVar3->cls == '\x03')) &&
       (pcVar5 = pcVar5->prev, pcVar5 != (c2_tuple *)0x0)) &&
      (((pcVar5->op == 0x16b && (pcVar5->dst->kind == '\x06')) &&
       ((pcVar5->dst->base->sym == pcVar3 &&
        ((pcVar7 = pcVar5->prev, pcVar7->op == 0x15b &&
         ((1 << (pcVar7->dst->kind & 0x1f) & 0x1eU) != 0)))))))) && (pcVar7->dst->sym == pcVar3)) {
    first = (c2_tuple *)node_clone((c2_node *)pcVar7->src);
    pcVar7 = pcVar7->prev;
    pcVar7->next = (c2_tuple *)0x0;
    tuple_splice_after(pcVar7,first);
    type = pcVar5->type;
    cell->tail = first;
    reader_load_value(cell,type,type & 0xfff,0);
    pcVar6 = (c2_operand *)node_clone(node);
    tuple_replace_dst(pcVar5,pcVar5->dst,pcVar6);
    node_free((c2_node *)pcVar5->prev);
    node_free((c2_node *)pcVar5->next);
    pcVar7 = (c2_tuple *)node->rank_or_prev;
    pcVar5->next = (c2_tuple *)0x0;
    tuple_splice_after(pcVar7,pcVar5);
    pcVar5->next = (c2_tuple *)0x0;
    cell->tail = pcVar5;
    node_free(node);
  }
  pcVar2 = cell->before;
  if (pcVar2 != (c2_reader_cell *)0x0) {
    for (pcVar4 = pcVar2->next; pcVar4 != (c2_reader_cell *)0x0; pcVar4 = pcVar4->next) {
      pcVar2 = pcVar4;
    }
    if (((((pcVar2 != (c2_reader_cell *)0x0) && (pcVar5 = cell->tail, cell->head->next == pcVar5))
         && (bVar1 = pcVar5->kind, (1 << (bVar1 & 0x1f) & 0xffeU) != 0)) &&
        (((bVar1 == 2 ||
          ((bVar1 == 6 && (pcVar5 = (c2_tuple *)pcVar5->switch_flags, pcVar5->kind == '\x02')))) &&
         (pcVar3 = (pcVar5->u14).expr, pcVar3 != (c2_symbol *)0x0)))) &&
       ((pcVar3->cls == '\x03' && (pcVar3->def == (c2_tuple *)0x0)))) {
      pcVar5 = pcVar2->tail;
      pcVar7 = pcVar5;
      if ((1 << (pcVar5->kind & 0x1f) & 0xffeU) != 0) {
        pcVar7 = pcVar5->prev;
      }
      if ((((pcVar7->kind == '\x0e') || (pcVar7->kind == '\x12')) &&
          (pcVar6 = pcVar7->dst, pcVar6 != (c2_operand *)0x0)) && (pcVar6->sym == pcVar3)) {
        tuple_remove_dst(pcVar7,pcVar6);
        if (pcVar7 != pcVar5) {
          tuple_unlink(pcVar5);
          node_free((c2_node *)pcVar5);
          pcVar2->tail = pcVar7;
        }
        pcVar5 = cell->tail;
        tuple_unlink(pcVar5);
        node_free((c2_node *)pcVar5);
        cell->tail = cell->head;
        reader_flush_cells_to_head(cell);
      }
    }
  }
  return;
}

