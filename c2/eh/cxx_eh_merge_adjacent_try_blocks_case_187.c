void cxx_eh_merge_adjacent_try_blocks_case_187
               (c2_tuple *list_end,c2_tuple *next,c2_tuple *t,c2_tuple *cursor,c2_tuple *region_end,
               c2_function *fn)

{
  uint32_t *puVar1;
  ushort uVar2;
  uint32_t uVar3;
  c2_tuple *pcVar4;
  c2_cxx_catch *pcVar5;
  c2_tuple *pcVar6;
  c2_eh_object_cell *pcVar7;
  c2_tuple *t_00;
  c2_tuple *pcVar8;
  c2_fe_symbol *label_sym;
  c2_operand *new_op;
  uint uVar9;
  c2_eh_object_cell *object_tail;
  c2_eh_tuple_cell *store_tail;
  c2_eh_tuple_cell *store_cell;
  c2_eh_object_cell *object_cell;
  c2_eh_op_region *region;
  c2_eh_op_region *next_region;
  c2_eh_state *object;
  c2_cxx_try_block *try_block;
  
  pcVar8 = cursor;
code_r0x10788831:
  cursor = pcVar8;
  pcVar8 = cursor;
  if (((1 << (t->src->kind & 0x1f) & 6U) != 0) && (t->src->sym->cls == '\x03')) {
    if (next != list_end) {
LAB_1078885a:
      switch(next->kind) {
      case '\f':
      case '\r':
      case '\x0e':
      case '\x0f':
      case '\x10':
      case '\x11':
      case '\x12':
      case '\x13':
      case '\x14':
      case '\x15':
        if (next->op != 0x186) break;
      case '\x1a':
        if ((next->flags & 1) != 0) {
          pcVar8 = *(c2_tuple **)((int)&next->src->sym->u30 + 2);
          tuple_unlink_free(next);
          cursor = t->next;
          next = pcVar8;
        }
        goto LAB_107888c8;
      case '\x16':
        goto switchD_1078886f_caseD_16;
      }
    }
switchD_1078886f_caseD_17:
    label_sym = label_symbol_new();
    next = tuple_new_label(label_sym);
    tuple_splice_after(t,next);
LAB_107888c8:
    label_add_ref(next,(c2_node *)t);
    new_op = operand_new_labelref(next,0);
    tuple_replace_src(t,t->src,new_op);
    pcVar8 = cursor;
  }
  goto switchD_10754a2e_caseD_188;
switchD_1078886f_caseD_16:
  if (((next->op != 0x1b5) && (next->op != 0x1b7)) || (next = next->next, next == list_end))
  goto switchD_1078886f_caseD_17;
  goto LAB_1078885a;
  do {
    t = cursor;
    pcVar8 = next;
    switch(cursor->op) {
    case 0x187:
      goto code_r0x10788831;
    case 0x1a2:
      uVar3 = next->op;
      pcVar6 = next;
      while (uVar3 != 0x1a3) {
        pcVar6 = pcVar6->next;
        uVar3 = pcVar6->op;
      }
      t_00 = pcVar6->next;
      while (pcVar8 = next, t_00 != (c2_tuple *)0x0) {
        pcVar4 = t_00->next;
        if (((t_00->flags & 1) == 0) || (t_00->op != 0x1a2)) {
          if ((t_00->kind != '\x16') ||
             ((puVar1 = &t_00->op, t_00 = pcVar4, *puVar1 != 0x1b5 && (*puVar1 != 0x1b7)))) break;
        }
        else {
          next_region = (t_00->u20).eh_region;
          region = (c2_eh_op_region *)(cursor->u20).eh_try;
          if (region->flags != next_region->flags) break;
          region->count = region->count + next_region->count;
          store_tail = region->state_stores;
          for (store_cell = region->state_stores->next; store_cell != (c2_eh_tuple_cell *)0x0;
              store_cell = store_cell->next) {
            store_tail = store_cell;
          }
          store_tail->next = next_region->state_stores;
          object_tail = region->objects;
          for (pcVar7 = region->objects->next; pcVar7 != (c2_eh_object_cell *)0x0;
              pcVar7 = pcVar7->next) {
            object_tail = pcVar7;
          }
          object_cell = next_region->objects;
          object_tail->next = object_cell;
          object_cell->prev = object_tail;
          tuple_unlink_free(pcVar6);
          uVar3 = pcVar4->op;
          while (uVar3 != 0x1a3) {
            pcVar4 = pcVar4->next;
            uVar3 = pcVar4->op;
          }
          ((pcVar4->u20).default_label)->next = cursor;
          next = pcVar4->next;
          tuple_unlink_free(t_00);
          t_00 = next;
          pcVar6 = pcVar4;
        }
      }
    default:
switchD_10754a2e_caseD_188:
      do {
        cursor = pcVar8;
        list_end = (c2_tuple *)0x0;
        object = g_eh_object_records;
        if (cursor == (c2_tuple *)0x0) {
          for (; object != (c2_eh_state *)0x0; object = object->next) {
            if ((((object->u1c).unwind_body != (c2_tuple *)0x0) &&
                (uVar9 = object->flags & 0xff, uVar9 != 6)) && (uVar9 != 7)) {
              node_list_free((c2_node *)(object->u1c).unwind_body);
              (object->u1c).unwind_body = (c2_tuple *)0x0;
            }
          }
          return;
        }
        next = cursor->next;
        pcVar8 = next;
      } while ((cursor->flags & 1) == 0);
      uVar2 = cursor->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      break;
    case 0x1a4:
      ((cursor->u20).eh_state_store)->new_state->guard_bit = 0;
      pcVar8 = next;
      break;
    case 0x1a5:
      try_block = ((cursor->u20).eh_try)->try_block;
      pcVar5 = ((cursor->u20).eh_try)->catch_rec;
      if (pcVar5 == try_block->catches) {
        pcVar8 = tuple_new_branch(0x186,'\0',(c2_node *)(try_block->end_label->u32).label_tuple,
                                  (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,cursor);
        cursor = pcVar8->next;
      }
      pcVar8 = tuple_new_label(pcVar5->label);
      tuple_insert_before(cursor,pcVar8);
      pcVar8 = next;
      break;
    case 0x1a6:
      try_block = ((cursor->u20).eh_try)->try_block;
      for (; (next != (c2_tuple *)0x0 && (next->kind == '\x1a')); next = next->next) {
      }
      tuple_unlink(cursor);
      pcVar8 = next->prev;
      pcVar6 = (try_block->end_label->u32).label_tuple;
      pcVar8->next = pcVar6;
      pcVar6->prev = pcVar8;
      cursor->prev = pcVar6;
      pcVar6->next = cursor;
      cursor->next = next;
      next->prev = cursor;
      pcVar8 = next;
      break;
    }
  } while( true );
}

