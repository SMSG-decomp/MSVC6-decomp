void __fastcall insert_split_marker_after_spill(c2_tuple *t,void *range)

{
  if (t->next->op == 0x164) {
    t = t->next;
  }
  insert_pressure_split_marker(t,(c2_bitset *)0x0,(c2_bitset *)0x0,range);
  return;
}

