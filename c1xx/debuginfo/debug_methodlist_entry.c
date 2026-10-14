int __cdecl debug_methodlist_entry(int method,int record,uint offset)

{
  uint uVar1;
  ushort *attr;
  uint uVar2;
  
  uVar1 = debug_type_pad_to_4((char *)((offset & 0xffff) + record),(char)offset);
  uVar2 = *g_debug_index_queue;
  attr = (ushort *)((offset + uVar1 & 0xffff) + record);
  g_debug_index_queue = g_debug_index_queue + 1;
  *(uint *)(attr + 2) = uVar2;
  attr[1] = 0;
  uVar2 = debug_method_field_attributes(method,attr,(uint *)(attr + 4));
  return uVar2 + 8 + offset + uVar1;
}

