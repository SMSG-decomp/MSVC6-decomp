uint32_t __fastcall inasm_read_compact_value(uint16_t **cursor)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = *cursor;
  *cursor = puVar2 + 1;
  uVar1 = *puVar2;
  if ((uVar1 & 0x8000) != 0) {
    *cursor = puVar2 + 2;
    return (uint)puVar2[1] << 0xf | (uint)(uVar1 & 0x7fff);
  }
  return (uint)uVar1;
}

