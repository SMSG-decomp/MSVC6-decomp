void __thiscall
type_pair_record_init(c1_ptr_operator *op,c1_decl_modifier *mods,c1_decl_modifier *cv)

{
  op->kind = 0x82;
  op->modifiers = (c1_u16)mods->bits;
  op->cv = (c1_u16)cv->bits;
  op->extra = mods->based;
  return;
}

