void __fastcall add_sub_const_to_inc_dec(c2_tuple *t)

{
  uint uVar1;
  c2_tuple *pcVar2;
  uint uVar3;
  uint32_t op;
  
  uVar1 = (t->src->next->u18).lo;
  if ((uVar1 == 2) || (uVar1 == 1)) {
    op = (-(uint)(t->op != 0x2d) & 0xfffffffd) + 0x21;
  }
  else {
    if ((uVar1 != 0xfffffffe) && (uVar1 != 0xffffffff)) {
      return;
    }
    op = (-(uint)(t->op != 0x2d) & 3) + 0x1e;
  }
  uVar3 = (int)uVar1 >> 0x1f;
  if ((g_opt_favor_speed == 0) || ((uVar1 ^ uVar3) - uVar3 != 2)) {
    if (((g_opt_basic != 0) &&
        ((((t->type & 0xf000) == 0x2000 && (t->dst->kind == '\x01')) &&
         (pcVar2 = find_next_use_of_symbol_2(t,t->dst->sym), pcVar2 != (c2_tuple *)0x0)))) &&
       (pcVar2->op == 0x178)) {
      return;
    }
    tuple_remove_src(t,t->src->next);
    t->op = op;
    if ((uVar1 ^ uVar3) - uVar3 == 2) {
      pcVar2 = tuple_new(op,t->type,t->dst,t->src,tuple_insert_before,t);
      set_flags_effects(pcVar2);
    }
  }
  return;
}

