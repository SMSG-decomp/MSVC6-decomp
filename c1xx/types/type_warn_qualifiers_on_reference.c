void __thiscall
type_warn_qualifiers_on_reference(c1_ptr_operator *op,c1_decl_modifier *mods,c1_decl_modifier *cv)

{
  c1_u32 cVar1;
  
  if ((short)cv->bits != 0) {
    diag_warning(1,0xe3);
  }
  op->kind = 0x80;
  cVar1 = mods->bits;
  op->cv = 0;
  op->modifiers = (c1_u16)cVar1;
  op->extra = (void *)0x0;
  return;
}

