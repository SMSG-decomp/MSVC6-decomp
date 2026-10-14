int __fastcall fe_symbol_storage_is_0x40(c2_fe_symbol *s)

{
  return (uint)(((byte)s->storage & 0x70) == 0x40);
}

