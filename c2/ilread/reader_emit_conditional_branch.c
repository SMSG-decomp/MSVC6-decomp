void __fastcall
reader_emit_conditional_branch(c2_reader_cell **stack,c2_tuple *label,c2_reader_op *rec)

{
  c2_reader_cell *pcVar1;
  c2_symbol *pcVar2;
  c2_operand *target;
  c2_tuple *first;
  byte bVar3;
  byte bVar4;
  c2_operand *cond;
  c2_tuple *pcVar5;
  c2_tuple *first_00;
  c2_fe_symbol *pcVar6;
  
  pcVar1 = *stack;
  if ((pcVar1->flags & 1) == 0) {
    bVar3 = reader_test_value(stack);
    pcVar1 = *stack;
    g_reader_popping_tested_value = 1;
    cond = reader_pop_operand(pcVar1);
    g_reader_popping_tested_value = 0;
    if (label == (c2_tuple *)0x0) {
      pcVar6 = label_symbol_new_in_scope(g_reading_function);
      pcVar5 = tuple_new_label(pcVar6);
      (pcVar1->u10).label = pcVar5;
    }
    else {
      (pcVar1->u10).label = label;
    }
    if (pcVar1->before != (c2_reader_cell *)0x0) {
      reader_flush_cells_to_head(pcVar1);
    }
    if (pcVar1->after != (c2_reader_cell *)0x0) {
      reader_flush_all_cells(pcVar1);
    }
    if (rec->op == 0x1b) {
      bVar3 = g_cond_inverse[bVar3];
      bVar4 = pcVar1->flags | 2;
    }
    else {
      bVar4 = pcVar1->flags & 0xfd;
    }
    pcVar2 = cond->sym;
    pcVar1->flags = bVar4;
    pcVar5 = pcVar1->tail;
    target = (pcVar1->u10).bitfield;
    cond->flags11 = cond->flags11 & 0xf;
    pcVar5 = tuple_new_branch(0x185,bVar3,(c2_node *)target,cond,pcVar2->def,tuple_splice_after,
                              pcVar5);
    pcVar1->tail = pcVar5;
    pcVar1->flags = pcVar1->flags | 1;
  }
  else {
    bVar3 = pcVar1->flags & 2;
    if (((bVar3 == 0) && (rec->op == 0x1b)) || ((bVar3 != 0 && (rec->op == 0x1c)))) {
      pcVar5 = pcVar1->tail;
      if (pcVar5->kind == '\x11') {
        first_00 = label;
        if (label == (c2_tuple *)0x0) {
          pcVar6 = label_symbol_new_in_scope(g_reading_function);
          first_00 = tuple_new_label(pcVar6);
        }
      }
      else {
        do {
          pcVar5 = pcVar5->prev;
        } while (pcVar5->kind == '\x1a');
        first_00 = pcVar5->next;
        pcVar5->next = (c2_tuple *)0x0;
        first_00->prev = (c2_tuple *)0x0;
        if (label != (c2_tuple *)0x0) {
          tuple_splice_after(label,first_00);
          first_00 = label;
        }
      }
      if ((pcVar5->op != 0x185) || (pcVar1->after != (c2_reader_cell *)0x0)) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\reader.c",0xf7a);
      }
      *(byte *)&pcVar5->type = g_cond_inverse[(byte)pcVar5->type];
      tuple_retarget(pcVar5,(c2_node *)first_00,0);
      first = (pcVar1->u10).label;
      tuple_splice_after(pcVar5,first);
      pcVar5 = (c2_tuple *)list_last((c2_link *)first);
      pcVar1->tail = pcVar5;
      (pcVar1->u10).label = first_00;
      pcVar1->flags = pcVar1->flags ^ 2;
    }
    if (pcVar1->before != (c2_reader_cell *)0x0) {
      reader_flush_cells_to_head(pcVar1);
      return;
    }
  }
  return;
}

