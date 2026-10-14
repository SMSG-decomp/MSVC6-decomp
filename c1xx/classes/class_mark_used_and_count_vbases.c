void __cdecl class_mark_used_and_count_vbases(c1_symbol *cls,c1_symbol *unused)

{
  class_init_table_pointers((int)cls,0,'\0');
  class_init_virtual_base_members(cls,(char)unused);
  return;
}

