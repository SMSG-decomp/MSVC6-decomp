void reserve_alias_class_ids(void)

{
  g_alias_reserved_class_base = g_alias_class_count;
  g_alias_reserved_class_next = g_alias_class_count;
  g_alias_reserved_number_base = g_alias_symbol_number_count;
  g_alias_reserved_number_next = g_alias_symbol_number_count;
  g_alias_class_count = g_alias_class_count + 0x10;
  g_alias_symbol_number_count = g_alias_symbol_number_count + 0x10;
  return;
}

