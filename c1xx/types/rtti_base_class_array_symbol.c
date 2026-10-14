int __cdecl rtti_base_class_array_symbol(c1_symbol *cls,int *count_out,uint *attributes)

{
  c1_u8 *item;
  void *name;
  c1_symbol *pcVar1;
  c1_vector *pcVar2;
  int iVar3;
  c1_type *local_10;
  c1_vector *local_c;
  ushort zero_half;
  
  local_10 = (c1_type *)0x0;
  name = name_intern_special_32(cls);
  pcVar1 = eh_new_compiler_data_object(name,&local_10,"__RTTIBaseClassArray",1);
  item = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  *(c1_symbol **)item = pcVar1;
  pcVar2 = vector_new(0,0);
  *(c1_vector **)(item + 4) = pcVar2;
  local_c = g_rtti_catchable_types;
  zero_half = 0;
  iVar3 = rtti_collect_base_class_descriptors
                    ((int)cls,*(c1_vector **)(item + 4),attributes,0,(int *)&local_c);
  *count_out = iVar3 + 1;
  if (g_rtti_base_class_arrays == (c1_vector *)0x0) {
    g_rtti_base_class_arrays = vector_new(0,0);
  }
  vector_push(g_rtti_base_class_arrays,item);
  return (int)pcVar1;
}

