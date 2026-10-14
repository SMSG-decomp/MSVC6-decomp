int32_t __fastcall x87_range_fits_stack(c2_function *fn,c2_live_range *lr,c2_bitset *on_stack)

{
  c2_list_cell_u04 cVar1;
  c2_tuple *pcVar2;
  c2_list_cell *pcVar3;
  bool bVar4;
  c2_list_cell *list;
  c2_list_cell *def_live_sets;
  c2_bitset *end_live;
  c2_list_cell *end_set;
  c2_bitset *def_live;
  c2_list_cell *def_cell;
  c2_bitset *dst;
  uint32_t uVar5;
  int iVar6;
  c2_list_cell *conflict_def;
  c2_live_range *reload_range;
  int32_t iVar7;
  uint32_t uVar8;
  int iVar9;
  c2_tuple *pcVar10;
  c2_list_cell *end_cells;
  c2_list_cell *def_cells;
  c2_tuple *local_10;
  c2_list_cell *def_set;
  c2_list_cell *end_cell;
  c2_tuple *end_tuple;
  c2_list_cell *end_walk;
  c2_list_cell *end_live_sets;
  c2_list_cell *def_walk;
  c2_list_cell *reload_defs;
  
  end_walk = (c2_list_cell *)lr->prefs;
  local_10 = (c2_tuple *)0x0;
  end_cells = (c2_list_cell *)0x0;
  end_live_sets = (c2_list_cell *)0x0;
  while (end_walk != (c2_list_cell *)0x0) {
    def_live_sets = alloc_split_cell();
    end_tuple = (end_walk->u04).tuple;
    def_live_sets->next = end_live_sets;
    end_live = x87_live_at(end_tuple,on_stack);
    (def_live_sets->u04).set = end_live;
    end_set = alloc_split_cell();
    cVar1 = end_walk->u04;
    end_walk = end_walk->next;
    end_set->next = end_cells;
    end_set->u04 = cVar1;
    end_live_sets = def_live_sets;
    end_cells = end_set;
  }
  def_cells = (c2_list_cell *)0x0;
  pcVar10 = (lr->u38).def;
  list = (c2_list_cell *)0x0;
  while (pcVar10 != (c2_tuple *)0x0) {
    end_set = alloc_split_cell();
    pcVar2 = (c2_tuple *)pcVar10->op;
    end_set->next = list;
    def_live = x87_live_at(pcVar2,on_stack);
    (end_set->u04).set = def_live;
    def_cell = alloc_split_cell();
    cVar1 = (c2_list_cell_u04)pcVar10->op;
    pcVar10 = pcVar10->next;
    def_cell->next = def_cells;
    def_cell->u04 = cVar1;
    list = end_set;
    def_cells = def_cell;
  }
  bVar4 = false;
  dst = bitset_new(6);
  end_cell = end_cells;
  for (end_set = end_live_sets; pcVar3 = def_cells, def_set = list, end_set != (c2_list_cell *)0x0;
      end_set = end_set->next) {
    for (; def_set != (c2_list_cell *)0x0; def_set = def_set->next) {
      bitset_copy(dst,(end_set->u04).set);
      bitset_andnot(dst,(def_set->u04).set);
      if (dst->chunks != (c2_bitset_chunk *)0x0) {
        uVar5 = bitset_iter_next(dst);
        while (uVar5 != 0xffffffff) {
          reload_range = live_range_from_id(uVar5);
          def_walk = (reload_range->u38).x87_defs;
          if (def_walk != (c2_list_cell *)0x0) {
            conflict_def = def_walk;
            do {
              if ((conflict_def->u04).tuple == (pcVar3->u04).tuple) {
                if (conflict_def != (c2_list_cell *)0x0) goto LAB_1075e9cb;
                break;
              }
              conflict_def = conflict_def->next;
            } while (conflict_def != (c2_list_cell *)0x0);
          }
          for (; def_walk != (c2_list_cell *)0x0; def_walk = def_walk->next) {
            iVar7 = x87_split_if_live_at((def_walk->u04).tuple,lr);
            if (iVar7 != 0) {
              bVar4 = true;
            }
          }
LAB_1075e9cb:
          uVar5 = bitset_iter_next((c2_bitset *)0x0);
        }
      }
      bitset_copy(dst,(def_set->u04).set);
      bitset_andnot(dst,(end_set->u04).set);
      if (dst->chunks != (c2_bitset_chunk *)0x0) {
        if (((end_cell->u04).tuple)->op == 0x163) {
          pcVar10 = ((end_cell->u04).tuple)->next;
          uVar5 = pcVar10->op;
          while (uVar5 == 0x163) {
            reload_range = (pcVar10->dst->u18).range;
            if (reload_range->colour != (c2_register_descriptor *)0x0) {
              uVar5 = reload_range->id;
              uVar8 = bitset_test(dst,uVar5);
              if (uVar8 != 0) {
                bitset_clear(dst,uVar5);
                bitset_set((end_set->u04).set,uVar5);
                tuple_move_after(pcVar10,(end_cell->u04).tuple);
                pcVar10 = (end_cell->u04).tuple;
              }
            }
            pcVar10 = pcVar10->next;
            uVar5 = pcVar10->op;
          }
        }
        if (dst->chunks != (c2_bitset_chunk *)0x0) {
          if (pcVar3->next == (c2_list_cell *)0x0) {
            pcVar10 = (c2_tuple *)0x0;
            uVar5 = bitset_iter_next(dst);
            while (uVar5 != 0xffffffff) {
              reload_range = live_range_from_id(uVar5);
              reload_defs = (reload_range->u38).x87_defs;
              if (reload_defs->next != (c2_list_cell *)0x0) {
LAB_10778384:
                if (uVar5 != 0xffffffff) goto LAB_10778389;
                break;
              }
              if (pcVar10 == (c2_tuple *)0x0) {
                pcVar10 = (reload_defs->u04).tuple;
              }
              else if (pcVar10 != (reload_defs->u04).tuple) goto LAB_10778384;
              uVar5 = bitset_iter_next((c2_bitset *)0x0);
            }
            if ((pcVar10 != (pcVar3->u04).tuple) &&
               (local_10 = x87_find_split_point(lr,(pcVar3->u04).tuple,pcVar10,dst),
               local_10 != (c2_tuple *)0x0)) {
              pcVar2 = (lr->u38).def;
              (pcVar3->u04).tuple = pcVar10;
              pcVar2->op = (uint32_t)pcVar10;
              bitset_clear_all(dst);
            }
          }
LAB_10778389:
          if (dst->chunks != (c2_bitset_chunk *)0x0) {
            uVar5 = bitset_iter_next(dst);
            while (uVar5 != 0xffffffff) {
              reload_range = live_range_from_id(uVar5);
              pcVar10 = (reload_range->u38).def;
              if (pcVar10 != (c2_tuple *)0x0) {
                do {
                  if ((c2_tuple *)pcVar10->op == (pcVar3->u04).tuple) {
                    if (pcVar10 != (c2_tuple *)0x0) goto LAB_107783eb;
                    break;
                  }
                  pcVar10 = pcVar10->next;
                } while (pcVar10 != (c2_tuple *)0x0);
              }
              for (end_walk = (c2_list_cell *)reload_range->prefs; end_walk != (c2_list_cell *)0x0;
                  end_walk = end_walk->next) {
                iVar7 = x87_split_if_live_at((end_walk->u04).tuple,lr);
                if (iVar7 != 0) {
                  bVar4 = true;
                }
              }
LAB_107783eb:
              uVar5 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
      }
      pcVar3 = pcVar3->next;
    }
    uVar5 = bitset_iter_next((end_set->u04).set);
    while (uVar5 != 0xffffffff) {
      reload_range = live_range_from_id(uVar5);
      for (pcVar10 = (reload_range->u38).def; pcVar10 != (c2_tuple *)0x0; pcVar10 = pcVar10->next) {
        iVar7 = x87_split_if_live_at((c2_tuple *)pcVar10->op,lr);
        if (iVar7 != 0) {
          bVar4 = true;
        }
      }
      uVar5 = bitset_iter_next((c2_bitset *)0x0);
    }
    end_cell = end_cell->next;
  }
  bitset_free(dst);
  for (end_set = end_live_sets; pcVar3 = list, end_set != (c2_list_cell *)0x0;
      end_set = end_set->next) {
    bitset_free((end_set->u04).set);
  }
  for (; pcVar3 != (c2_list_cell *)0x0; pcVar3 = pcVar3->next) {
    bitset_free((pcVar3->u04).set);
  }
  free_split_cell_list(end_live_sets);
  free_split_cell_list(end_cells);
  free_split_cell_list(list);
  free_split_cell_list(def_cells);
  if (!bVar4) {
    end_walk = (c2_list_cell *)lr->prefs->next;
    if (end_walk != (c2_list_cell *)0x0) {
      iVar6 = x87_stack_depth_at((c2_tuple *)lr->prefs->reg);
      for (; end_walk != (c2_list_cell *)0x0; end_walk = end_walk->next) {
        iVar9 = x87_stack_depth_at((end_walk->u04).tuple);
        if (iVar6 != iVar9) {
          if ((end_walk != (c2_list_cell *)0x0) &&
             (iVar6 = x87_check_range_stack_depth(fn,lr), iVar6 != 0)) goto LAB_1075ea1c;
          break;
        }
      }
    }
    pcVar10 = (lr->u38).def;
    bVar4 = false;
    if (pcVar10 != (c2_tuple *)0x0) {
      do {
        iVar6 = x87_split_before_conflicting_def((c2_symbol *)lr,(c2_tuple *)pcVar10->op);
        if (iVar6 != 0) {
          bVar4 = true;
        }
        pcVar10 = pcVar10->next;
      } while (pcVar10 != (c2_tuple *)0x0);
      if (bVar4) goto LAB_1075ea1c;
    }
    return 1;
  }
LAB_1075ea1c:
  if (local_10 != (c2_tuple *)0x0) {
    x87_mark_last_use_and_free(local_10);
  }
  return 0;
}

