void __cdecl
class_virtual_base_info
          (c1_symbol *base,c1_symbol *cls,int *vbptr_offset,int *vbase_index,c1_type **base_type)

{
  class_vbase_get_info(base,cls,vbptr_offset,vbase_index,base_type);
  return;
}

