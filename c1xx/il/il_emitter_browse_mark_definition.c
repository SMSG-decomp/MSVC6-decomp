int __thiscall il_emitter_browse_mark_definition(c1xx_il_emitter_browse *this,int set,int sym)

{
  byte *pbVar1;
  
  pbVar1 = browse_ring_find_definition(sym);
  if (pbVar1 == (byte *)0x0) {
    return 0;
  }
  if (set != 0) {
    pbVar1[0x14] = pbVar1[0x14] | 0x20;
    return 1;
  }
  *(ushort *)(pbVar1 + 0x14) = *(ushort *)(pbVar1 + 0x14) & 0xffdf;
  return 1;
}

