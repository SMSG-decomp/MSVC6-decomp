void __thiscall decl_add_reference_modifier(void *decl,ushort *mods)

{
  int ref_mod;
  c1_type *layer;
  ushort *p;
  
  p = mods + 2;
  ref_mod._0_2_ = type_check_based_reference(decl,*mods);
  layer = (c1_type *)record_pos_new(0x80,(ushort)ref_mod,(int *)p);
  decl_check_modifier_over_reference(decl,layer);
  if (*(int *)((int)decl + 8) == 0) {
    *(c1_type **)((int)decl + 8) = layer;
    *(c1_type **)((int)decl + 4) = layer;
    return;
  }
  *(c1_type **)(*(int *)((int)decl + 8) + 4) = layer;
  *(c1_type **)((int)decl + 8) = layer;
  return;
}

