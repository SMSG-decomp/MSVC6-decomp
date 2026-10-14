void __cdecl
decl_warn_inconsistent_dll_linkage(c1_u8 dllexport_bit,c1_declaration *decl,c1_symbol *sym)

{
  c1_u8 *pcVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  char allocate_bit;
  byte bVar5;
  uint uStack00000010;
  
  if ((((((decl->spec).storage & 7) != 3) && (((decl->spec).inlining & 1) == 0)) &&
      ((decl->flags2c & 0x40) == 0)) && ((sym->flags2 & 1) == 0)) {
    diag_warning(1,0x111,sym);
    sym->storage = sym->storage & 0xf8 ^ 1;
    bVar5 = sym->flags22 & 0xf7;
    sym->flags22 = bVar5;
    sym->flags22 = bVar5 | dllexport_bit;
  }
  if (((sym->storage & 7) == 1) && (((decl->spec).storage & 7) != 1)) {
    if ((sym->flags21 & 0x10) != 0) {
      pcVar1 = &(decl->spec).inlining;
      *pcVar1 = *pcVar1 | 0x10;
    }
    bVar5 = (decl->spec).declspec;
    bVar5 = (bVar5 ^ sym->flags22) & dllexport_bit ^ bVar5;
    (decl->spec).declspec = bVar5;
    (decl->spec).declspec = (bVar5 ^ sym->flags22) & 8 ^ bVar5;
    cVar2 = (decl->spec).inlining;
    cVar3 = (decl->spec).declspec;
    cVar4 = (decl->spec).allocate;
    sym->storage = (decl->spec).storage;
    sym->flags21 = cVar2;
    sym->flags22 = cVar3;
    sym->flags23 = cVar4;
  }
  if ((decl->flags2c & 8) != 0) {
    sym->flags1 = sym->flags1 | 1;
  }
  if ((decl->flags2c & dllexport_bit) != 0) {
    sym->flags3 = sym->flags3 | dllexport_bit;
  }
  uStack00000010._0_1_ = (decl->spec).storage;
  uStack00000010._1_1_ = (decl->spec).inlining;
  uStack00000010._2_1_ = (decl->spec).declspec;
  uStack00000010._3_1_ = (decl->spec).allocate;
  allocate_bit = '\0';
  if (((uStack00000010 & 0x100) != 0) && ((sym->flags21 & 1) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 1;
  }
  if (((uStack00000010 & 0x40) != 0) && ((sym->storage & 0x40) == 0)) {
    allocate_bit = '\x01';
    sym->storage = sym->storage | 0x40;
  }
  if (((uStack00000010 & 0x8000) != 0) && ((sym->flags21 & 0x80) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 0x80;
  }
  if (((uStack00000010 & 0x400000) != 0) && ((sym->flags22 & 0x40) == 0)) {
    allocate_bit = '\x01';
    sym->flags22 = sym->flags22 | 0x40;
  }
  if (((uStack00000010 & 0x1000) != 0) && ((sym->flags21 & 0x10) == 0)) {
    allocate_bit = '\x01';
    sym->flags21 = sym->flags21 | 0x10;
  }
  if (((uStack00000010 & 0x10000) != 0) && ((sym->flags22 & 1) == 0)) {
    allocate_bit = '\x01';
    sym->flags22 = sym->flags22 | 1;
  }
  bVar5 = sym->flags22;
  if (((bVar5 ^ uStack00000010._2_1_) & 0xc) != 0) {
    if ((uStack00000010 & 0x40000) != 0) {
      sym->flags22 = bVar5 & 0xf7 | 4;
      sym->flags1 = sym->flags1 & 0xfd;
      return;
    }
    if ((uStack00000010 & 0x80000) != 0) {
      decl_merge_redeclaration_fragment(allocate_bit,bVar5,sym);
      return;
    }
  }
  if (allocate_bit != '\0') {
    sym->flags1 = sym->flags1 & 0xfd;
  }
  return;
}

