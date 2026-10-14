c2_tuple * __fastcall cxx_eh_lower_try_end(c2_tuple *region_begin)

{
  c2_tuple *pcVar1;
  int32_t old_state;
  bool bVar2;
  c2_eh_object_cell *pcVar3;
  uint32_t object_kind;
  int iVar4;
  c2_tuple *pcVar5;
  c2_eh_state *pcVar6;
  c2_eh_state *pcVar7;
  c2_eh_state *pcVar8;
  c2_eh_op_construct *pcVar9;
  uint32_t kind;
  c2_eh_tuple_cell *store_cell;
  c2_eh_object_cell *list;
  c2_eh_tuple_cell *local_10;
  c2_eh_op_region *region;
  c2_tuple *region_end;
  
  region = (region_begin->u20).eh_region;
  store_cell = region->state_stores;
  kind = region->flags & 7;
  pcVar3 = cxx_eh_order_objects_by_state(region->objects,region->count);
  region_end = region_begin;
  while ((region_end != (c2_tuple *)0x0 &&
         ((region_end->op != 0x1a3 ||
          (((region_end->u20).eh_region_end)->region_begin != region_begin))))) {
    region_end = region_end->next;
  }
  pcVar1 = region_begin->prev;
  tuple_unlink_free(region_begin);
  if (pcVar3 == (c2_eh_object_cell *)0x0) {
    ((region_end->u20).eh_construct)->object = g_eh_current_state;
    return pcVar1->next;
  }
  bVar2 = true;
  pcVar7 = (c2_eh_state *)kind;
  local_10 = store_cell;
  do {
    while( true ) {
      while( true ) {
        pcVar8 = g_eh_current_state;
        if (!bVar2) {
          pcVar8 = pcVar7->parent;
        }
        if (pcVar8 == (c2_eh_state *)0x0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\ehexcept.c",0x9bf);
        }
        object_kind = pcVar8->flags & 0xff;
        pcVar7 = pcVar8;
        if (object_kind != 6) break;
        bVar2 = false;
      }
      pcVar6 = pcVar8->origin;
      if (pcVar8->origin == (c2_eh_state *)0x0) {
        pcVar6 = pcVar8;
      }
      if (pcVar3->object == pcVar6) break;
      if (kind != object_kind) {
        pcVar7 = eh_pop_state();
        list = (c2_eh_object_cell *)0x0;
        old_state = pcVar7->state;
        do {
          pcVar8 = eh_pop_state();
          pcVar8->refs = pcVar8->refs + -1;
          pcVar3 = pcVar3->next;
          list = list_append_new(list,pcVar8);
        } while (pcVar3 != (c2_eh_object_cell *)0x0);
        pcVar7 = cxx_eh_clone_object_record(pcVar7);
        pcVar5 = tuple_new_pseudo(0x1a0,0x1004);
        pcVar9 = arena_alloc(1,0x10);
        (pcVar5->u20).eh_construct = pcVar9;
        pcVar9->object = pcVar7;
        tuple_insert_after(store_cell->tuple->prev,pcVar5);
        push_eh_state(pcVar7);
        iVar4 = 0;
        pcVar3 = list->next;
        pcVar7 = g_eh_current_state;
        while (g_eh_current_state = pcVar7, pcVar3 != (c2_eh_object_cell *)0x0) {
          pcVar7 = cxx_eh_clone_object_record(list->object);
          pcVar5 = tuple_new_pseudo(0x1a0,0x1004);
          pcVar9 = arena_alloc(1,0x10);
          (pcVar5->u20).eh_construct = pcVar9;
          pcVar9->object = pcVar7;
          tuple_insert_after(local_10->tuple->prev,pcVar5);
          push_eh_state(pcVar7);
          list = list->next;
          iVar4 = iVar4 + 1;
          store_cell = local_10;
          pcVar7 = g_eh_current_state;
          pcVar3 = list->next;
        }
        pcVar5 = store_cell->tuple->prev;
        tuple_unlink_free(store_cell->tuple);
        store_cell = local_10->next;
        pcVar5 = insert_eh_state_store(pcVar7->state,old_state,pcVar7,pcVar5);
        ((pcVar5->u20).eh_region)->count = 1;
        ((pcVar5->u20).eh_state_store)->new_state = pcVar7;
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          pcVar7 = eh_pop_state();
          pcVar5 = store_cell->tuple->prev;
          tuple_unlink_free(store_cell->tuple);
          store_cell = store_cell->next;
          pcVar5 = insert_eh_state_store(pcVar7->to_state,pcVar7->state,pcVar7,pcVar5);
          ((pcVar5->u20).eh_region)->count = 1;
          ((pcVar5->u20).cond_cells)->cc = (uint32_t)pcVar7->parent;
        }
        ((region_end->u20).eh_construct)->object = g_eh_current_state;
        return pcVar1->next;
      }
      bVar2 = false;
    }
    pcVar3 = pcVar3->next;
    iVar4 = pcVar8->refs + -1;
    pcVar8->refs = iVar4;
    if (iVar4 == 0) {
      if (bVar2) {
        eh_pop_state();
      }
      else {
        pcVar6 = eh_pop_state();
        while (pcVar6 != pcVar8) {
          pcVar6 = eh_pop_state();
        }
        bVar2 = true;
      }
    }
    else {
      bVar2 = false;
    }
    pcVar5 = store_cell->tuple->prev;
    tuple_unlink_free(store_cell->tuple);
    store_cell = store_cell->next;
    pcVar5 = insert_eh_state_store(pcVar8->to_state,pcVar8->state,pcVar8,pcVar5);
    ((pcVar5->u20).eh_region)->count = 1;
    ((pcVar5->u20).cond_cells)->cc = (uint32_t)pcVar8->parent;
    local_10 = store_cell;
  } while (pcVar3 != (c2_eh_object_cell *)0x0);
  ((region_end->u20).eh_construct)->object = g_eh_current_state;
  return pcVar1->next;
}

