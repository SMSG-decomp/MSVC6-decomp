c1_ovl_candidate * __thiscall
ovl_builtin_candidate_init
          (c1_ovl_candidate *entry,c1_builtin_operator_row *row,c1_type *type,c1_type *type2,
          c1_conversion *conv_slots,c1_ovl_candidate *prev)

{
  entry->conversions = conv_slots;
  entry->builtin_left = type;
  entry->row = row;
  entry->flags = entry->flags | 4;
  entry->builtin_right = type2;
  if (prev != (c1_ovl_candidate *)0x0) {
    entry->prev = prev;
    prev->next = entry;
  }
  return entry;
}

