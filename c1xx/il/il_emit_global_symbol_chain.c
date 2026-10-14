void __fastcall il_emit_global_symbol_chain(byte *sym)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *symref;
  
  pbVar1 = sym + 8;
  if (pbVar1 != (byte *)0x0) {
    bVar3 = *sym & 0x1f;
    symref = pbVar1;
    if ((((bVar3 != 7) && (bVar3 != 8)) && (bVar3 != 6)) && ((*sym & 0x1f) != 0x1a)) {
      symref = *(byte **)(sym + 0x14);
    }
    while ((pbVar1 != (byte *)0x0 && (symref != (byte *)0x0))) {
      bVar3 = symref[-8];
      while ((bVar3 & 0x1f) == 0x1a) {
        symref = *(byte **)(symref + 4);
        if (symref == (byte *)0x0) {
          return;
        }
        bVar3 = symref[-8];
      }
      bVar3 = *sym & 0x1f;
      if (((bVar3 == 7) || (bVar3 == 8)) || (bVar3 == 6)) {
        il_emit_global_symbol((int *)symref);
        symref = (byte *)0x0;
      }
      else {
        pbVar2 = *(byte **)(symref + 4);
        il_emit_global_symbol((int *)symref);
        symref = pbVar2;
      }
    }
  }
  return;
}

