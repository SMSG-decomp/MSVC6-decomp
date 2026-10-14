char __thiscall decl_check_redeclaration(c1_declaration *decl,c1_symbol *sym)

{
  void *pvVar1;
  c1_u8 cVar2;
  byte bVar3;
  uint uVar4;
  void *pvVar5;
  
  if ((decl->flags2c & 0x40) != 0) {
    sym->flags2 = sym->flags2 | 1;
    return '\x01';
  }
  uVar4 = decl_check_function_redeclaration_varargs(decl,sym);
  if (uVar4 == 0) {
    cVar2 = decl_check_storage_compatible(decl,sym);
    if (cVar2 == '\0') {
      bVar3 = sym->kind & 0x1f;
      if ((bVar3 == 7) || (bVar3 == 8)) {
        uVar4 = 0x177;
        goto LAB_106378ff;
      }
    }
    else {
      if (((sym->flags3 & 4) != 0) && ((decl->flags2c & 4) != 0)) {
        uVar4 = 0x176;
        goto LAB_106378ff;
      }
      if (((decl->spec).allocate & 1) != 0) {
        if ((sym->flags23 & 1) == 0) {
          pvVar1 = (decl->spec).segment;
          if (pvVar1 != (void *)0x0) {
            sym_set_segment(sym,pvVar1);
            return '\0';
          }
          sym->flags23 = sym->flags23 & 0xfe;
        }
        else {
          pvVar1 = (decl->spec).segment;
          pvVar5 = sym_segment_record(sym);
          if (pvVar5 != pvVar1) {
            uVar4 = 0x170;
            goto LAB_106378ff;
          }
        }
        return '\0';
      }
      if (((decl->spec).declspec & 2) == 0) {
        return '\0';
      }
      if ((sym->flags22 & 2) != 0) {
        return '\0';
      }
    }
    uVar4 = 0x172;
  }
  else if (uVar4 == 0x28) {
    decl->flags2c = decl->flags2c | 0x40;
    sym->flags2 = sym->flags2 | 1;
    diag_error(0x28,0x53,sym,decl->type,sym->type);
    return '\x01';
  }
LAB_106378ff:
  decl->flags2c = decl->flags2c | 0x40;
  sym->flags2 = sym->flags2 | 1;
  diag_error((short)uVar4,sym);
  return '\x01';
}

