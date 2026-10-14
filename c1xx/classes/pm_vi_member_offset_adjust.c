void __cdecl
pm_vi_member_offset_adjust
          (c1_symbol *cls,int node,int value,int value2,int *offset_out,int *index_out)

{
  int iVar1;
  
  *offset_out = value;
  if (node != 0) {
    iVar1 = class_vbptr_offset((c1_symbol *)node);
    *offset_out = *offset_out + iVar1;
  }
  if (value2 == 0) {
    iVar1 = class_vbptr_offset(cls);
    *offset_out = *offset_out - iVar1;
  }
  if (index_out != (int *)0x0) {
    if (value2 != 0) {
      class_virtual_base_info
                (g_scope_vector->entries[*(short *)(value2 + 0x18)],cls,(int *)0x0,index_out,
                 (c1_type **)0x0);
      return;
    }
    *index_out = 0;
  }
  return;
}

