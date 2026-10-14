int __cdecl debug_emit_types_twice(c1_symbol *cls,int *count,ushort *property)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = g_debug_index_queue;
  debug_type_record_class_fieldlist(1,cls,count,property);
  g_debug_index_queue = puVar1;
  iVar2 = debug_type_record_class_fieldlist(2,cls,count,property);
  g_debug_index_queue = puVar1;
  return iVar2;
}

