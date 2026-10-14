void __thiscall import_name_list_push(c1_import_enum_table *table,wchar_t *enum_name,int value)

{
  c1_import_enum_entry *node;
  c1_u8 *pcVar1;
  
  node = __2_YAPAXI_Z(0x10);
  if (node != (c1_import_enum_entry *)0x0) {
    pcVar1 = wide_to_multibyte_arena(enum_name);
    node->constant = table->name;
    node->enum_name = (char *)pcVar1;
    node->value = value;
    node->next = table->buckets[table->bucket];
    table->buckets[table->bucket] = node;
    return;
  }
  diag_fatal_simple(0x3c);
}

