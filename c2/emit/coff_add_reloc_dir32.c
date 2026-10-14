void __fastcall coff_add_reloc_dir32(int offset,c2_fe_symbol *s)

{
  uint16_t type;
  
  type = 6;
  if ((s->cls == '\x01') && ((s->attrs & 0x1000) != 0)) {
    type = 0xb;
  }
  coff_add_reloc_typed(offset,s,type);
  return;
}

