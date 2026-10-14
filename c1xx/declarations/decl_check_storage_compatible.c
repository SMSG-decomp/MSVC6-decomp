char __thiscall decl_check_storage_compatible(c1_declarator *d,c1_symbol *sym)

{
  uint uVar1;
  uint uVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  byte bVar5;
  
  pcVar3 = sym;
  uVar1 = *(uint *)d->spec;
  uVar2._0_1_ = sym->storage;
  uVar2._1_1_ = sym->flags21;
  uVar2._2_1_ = sym->flags22;
  uVar2._3_1_ = sym->flags23;
  bVar4 = sym->kind & 0x1f;
  bVar5 = (byte)uVar1;
  sym._2_1_ = (byte)(uVar1 >> 0x10);
  if (((((bVar4 != 7) && (bVar4 != 8)) && ((pcVar3->flags4 & 4) != 0)) ||
      (((((bVar5 ^ (undefined1)uVar2) & 7) != 0 &&
        ((((undefined1)uVar2 & 7) != 1 || ((bVar5 & 7) != 2)))) ||
       (((sym._2_1_ ^ uVar2._2_1_) & 0xf) != 0)))) ||
     (sym._3_1_ = (byte)(uVar1 >> 0x18), ((uVar2._3_1_ ^ sym._3_1_) & 0x10) != 0)) {
    if ((bVar5 & 7) == 3) {
      if (g_ms_extensions == '\0') {
        return '\0';
      }
      if (((undefined1)uVar2 & 7) != 1) {
        return '\0';
      }
      if ((pcVar3->flags2 & 4) != 0) {
        return '\0';
      }
      diag_warning(4,0xd3);
    }
    else {
      if (((((undefined1)uVar2 & 7) == 7) || ((bVar5 & 7) == 7)) && (g_block_depth == '\0')) {
        return '\0';
      }
      if (((uVar2 & 0xc0000) == 0) && ((uVar1 & 0xc0000) != 0)) {
        return '\0';
      }
    }
  }
  return '\x01';
}

