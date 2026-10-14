void __thiscall operator_id_set(c1_decl_modifier *mod,short bits,void *based)

{
  if ((bits == 0x18) && (based == (void *)0x0)) {
    bits = 0;
  }
  mod->based = based;
  *(short *)&mod->bits = bits;
  return;
}

