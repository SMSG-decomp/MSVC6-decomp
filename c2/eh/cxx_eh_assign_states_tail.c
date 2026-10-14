uint32_t cxx_eh_assign_states_tail
                   (c2_eh_state *chain,c2_tuple *op,c2_eh_state *object,uint32_t more_work,
                   uint32_t dropped,int pass,int kind4_pending,int kind4_unseeded,
                   uint32_t region_kind,c2_tuple *cursor,c2_tuple *end,c2_function *fn)

{
  char cVar1;
  c2_tuple *cursor_00;
  bool bVar2;
  c2_fe_symbol *pcVar3;
  c2_eh_object_cell *cell;
  uint uVar4;
  int iVar5;
  uint32_t uVar6;
  c2_eh_state *pcVar7;
  c2_eh_state *pcVar8;
  uint uVar9;
  c2_tuple *region_end;
  int32_t pop_count;
  c2_eh_op_region *region_op;
  
  do {
    pcVar8 = chain->parent;
    push_eh_state(chain);
    chain = pcVar8;
    cursor_00 = cursor;
  } while (pcVar8 != (c2_eh_state *)0x0);
LAB_10754e0d:
  cursor = cursor_00;
  pcVar8 = g_eh_return_object_record;
  cursor_00 = cursor;
  if (((op->u20).eh_region)->count == 0) {
    if (op->op == 0x1a2) {
      region_end = op->next;
      while ((region_end->op != 0x1a3 || (((region_end->u20).eh_region_end)->region_begin != op))) {
        region_end = region_end->next;
      }
      tuple_unlink_free(region_end);
    }
    tuple_unlink_free(op);
    pcVar8 = g_eh_return_object_record;
  }
switchD_10754b75_caseD_16d:
  cursor = cursor_00;
  if (cursor == end) {
    if ((pass == 0) && (dropped == 0)) {
      fn->flags = fn->flags & 0xffff7fff;
    }
    return more_work;
  }
  cursor_00 = cursor->next;
  switch(cursor->op) {
  case 0x16c:
    if (kind4_pending != 0) {
      kind4_pending = 0;
      iVar5 = pcVar8->walk_refs + -1;
      pcVar8->walk_refs = iVar5;
      if (iVar5 == 0) {
        uVar9 = pcVar8->flags;
        if (pass == 0) {
          if ((uVar9 & 0x800) == 0) {
            more_work = more_work | 1;
          }
          else {
            dropped = dropped | 1;
            pcVar8->flags = uVar9 & 0xfffffbff;
          }
        }
        else if ((uVar9 & 0x400) != 0) {
          g_eh_return_object_record = (c2_eh_state *)0x0;
          pcVar8 = (c2_eh_state *)0x0;
        }
      }
    }
  default:
    goto switchD_10754b75_caseD_16d;
  case 0x184:
    if ((pass == 0) &&
       ((pcVar3 = call_target_function_symbol(cursor), pcVar7 = g_eh_current_state,
        pcVar8 = g_eh_return_object_record, pcVar3 == (c2_fe_symbol *)0x0 ||
        ((pcVar3->attrs & 0x800) == 0)))) {
      for (; g_eh_return_object_record = pcVar8, pcVar7 != (c2_eh_state *)0x0;
          pcVar7 = pcVar7->parent) {
        pcVar7->flags = pcVar7->flags | 0x800;
        pcVar8 = g_eh_return_object_record;
      }
      object = (c2_eh_state *)0x0;
      if (pcVar8 != (c2_eh_state *)0x0) {
        pcVar8->flags = pcVar8->flags | 0x800;
      }
    }
    goto switchD_10754b75_caseD_16d;
  case 0x1a0:
    object = ((cursor->u20).eh_construct)->object;
    if ((char)object->flags == '\x04') {
      if (kind4_unseeded != 0) {
        kind4_unseeded = 0;
        object->walk_refs = object->funclet->funclet_refs;
      }
      kind4_pending = 1;
    }
    else {
      push_eh_state(object);
      object->walk_refs = object->refs;
      pcVar8 = g_eh_return_object_record;
    }
    if (pass == 0) {
      object->flags = object->flags & 0xfffff7ff | 0x400;
    }
    else if ((object->flags & 0x400) != 0) {
      lower_copy_pseudo(cursor);
      pcVar8 = g_eh_return_object_record;
    }
    goto switchD_10754b75_caseD_16d;
  case 0x1a1:
    goto switchD_10754b75_caseD_1a1;
  case 0x1a3:
    break;
  case 0x1a8:
    if (pass == 0) {
      object = ((cursor->u20).eh_construct)->object;
      if ((object->flags & 0x800) == 0) {
        more_work = 1;
      }
      else {
        dropped = 1;
        object->flags = object->flags & 0xfffffbff;
      }
    }
    goto switchD_10754b75_caseD_16d;
  }
  cursor = ((cursor->u20).eh_region_end)->region_begin;
switchD_10754b75_caseD_1a1:
  region_op = (cursor->u20).eh_region;
  pop_count = region_op->count;
  uVar9 = region_op->flags & 7;
  op = cursor;
  if (uVar9 != 2) {
    cell = cxx_eh_order_objects_by_state(region_op->objects,pop_count);
    ((cursor->u20).eh_region)->objects = cell;
    pcVar8 = g_eh_return_object_record;
    if (cell != (c2_eh_object_cell *)0x0) goto code_r0x10754d0b;
    goto switchD_10754b75_caseD_16d;
  }
  pcVar8 = (c2_eh_state *)0x0;
  do {
    pcVar7 = eh_pop_state();
    cVar1 = (char)pcVar7->flags;
    while (object = pcVar7, cVar1 == '\x03') {
      object->parent = pcVar8;
      pcVar7 = eh_pop_state();
      cVar1 = (char)pcVar7->flags;
      pcVar8 = object;
    }
    if (pass == 0) {
      uVar6 = cxx_eh_object_needs_state(cursor,object);
      if (uVar6 == 0) {
        dropped = dropped | 1;
      }
      else {
        more_work = more_work | 1;
      }
    }
    else {
      cxx_eh_drop_object_state(cursor,object,((cursor->u20).eh_region)->objects);
    }
    pop_count = pop_count + -1;
  } while (0 < pop_count);
  if (pcVar8 != (c2_eh_state *)0x0) {
    uVar6 = cxx_eh_assign_states_tail
                      (pcVar8,cursor,object,more_work,dropped,pass,kind4_pending,kind4_unseeded,2,
                       cursor_00,end,fn);
    return uVar6;
  }
  goto LAB_10754e0d;
code_r0x10754d0b:
  bVar2 = true;
  pcVar8 = object;
  do {
    while( true ) {
      while( true ) {
        object = g_eh_current_state;
        if (!bVar2) {
          object = pcVar8->parent;
        }
        if (object == (c2_eh_state *)0x0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\ehexcept.c",0x6cc);
        }
        uVar4 = object->flags & 0xff;
        pcVar8 = object;
        if (uVar4 != 6) break;
        bVar2 = false;
      }
      pcVar7 = object->origin;
      if (object->origin == (c2_eh_state *)0x0) {
        pcVar7 = object;
      }
      if (cell->object == pcVar7) break;
      if (uVar9 != uVar4) {
        if (cell != (c2_eh_object_cell *)0x0) {
          pcVar8 = eh_pop_state();
          do {
            object = eh_pop_state();
            object->walk_refs = object->walk_refs + -1;
            if (pass == 0) {
              uVar6 = cxx_eh_object_needs_state(cursor,object);
              if (uVar6 == 0) {
                dropped = dropped | 1;
              }
              else {
                more_work = more_work | 1;
              }
            }
            else {
              cxx_eh_drop_object_state(cursor,object,cell);
            }
            cell = cell->next;
          } while (cell != (c2_eh_object_cell *)0x0);
          push_eh_state(pcVar8);
        }
        goto LAB_10754e0d;
      }
      bVar2 = false;
    }
    iVar5 = object->walk_refs + -1;
    object->walk_refs = iVar5;
    if (iVar5 == 0) {
      if (bVar2) {
        eh_pop_state();
      }
      else {
        pcVar7 = eh_pop_state();
        while (pcVar7 != object) {
          pcVar7 = eh_pop_state();
        }
        bVar2 = true;
      }
    }
    else {
      bVar2 = false;
    }
    if (pass == 0) {
      uVar6 = cxx_eh_object_needs_state(cursor,object);
      if (uVar6 == 0) {
        dropped = dropped | 1;
      }
      else {
        more_work = more_work | 1;
      }
    }
    else {
      cxx_eh_drop_object_state(cursor,object,cell);
    }
    cell = cell->next;
  } while (cell != (c2_eh_object_cell *)0x0);
  goto LAB_10754e0d;
}

