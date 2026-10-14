void __thiscall
decl_tag_declarator_set_kind(c1_declaration *decl,ushort kind,void **insert_fn,int unused)

{
  decl->tag_kind = kind;
  if (((g_compile_flags_c4 & 0x20000) == 0) && (g_pch_precomp_types == '\0')) {
    decl->flags2c = decl->flags2c | 0x10;
  }
  if ((-1 < g_class_depth) && (*insert_fn != scope_insert_through_object)) {
    decl->owner = g_struct_layouts[g_class_depth].tag;
  }
  decl->flags2d = decl->flags2d | 4;
  decl->flags2f = (g_block_depth != '\0') << 5 | decl->flags2f & 0xdf;
  return;
}

