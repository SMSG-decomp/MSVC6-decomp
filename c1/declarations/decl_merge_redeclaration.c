void __thiscall decl_merge_redeclaration(c1_declaration *decl,c1_symbol *sym)

{
  c1_u8 *pcVar1;
  c1_type *pcVar2;
  uint uVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_u8 cVar6;
  ushort uVar7;
  void *pvVar8;
  void *pvVar9;
  byte bVar10;
  char allocate_bit;
  
  bVar10 = (decl->spec).allocate & 1;
  if ((sym->flags23 & 1) == 0) {
    if (bVar10 != 0) {
      pvVar9 = (decl->spec).segment;
      if (pvVar9 == (void *)0x0) {
        sym->flags23 = sym->flags23 & 0xfe;
      }
      else {
LAB_10637789:
        sym_set_segment(sym,pvVar9);
      }
    }
  }
  else if ((bVar10 != 0) &&
          (pvVar9 = (decl->spec).segment, pvVar8 = sym_segment_record(sym), pvVar8 != pvVar9)) {
    pvVar9 = (decl->spec).segment;
    if (pvVar9 != (void *)0x0) goto LAB_10637789;
    sym->flags23 = sym->flags23 & 0xfe;
  }
  pcVar2 = decl->type;
  if (-1 < (char)pcVar2->code) goto LAB_106089f2;
  uVar7 = pcVar2->code & 0x8f;
  if (uVar7 != 0x81) {
    if (uVar7 == 0x83) {
      if (((pcVar2->extra).sym != (c1_symbol *)0x0) && ((sym->type->extra).sym == (c1_symbol *)0x0))
      {
        sym->type = pcVar2;
        sym->flags4 = sym->flags4 & 0xfe;
      }
      goto LAB_106089f2;
    }
    if (uVar7 != 0x85) goto LAB_106089f2;
  }
  if ((decl->flags2c & 8) != 0) {
    if ((sym->flags1 & 1) == 0) {
      sym->flags1 = sym->flags1 | 1;
    }
    else if ((sym->flags2 & 1) == 0) {
      diag_error(0x54,sym);
      sym->flags2 = sym->flags2 | 1;
    }
  }
LAB_106089f2:
  if (((sym->flags22 & 4) == 0) || (((decl->spec).declspec & 8) == 0)) {
    if (((sym->flags22 & 8) != 0) && (((decl->spec).declspec & 8) == 0)) {
      decl_warn_inconsistent_dll_linkage('\x04',decl,sym);
      return;
    }
  }
  else {
    diag_warning(1,0x111,sym);
    sym->storage = sym->storage & 0xf8 ^ 1;
    bVar10 = sym->flags22 & 0xf7;
    sym->flags22 = bVar10;
    sym->flags22 = bVar10 | 4;
  }
  if (((sym->storage & 7) == 1) && (((decl->spec).storage & 7) != 1)) {
    if ((sym->flags21 & 0x10) != 0) {
      pcVar1 = &(decl->spec).inlining;
      *pcVar1 = *pcVar1 | 0x10;
    }
    bVar10 = (decl->spec).declspec;
    bVar10 = (bVar10 ^ sym->flags22) & 4 ^ bVar10;
    (decl->spec).declspec = bVar10;
    (decl->spec).declspec = (bVar10 ^ sym->flags22) & 8 ^ bVar10;
    cVar4 = (decl->spec).inlining;
    cVar5 = (decl->spec).declspec;
    cVar6 = (decl->spec).allocate;
    sym->storage = (decl->spec).storage;
    sym->flags21 = cVar4;
    sym->flags22 = cVar5;
    sym->flags23 = cVar6;
  }
  if ((decl->flags2c & 8) != 0) {
    sym->flags1 = sym->flags1 | 1;
  }
  if ((decl->flags2c & 4) != 0) {
    sym->flags3 = sym->flags3 | 4;
  }
  uVar3._0_1_ = (decl->spec).storage;
  uVar3._1_1_ = (decl->spec).inlining;
  uVar3._2_1_ = (decl->spec).declspec;
  uVar3._3_1_ = (decl->spec).allocate;
  allocate_bit = '\0';
  if (((uVar3 & 0x100) != 0) && ((sym->flags21 & 1) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 1;
  }
  if (((uVar3 & 0x40) != 0) && ((sym->storage & 0x40) == 0)) {
    allocate_bit = '\x01';
    sym->storage = sym->storage | 0x40;
  }
  if (((uVar3 & 0x8000) != 0) && ((sym->flags21 & 0x80) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 0x80;
  }
  if (((uVar3 & 0x400000) != 0) && ((sym->flags22 & 0x40) == 0)) {
    allocate_bit = '\x01';
    sym->flags22 = sym->flags22 | 0x40;
  }
  if (((uVar3 & 0x1000) != 0) && ((sym->flags21 & 0x10) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 0x10;
  }
  if (((uVar3 & 0x10000) != 0) && ((sym->flags22 & 1) == 0)) {
    allocate_bit = '\x01';
    sym->flags22 = sym->flags22 | 1;
  }
  bVar10 = sym->flags22;
  if (((bVar10 ^ uVar3._2_1_) & 0xc) != 0) {
    if ((uVar3 & 0x40000) != 0) {
      sym->flags22 = bVar10 & 0xf7 | 4;
      sym->flags1 = sym->flags1 & 0xfd;
      return;
    }
    if ((uVar3 & 0x80000) != 0) {
      decl_merge_redeclaration_fragment(allocate_bit,bVar10,sym);
      return;
    }
  }
  if (allocate_bit != '\0') {
    sym->flags1 = sym->flags1 & 0xfd;
  }
  return;
}

