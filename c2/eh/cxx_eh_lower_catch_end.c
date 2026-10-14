void __fastcall cxx_eh_lower_catch_end(c2_tuple *t)

{
  uint uVar1;
  c2_eh_state *pcVar2;
  c2_eh_state *object;
  uint uVar3;
  c2_tuple *new_tuple;
  c2_eh_op *store_op;
  c2_eh_tuple_cell *cell;
  c2_tuple *region_begin;
  c2_eh_op_region *final_region;
  c2_tuple *pcVar4;
  c2_eh_op_region_end *final_region_end;
  c2_tuple_u20 *pcVar5;
  c2_eh_op_region *split_region;
  c2_eh_op_region_end *split_region_end;
  c2_eh_op_region *flag200_region;
  c2_eh_op_region_end *flag200_region_end;
  c2_fe_symbol *label_sym;
  c2_const_operand *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_tuple *last;
  c2_insert_fn *pcVar9;
  uint pops_states;
  c2_operand *cond;
  c2_tuple *prev_region;
  int32_t nobjects;
  c2_tuple *first_store;
  c2_eh_tuple_cell *store_cells;
  int32_t pop_count;
  c2_eh_object_cell *local_20;
  c2_eh_tuple_cell *store_tail;
  c2_eh_state *resume_state;
  c2_insert_fn *splice_fn;
  uint32_t region_flags;
  c2_eh_op_region *region;
  
  region = (t->u20).eh_region;
  pop_count = region->count;
  region_flags = region->flags;
  pops_states = region_flags & 0x20;
  last = (c2_tuple *)0x0;
  resume_state = (c2_eh_state *)0x0;
  nobjects = 0;
  local_20 = (c2_eh_object_cell *)0x0;
  prev_region = (c2_tuple *)0x0;
  first_store = (c2_tuple *)0x0;
  store_cells = (c2_eh_tuple_cell *)0x0;
  if (g_eh_current_state == (c2_eh_state *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\ehexcept.c",0x37b);
  }
  object = g_eh_current_state;
  if (pops_states != 0) {
    object = eh_pop_state();
  }
  do {
    if (object == (c2_eh_state *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\ehexcept.c",0x37f);
    }
    uVar1 = object->flags;
    uVar3 = uVar1 & 0xff;
    if (uVar3 == (region_flags & 7)) {
      if (nobjects == 0) {
        new_tuple = last;
        if ((uVar1 & 0x200) == 0) {
LAB_1075539d:
          local_20 = list_append_new(local_20,object);
          nobjects = nobjects + 1;
          object->refs = object->refs + 1;
          new_tuple = tuple_new_pseudo(0x1a8,0x1004);
          store_op = arena_alloc(1,0x10);
          (new_tuple->u20).eh_op = store_op;
          (store_op->construct).object = object;
          if (last != (c2_tuple *)0x0) {
            tuple_splice_after(last,new_tuple);
          }
          if (first_store == (c2_tuple *)0x0) {
            first_store = new_tuple;
          }
          if (store_cells == (c2_eh_tuple_cell *)0x0) {
            cell = arena_alloc(1,8);
            store_cells = cell;
          }
          else {
            cell = arena_alloc(1,8);
            store_tail->next = cell;
          }
          cell->tuple = new_tuple;
          store_tail = cell;
        }
      }
      else {
        if ((uVar1 & 0x200) == 0) goto LAB_1075539d;
        pcVar4 = tuple_new_pseudo(0x1a2,g_ptr_type);
        if (first_store->prev == (c2_tuple *)0x0) {
          pcVar4->next = first_store;
          first_store->prev = pcVar4;
        }
        else {
          tuple_insert_before(first_store,pcVar4);
        }
        flag200_region = arena_alloc(1,0x10);
        flag200_region->objects = (c2_eh_object_cell *)prev_region;
        flag200_region->flags = region_flags;
        flag200_region->count = nobjects;
        flag200_region->state_stores = store_cells;
        (pcVar4->u20).eh_region = flag200_region;
        store_cells = (c2_eh_tuple_cell *)0x0;
        nobjects = 0;
        first_store = (c2_tuple *)0x0;
        new_tuple = tuple_new_pseudo(0x1a3,0x1004);
        tuple_splice_after(last,new_tuple);
        flag200_region_end = arena_alloc(1,0x10);
        (new_tuple->u20).eh_region_end = flag200_region_end;
        flag200_region_end->region_begin = pcVar4;
        prev_region = pcVar4;
      }
      if ((object->flags & 0x100) == 0) {
        if (pops_states == 0) {
          pcVar4 = clone_tuple_list((object->u1c).unwind_body);
        }
        else {
          pcVar4 = (object->u1c).unwind_body;
          (object->u1c).unwind_body = (c2_tuple *)0x0;
        }
        tuple_range_set_line(pcVar4,(c2_tuple *)0x0);
        if (new_tuple != (c2_tuple *)0x0) {
          tuple_splice_after(new_tuple,pcVar4);
        }
        last = (c2_tuple *)list_last((c2_link *)pcVar4);
      }
      else {
        label_sym = label_symbol_new();
        last = tuple_new_label(label_sym);
        pcVar9 = (c2_insert_fn *)(-(uint)(new_tuple != (c2_tuple *)0x0) & 0x1070b315);
        pcVar6 = operand_new_intconst(0x1004,object->guard_bit,0);
        pcVar7 = operand_new_sym(0x14a,0x1004,object->guard_word);
        pcVar8 = tuple_new_binary_temp(0x172,0x1004,pcVar7,pcVar6,pcVar9,new_tuple);
        splice_fn = tuple_splice_after;
        pcVar4 = pcVar8;
        pcVar6 = operand_new_intconst(0x1004,0,0);
        pcVar4 = tuple_new_compare(0x17d,0x1004,pcVar8->dst,pcVar6,splice_fn,pcVar4);
        pcVar4 = tuple_new_branch(0x185,'\x01',(c2_node *)last,pcVar4->dst,pcVar4,tuple_splice_after
                                  ,pcVar4);
        pcVar7 = operand_new_sym(0x14a,0x1004,object->guard_word);
        splice_fn = tuple_splice_after;
        pcVar6 = operand_new_intconst(0x1004,~object->guard_bit,0);
        pcVar4 = tuple_new_binary(0x172,0x1004,pcVar7,pcVar7,pcVar6,splice_fn,pcVar4);
        if (pops_states == 0) {
          pcVar8 = clone_tuple_list((object->u1c).unwind_body);
        }
        else {
          pcVar8 = (object->u1c).unwind_body;
          (object->u1c).unwind_body = (c2_tuple *)0x0;
        }
        tuple_range_set_line(pcVar8,(c2_tuple *)0x0);
        tuple_splice_after(pcVar4,pcVar8);
        pcVar4 = (c2_tuple *)list_last((c2_link *)pcVar8);
        tuple_splice_after(pcVar4,last);
      }
    }
    else {
      pcVar2 = object;
      if ((uVar3 == 1) || (pcVar2 = resume_state, uVar3 == 6)) {
        resume_state = pcVar2;
        pop_count = pop_count + 1;
      }
      else {
        if (nobjects != 0) {
          new_tuple = tuple_new_pseudo(0x1a2,0x1004);
          pcVar4 = last;
          if ((first_store == (c2_tuple *)0x0) || (first_store->prev == (c2_tuple *)0x0)) {
            new_tuple->next = first_store;
            first_store->prev = new_tuple;
            if (last == (c2_tuple *)0x0) {
              pcVar4 = new_tuple;
            }
          }
          else {
            tuple_insert_before(first_store,new_tuple);
          }
          split_region = arena_alloc(1,0x10);
          split_region->objects = (c2_eh_object_cell *)prev_region;
          split_region->flags = region_flags;
          split_region->count = nobjects;
          split_region->state_stores = store_cells;
          (new_tuple->u20).eh_region = split_region;
          store_cells = (c2_eh_tuple_cell *)0x0;
          nobjects = 0;
          first_store = (c2_tuple *)0x0;
          last = tuple_new_pseudo(0x1a3,0x1004);
          tuple_splice_after(pcVar4,last);
          split_region_end = arena_alloc(1,0x10);
          split_region_end->region_begin = new_tuple;
          (last->u20).eh_region_end = split_region_end;
          prev_region = new_tuple;
        }
        while (prev_region != (c2_tuple *)0x0) {
          pcVar5 = &prev_region->u20;
          prev_region = (c2_tuple *)pcVar5->eh_region->objects;
          pcVar5->eh_region->objects = local_20;
        }
        local_20 = (c2_eh_object_cell *)0x0;
        pcVar9 = (c2_insert_fn *)(-(uint)(last != (c2_tuple *)0x0) & 0x1070b315);
        pcVar4 = (c2_tuple *)0x0;
        cond = (c2_operand *)0x0;
        pcVar7 = operand_new_temp(0x1004);
        last = tuple_new_branch(0x187,'\0',(c2_node *)pcVar7,cond,pcVar4,pcVar9,last);
      }
    }
    pop_count = pop_count + -1;
    if (pop_count < 1) {
      if (resume_state != (c2_eh_state *)0x0) {
        push_eh_state(resume_state);
      }
      if (last == (c2_tuple *)0x0) {
        region->objects = local_20;
        return;
      }
      pcVar4 = last;
      if (nobjects != 0) {
        region_begin = tuple_new_pseudo(0x1a2,0x1004);
        if (first_store->prev == (c2_tuple *)0x0) {
          region_begin->next = first_store;
          first_store->prev = region_begin;
        }
        else {
          tuple_insert_before(first_store,region_begin);
        }
        final_region = arena_alloc(1,0x10);
        final_region->objects = (c2_eh_object_cell *)prev_region;
        final_region->flags = region_flags;
        final_region->count = nobjects;
        final_region->state_stores = store_cells;
        (region_begin->u20).eh_region = final_region;
        pcVar4 = tuple_new_pseudo(0x1a3,0x1004);
        tuple_splice_after(last,pcVar4);
        final_region_end = arena_alloc(1,0x10);
        (pcVar4->u20).eh_region_end = final_region_end;
        final_region_end->region_begin = region_begin;
        prev_region = region_begin;
      }
      while (prev_region != (c2_tuple *)0x0) {
        pcVar5 = &prev_region->u20;
        prev_region = (c2_tuple *)pcVar5->eh_region->objects;
        pcVar5->eh_region->objects = local_20;
      }
      pcVar4 = list_last_by_0c(pcVar4);
      tuple_splice_after(t,pcVar4);
      tuple_unlink_free(t);
      return;
    }
    if (pops_states == 0) {
      object = object->parent;
    }
    else {
      object = eh_pop_state();
    }
  } while( true );
}

