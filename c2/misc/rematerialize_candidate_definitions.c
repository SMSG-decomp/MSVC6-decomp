c2_bitset * __fastcall rematerialize_candidate_definitions(c2_list_cell *defs,c2_live_range *picked)

{
  c2_tuple *def;
  c2_live_range *lr;
  c2_tuple *t;
  c2_bitset *bs;
  int iVar1;
  c2_bitset *bs_00;
  c2_bitset *local_10;
  c2_list_cell *local_c;
  int local_4;
  
  bs_00 = (c2_bitset *)0x0;
  local_10 = (c2_bitset *)0x0;
  local_c = defs;
  if (defs == (c2_list_cell *)0x0) {
    return (c2_bitset *)0x0;
  }
  do {
    def = (local_c->u04).tuple;
    bs = collect_remat_dependencies(def,picked,&local_4);
    if (bs != (c2_bitset *)0x0) {
      if (local_4 == 0) {
        bitset_free(bs);
      }
      else {
        lr = (def->dst->u18).range;
        iVar1 = can_rematerialize_address(def,lr,bs,0);
        if (iVar1 != 0) {
          if (bs_00 == (c2_bitset *)0x0) {
            bs_00 = bitset_new(6);
            local_10 = bs_00;
          }
          bitset_set(bs_00,lr->id);
          if ((def->flags12 != '\0') && (t = def->next, bs_00 = local_10, t->kind == '\x1b')) {
            bitset_free((t->u14).regs);
            (t->u14).arg = (void *)0x0;
            tuple_unlink_free(t);
          }
          if (g_pressure_split_points != (void *)0x0) {
            list_clear_value(g_pressure_split_points,def);
          }
          substitute_definition_into_uses(def,lr,(c2_operand *)0x0);
          free_live_range(lr,1);
        }
        bitset_free(bs);
      }
    }
    local_c = local_c->next;
  } while (local_c != (c2_list_cell *)0x0);
  return bs_00;
}

