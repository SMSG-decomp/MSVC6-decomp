uint16_t __fastcall coff_symbol_type_bits(c2_fe_symbol *s)

{
  uint16_t uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  if (s->cls == '\x04') {
    if (((byte)s->attrs & 0xc) == 0xc) {
      uVar2 = g_coff_cor_basetype_table[(char)(s->u4a).function.cor_type] << 4;
    }
    uVar1 = uVar2 | 0x20;
  }
  return uVar1;
}

