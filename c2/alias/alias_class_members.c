c2_symbol_cell * __fastcall alias_class_members(uint32_t cls)

{
  if (cls < g_alias_class_count) {
    return g_alias_primary_table[cls];
  }
  return g_alias_primary_table[g_alias_secondary_records[cls - g_alias_class_count].parent];
}

