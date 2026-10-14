void __thiscall
qualified_name_record_init
          (c1_ptr_operator *op,c1_overload_set *qual,c1_decl_modifier *mods,c1_decl_modifier *cv)

{
  op->kind = 0x8a;
  op->modifiers = (c1_u16)mods->bits;
  op->cv = (c1_u16)cv->bits;
  lookup_member_pointer_class(&op->extra,qual);
  if (op->extra == (void *)0x0) {
    op->kind = 0x82;
  }
  return;
}

