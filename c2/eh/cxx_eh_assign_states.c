uint32_t __fastcall cxx_eh_assign_states(c2_function *fn,int pass)

{
  char cVar1;
  bool bVar2;
  c2_fe_symbol *pcVar3;
  c2_eh_object_cell *cell;
  uint uVar4;
  int iVar5;
  uint32_t uVar6;
  c2_eh_state *pcVar7;
  c2_eh_state *pcVar8;
  c2_eh_state *object;
  uint uVar9;
  c2_tuple *region_end;
  c2_tuple *op;
  int32_t pop_count;
  uint32_t uVar10;
  uint32_t uVar11;
  uint dropped;
  int kind4_pending;
  int kind4_unseeded;
  c2_tuple *cursor;
  c2_tuple *end;
  c2_eh_op_region *region_op;
  
  uVar10 = 0;
  dropped = 0;
  uVar11 = 0;
  kind4_pending = 0;
  kind4_unseeded = 1;
  object = (c2_eh_state *)fn;
  reset_eh_state_numbering();
  end = fn->cfg->last->end;
  op = fn->cfg->first->head->next;
  pcVar8 = g_eh_return_object_record;
  pcVar7 = object;
  if (op != end) {
    do {
      fn = (c2_function *)pcVar7;
      uVar10 = uVar11;
      cursor = op->next;
      switch(op->op) {
      case 0x16c:
        if (kind4_pending != 0) {
          kind4_pending = 0;
          iVar5 = pcVar8->walk_refs + -1;
          pcVar8->walk_refs = iVar5;
          if (iVar5 == 0) {
            uVar9 = pcVar8->flags;
            if (pass == 0) {
              if ((uVar9 & 0x800) == 0) {
                uVar10 = uVar10 | 1;
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
        break;
      case 0x184:
        if ((pass == 0) &&
           ((pcVar3 = call_target_function_symbol(op), pcVar7 = g_eh_current_state,
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
        break;
      case 0x1a0:
        object = ((op->u20).eh_construct)->object;
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
          lower_copy_pseudo(op);
          pcVar8 = g_eh_return_object_record;
        }
        break;
      case 0x1a1:
        goto switchD_10754b75_caseD_1a1;
      case 0x1a3:
        op = ((op->u20).eh_region_end)->region_begin;
switchD_10754b75_caseD_1a1:
        region_op = (op->u20).eh_region;
        pop_count = region_op->count;
        uVar9 = region_op->flags & 7;
        if (uVar9 == 2) {
          pcVar8 = (c2_eh_state *)0x0;
          uVar11 = 2;
          iVar5 = pass;
          do {
            pcVar7 = eh_pop_state();
            cVar1 = (char)pcVar7->flags;
            while (object = pcVar7, cVar1 == '\x03') {
              object->parent = pcVar8;
              pcVar7 = eh_pop_state();
              cVar1 = (char)pcVar7->flags;
              pcVar8 = object;
            }
            if (iVar5 == 0) {
              uVar6 = cxx_eh_object_needs_state(op,object);
              if (uVar6 == 0) {
                dropped = dropped | 1;
              }
              else {
                uVar10 = uVar10 | 1;
              }
            }
            else {
              cxx_eh_drop_object_state(op,object,((op->u20).eh_region)->objects);
            }
            pop_count = pop_count + -1;
          } while (0 < pop_count);
          if (pcVar8 != (c2_eh_state *)0x0) {
            uVar10 = cxx_eh_assign_states_tail
                               (pcVar8,op,object,uVar10,dropped,iVar5,kind4_pending,kind4_unseeded,
                                uVar11,cursor,end,fn);
            return uVar10;
          }
        }
        else {
          cell = cxx_eh_order_objects_by_state(region_op->objects,pop_count);
          ((op->u20).eh_region)->objects = cell;
          pcVar8 = g_eh_return_object_record;
          if (cell == (c2_eh_object_cell *)0x0) break;
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
                iVar5 = pass;
                if (cell != (c2_eh_object_cell *)0x0) {
                  pcVar8 = eh_pop_state();
                  iVar5 = pass;
                  do {
                    object = eh_pop_state();
                    object->walk_refs = object->walk_refs + -1;
                    if (pass == 0) {
                      uVar11 = cxx_eh_object_needs_state(op,object);
                      if (uVar11 == 0) {
                        dropped = dropped | 1;
                      }
                      else {
                        uVar10 = uVar10 | 1;
                      }
                    }
                    else {
                      cxx_eh_drop_object_state(op,object,cell);
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
              uVar11 = cxx_eh_object_needs_state(op,object);
              if (uVar11 == 0) {
                dropped = dropped | 1;
              }
              else {
                uVar10 = uVar10 | 1;
              }
            }
            else {
              cxx_eh_drop_object_state(op,object,cell);
            }
            cell = cell->next;
            iVar5 = pass;
          } while (cell != (c2_eh_object_cell *)0x0);
        }
LAB_10754e0d:
        pcVar8 = g_eh_return_object_record;
        pass = iVar5;
        if (((op->u20).eh_region)->count == 0) {
          if (op->op == 0x1a2) {
            region_end = op->next;
            while ((region_end->op != 0x1a3 ||
                   (((region_end->u20).eh_region_end)->region_begin != op))) {
              region_end = region_end->next;
            }
            tuple_unlink_free(region_end);
          }
          tuple_unlink_free(op);
          pcVar8 = g_eh_return_object_record;
          pass = iVar5;
        }
        break;
      case 0x1a8:
        if (pass == 0) {
          object = ((op->u20).eh_construct)->object;
          if ((object->flags & 0x800) == 0) {
            uVar10 = 1;
          }
          else {
            dropped = 1;
            object->flags = object->flags & 0xfffffbff;
          }
        }
      }
      op = cursor;
      uVar11 = uVar10;
      pcVar7 = (c2_eh_state *)fn;
    } while (op != end);
  }
  if ((pass == 0) && (dropped == 0)) {
    ((c2_eh_state *)fn)->funclet = (c2_function *)((uint)((c2_eh_state *)fn)->funclet & 0xffff7fff);
  }
  return uVar10;
}

