c1_u8 __thiscall decl_check_storage_compatible(c1_declaration *decl,c1_symbol *sym)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bStack_2;
  
  uVar1._0_1_ = (decl->spec).storage;
  uVar1._1_1_ = (decl->spec).inlining;
  uVar1._2_1_ = (decl->spec).declspec;
  uVar1._3_1_ = (decl->spec).allocate;
  uVar2._0_1_ = sym->storage;
  uVar2._1_1_ = sym->flags21;
  uVar2._2_1_ = sym->flags22;
  uVar2._3_1_ = sym->flags23;
  bVar3 = sym->kind & 0x1f;
  if ((((bVar3 != 7) && (bVar3 != 8)) && ((sym->flags3 & 4) != 0)) ||
     ((((((undefined1)uVar1 ^ (undefined1)uVar2) & 7) != 0 &&
       ((((undefined1)uVar2 & 7) != 1 || (((undefined1)uVar1 & 7) != 2)))) ||
      (((uVar1._2_1_ ^ uVar2._2_1_) & 0xf) != 0)))) {
    if (((undefined1)uVar1 & 7) == 3) {
      if (g_ms_extensions == '\0') {
        return '\0';
      }
      if (((undefined1)uVar2 & 7) != 1) {
        return '\0';
      }
      if ((sym->flags1 & 1) != 0) {
        return '\0';
      }
      diag_warning(4,0xd3);
    }
    else {
      if (((((undefined1)uVar2 & 7) == 7) || (((undefined1)uVar1 & 7) == 7)) &&
         (g_block_depth == '\0')) {
        return '\0';
      }
      if (((uVar2 & 0xc0000) == 0) && ((uVar1 & 0xc0000) != 0)) {
        return '\0';
      }
    }
  }
  return '\x01';
}

