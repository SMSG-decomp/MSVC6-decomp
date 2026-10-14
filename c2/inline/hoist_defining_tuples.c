c2_tuple * __fastcall hoist_defining_tuples(c2_tuple *t,uint8_t flags12_delta)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  if (pcVar1 == (c2_operand *)0x0) {
    return t;
  }
  do {
    if (((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
       (t_00 = pcVar1->sym->def, t_00 != (c2_tuple *)0x0)) {
      tuple_unlink(t_00);
      t_00->flags12 = t_00->flags12 + flags12_delta;
      tuple_insert_before(t,t_00);
      t = hoist_defining_tuples(t_00,flags12_delta);
    }
    pcVar1 = pcVar1->next;
  } while (pcVar1 != (c2_operand *)0x0);
  return t;
}

