void __fastcall cxx_eh_merge_adjacent_try_blocks(c2_function *fn)

{
  uint32_t *puVar1;
  ushort uVar2;
  uint32_t uVar3;
  c2_tuple *pcVar4;
  c2_cxx_catch *pcVar5;
  c2_tuple *pcVar6;
  c2_eh_object_cell *pcVar7;
  c2_tuple *t;
  c2_tuple *pcVar8;
  c2_fe_symbol *label_sym;
  c2_operand *new_op;
  uint uVar9;
  c2_tuple *next_t;
  c2_eh_tuple_cell *store_cell;
  c2_eh_object_cell *object_cell;
  c2_eh_op_region *region;
  c2_eh_op_region *next_region;
  c2_eh_state *object;
  c2_eh_tuple_cell *store_tail;
  c2_eh_object_cell *object_tail;
  c2_cxx_try_block *try_block;
  
  t = fn->cfg->first->head;
  do {
    object = g_eh_object_records;
    if (t == (c2_tuple *)0x0) {
      for (; object != (c2_eh_state *)0x0; object = object->next) {
        if ((((object->u1c).unwind_body != (c2_tuple *)0x0) &&
            (uVar9 = object->flags & 0xff, uVar9 != 6)) && (uVar9 != 7)) {
          node_list_free((c2_node *)(object->u1c).unwind_body);
          (object->u1c).unwind_body = (c2_tuple *)0x0;
        }
      }
      return;
    }
    next_t = t->next;
    if ((t->flags & 1) != 0) {
      uVar2 = t->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      switch(t->op) {
      case 0x187:
        if (((1 << (t->src->kind & 0x1f) & 6U) != 0) && (t->src->sym->cls == '\x03')) {
          pcVar8 = next_t;
          if (next_t != (c2_tuple *)0x0) {
LAB_1078885a:
            switch(pcVar8->kind) {
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
              if (pcVar8->op != 0x186) break;
            case '\x1a':
              if ((pcVar8->flags & 1) != 0) {
                pcVar6 = *(c2_tuple **)((int)&pcVar8->src->sym->u30 + 2);
                tuple_unlink_free(pcVar8);
                next_t = t->next;
                pcVar8 = pcVar6;
              }
              goto LAB_107888c8;
            case '\x16':
              goto switchD_1078886f_caseD_16;
            }
          }
switchD_1078886f_caseD_17:
          label_sym = label_symbol_new();
          pcVar8 = tuple_new_label(label_sym);
          tuple_splice_after(t,pcVar8);
LAB_107888c8:
          label_add_ref(pcVar8,(c2_node *)t);
          new_op = operand_new_labelref(pcVar8,0);
          tuple_replace_src(t,t->src,new_op);
        }
        break;
      case 0x1a2:
        uVar3 = next_t->op;
        pcVar8 = next_t;
        while (uVar3 != 0x1a3) {
          pcVar8 = pcVar8->next;
          uVar3 = pcVar8->op;
        }
        pcVar6 = pcVar8->next;
        while (pcVar6 != (c2_tuple *)0x0) {
          pcVar4 = pcVar6->next;
          if (((pcVar6->flags & 1) == 0) || (pcVar6->op != 0x1a2)) {
            if ((pcVar6->kind != '\x16') ||
               ((puVar1 = &pcVar6->op, pcVar6 = pcVar4, *puVar1 != 0x1b5 && (*puVar1 != 0x1b7))))
            break;
          }
          else {
            next_region = (pcVar6->u20).eh_region;
            region = (c2_eh_op_region *)(t->u20).eh_try;
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
            tuple_unlink_free(pcVar8);
            uVar3 = pcVar4->op;
            while (uVar3 != 0x1a3) {
              pcVar4 = pcVar4->next;
              uVar3 = pcVar4->op;
            }
            ((pcVar4->u20).default_label)->next = t;
            next_t = pcVar4->next;
            tuple_unlink_free(pcVar6);
            pcVar6 = next_t;
            pcVar8 = pcVar4;
          }
        }
        break;
      case 0x1a4:
        ((t->u20).eh_state_store)->new_state->guard_bit = 0;
        break;
      case 0x1a5:
        try_block = ((t->u20).eh_try)->try_block;
        pcVar5 = ((t->u20).eh_try)->catch_rec;
        if (pcVar5 == try_block->catches) {
          t = tuple_new_branch(0x186,'\0',(c2_node *)(try_block->end_label->u32).label_tuple,
                               (c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,t);
          t = t->next;
        }
        pcVar8 = tuple_new_label(pcVar5->label);
        tuple_insert_before(t,pcVar8);
        break;
      case 0x1a6:
        try_block = ((t->u20).eh_try)->try_block;
        for (; (next_t != (c2_tuple *)0x0 && (next_t->kind == '\x1a')); next_t = next_t->next) {
        }
        tuple_unlink(t);
        pcVar8 = next_t->prev;
        pcVar6 = (try_block->end_label->u32).label_tuple;
        pcVar8->next = pcVar6;
        pcVar6->prev = pcVar8;
        t->prev = pcVar6;
        pcVar6->next = t;
        t->next = next_t;
        next_t->prev = t;
      }
    }
    t = next_t;
  } while( true );
switchD_1078886f_caseD_16:
  if (((pcVar8->op != 0x1b5) && (pcVar8->op != 0x1b7)) ||
     (pcVar8 = pcVar8->next, pcVar8 == (c2_tuple *)0x0)) goto switchD_1078886f_caseD_17;
  goto LAB_1078885a;
}

