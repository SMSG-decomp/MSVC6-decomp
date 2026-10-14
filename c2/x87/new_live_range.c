c2_live_range * __fastcall new_live_range(c2_symbol *sym)

{
  int iVar1;
  c2_live_range *lr;
  c2_bitset *dst;
  
  if ((sym->u34).parent != (c2_symbol *)0x0) {
    sym = (sym->u34).parent;
  }
  if (g_live_range_free_list == (c2_live_range *)0x0) {
    lr = arena_alloc(4,0x44);
    lr->id = g_next_live_range_id;
    g_next_live_range_id = g_next_live_range_id + 1;
  }
  else {
    lr = g_live_range_free_list;
    g_live_range_free_list = g_live_range_free_list->hash_next;
  }
  lr->self = lr;
  lr->kind = '\x02';
  lr->sym = sym;
  dst = bitset_new(6);
  lr->allowed = dst;
  lr->flags5 = lr->flags5 | 1;
  iVar1 = g_type_class[sym->type >> 0xc];
  bitset_or(dst,g_class_allowed_sets[iVar1]);
  bitset_set(g_class_candidates[iVar1],lr->id);
  hash_live_range(lr);
  return lr;
}

