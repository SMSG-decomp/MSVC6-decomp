uint __cdecl class_member_padding(uint alignment)

{
  uint uVar1;
  
  uVar1 = class_padding_for_offset(alignment,g_struct_layouts[g_class_depth].offset);
  return uVar1;
}

