c2_operand * __fastcall
make_constant_candidate_operand(c2_tuple *t,c2_operand *opnd,uint32_t *next_candidate_id)

{
  c2_operand *pcVar1;
  c2_operand *clone;
  c2_ra_candidate *cand;
  c2_live_range *range;
  uint local_c;
  c2_symbol *local_8;
  
  if (opnd->kind == '\a') {
    local_c = (opnd->u18).lo % 0x40;
  }
  else if (opnd->kind == '\x03') {
    local_c = opnd->sym->storage->fe->id % 0x40;
  }
  else {
    local_c = (uint)(opnd->sym->u28).frame_home % 0x40;
  }
  for (local_8 = g_constant_symbol_hash[local_c]; local_8 != (c2_symbol *)0x0;
      local_8 = local_8->order_next) {
    if (((local_8->u28).const_operand)->kind == opnd->kind) {
      if (opnd->kind == '\a') {
        if ((c2_symbol *)(((local_8->u28).free_next)->u18).expr == (opnd->u18).reg) break;
      }
      else if (opnd->kind == '\x03') {
        if ((c2_symbol *)((local_8->u28).free_next)->def == opnd->sym) break;
      }
      else if ((c2_symbol *)((local_8->u28).free_next)->def == opnd->sym) break;
    }
  }
  if (local_8 == (c2_symbol *)0x0) {
    local_8 = arena_alloc(1,0x54);
    local_8->cls = '\r';
    local_8->type = 0x1004;
    clone = (c2_operand *)node_clone((c2_node *)opnd);
    (local_8->u28).const_operand = clone;
    local_8->storage = local_8;
    local_8->size = 4;
    cand = arena_alloc(4,0x18);
    (local_8->u30).ra = cand;
    ((local_8->u30).ra)->id = *next_candidate_id;
    *next_candidate_id = *next_candidate_id + 1;
    local_8->order_next = g_constant_symbol_hash[local_c];
    g_constant_symbol_hash[local_c] = local_8;
    range = new_live_range(local_8);
    ((local_8->u30).order_prev)->part_next = (c2_symbol *)range;
  }
  else {
    local_8->flags5 = local_8->flags5 | 0x10;
  }
  pcVar1 = operand_new_reg(0x149,opnd->type,local_8,&g_register_candidate_home);
  pcVar1 = tuple_replace_src(t,opnd,pcVar1);
  return pcVar1;
}

