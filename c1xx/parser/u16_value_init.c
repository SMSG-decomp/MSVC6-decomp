c1_decl_modifier * __thiscall u16_value_init(c1_decl_modifier *mod,ushort bits)

{
  *(ushort *)&mod->bits = bits;
  mod->based = (void *)0x0;
  return mod;
}

