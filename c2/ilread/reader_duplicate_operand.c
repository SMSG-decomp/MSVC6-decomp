c2_operand * __fastcall reader_duplicate_operand(c2_reader_cell *cell)

{
  uint16_t type;
  c2_operand *pcVar1;
  int iVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_operand *local_8;
  c2_operand *local_4;
  
  pcVar3 = (c2_operand *)cell->tail;
  pcVar6 = (c2_operand *)0x0;
  pcVar4 = pcVar3;
  if ((1 << (pcVar3->kind & 0x1f) & 0xffeU) == 0) {
    pcVar4 = (c2_operand *)pcVar3->tag;
    pcVar6 = pcVar3;
  }
  pcVar1 = pcVar4;
  if (pcVar4->kind == '\x06') {
    pcVar1 = pcVar4->base;
  }
  if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) && (pcVar1->sym->def != (c2_tuple *)0x0)) {
    pcVar4 = reader_rematerialize_operand
                       (pcVar4,(c2_tuple *)pcVar6,(c2_tuple **)&local_4,(c2_tuple **)&local_8);
    tuple_splice_after((c2_tuple *)local_8,(c2_tuple *)pcVar4);
    if (pcVar4->kind == '\x06') {
      pcVar5 = pcVar4->base->sym;
    }
    else {
      pcVar5 = pcVar4->sym;
    }
    if (pcVar5->cls == '\x03') {
      if (pcVar4->kind == '\x06') {
        pcVar5 = pcVar4->base->sym;
      }
      else {
        pcVar5 = pcVar4->sym;
      }
      if (pcVar5->def == (c2_tuple *)0x0) {
        local_8 = pcVar4;
        if ((1 << (pcVar3->kind & 0x1f) & 0xffeU) != 0) {
          cell->tail = (c2_tuple *)pcVar3->rank;
          tuple_unlink((c2_tuple *)pcVar3);
          if ((*(uint16_t *)&pcVar3->flags & 0x10) == 0) {
            node_free((c2_node *)pcVar3);
          }
        }
        tuple_splice_after(cell->tail,(c2_tuple *)local_4);
        cell->tail = (c2_tuple *)local_8;
        pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar4);
        return pcVar3;
      }
    }
    return local_4;
  }
  if (((pcVar1->kind == 2) && ((pcVar1->sym->flags7 & 1) != 0)) ||
     (iVar2 = node_has_side_effects((c2_node *)pcVar4), pcVar6 = pcVar4, iVar2 != 0)) {
    if ((1 << (pcVar3->kind & 0x1f) & 0xffeU) == 0) {
      pcVar3 = (c2_operand *)0x0;
    }
    else {
      cell->tail = (c2_tuple *)pcVar3->rank;
      tuple_unlink((c2_tuple *)pcVar3);
    }
    type = pcVar4->type;
    pcVar6 = operand_new_temp_sym(type);
    pcVar7 = tuple_new(0x15b,type,pcVar6,pcVar4,tuple_splice_after,cell->tail);
    cell->tail = pcVar7;
    if ((pcVar3 != (c2_operand *)0x0) && ((*(uint16_t *)&pcVar3->flags & 0x10) == 0)) {
      node_free((c2_node *)pcVar3);
    }
  }
  pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar6);
  return pcVar3;
}

