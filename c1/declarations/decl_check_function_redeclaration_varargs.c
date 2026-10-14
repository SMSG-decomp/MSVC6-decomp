uint __thiscall decl_check_function_redeclaration_varargs(c1_declaration *decl,c1_symbol *sym)

{
  c1_symbol *unused;
  int iVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  void *pvVar4;
  void *pvVar5;
  byte bVar6;
  byte bVar7;
  c1_type *local_14;
  c1_type local_10;
  
  unused = sym;
  local_14 = sym->type;
  pcVar3 = decl->type;
  bVar7 = sym->flags23 & 1;
  if ((pcVar3 == (c1_type *)0x0) && (decl->context == 0xd)) {
    local_10.code = decl->tag_kind;
    local_10.base = (c1_type *)0x0;
    local_10.debug_index = 0;
    local_10.flags = 0;
    local_10.extra.sym = (c1_symbol *)0x0;
    pcVar3 = type_intern(&local_10);
  }
  if (pcVar3 == (c1_type *)0x0) {
    return 0;
  }
  if (((decl->spec).allocate & 1) == 0) {
    if (bVar7 != 0) {
      pvVar5 = sym_segment_record(sym);
      if (pvVar5 == (void *)0x0) {
        (decl->spec).segment = (void *)0x0;
        (decl->spec).allocate = (decl->spec).allocate & 0xfe;
      }
      else {
        (decl->spec).segment = pvVar5;
        (decl->spec).allocate = (decl->spec).allocate | 1;
      }
    }
  }
  else if (bVar7 == 0) {
    pvVar5 = (decl->spec).segment;
    if (pvVar5 == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym,pvVar5);
    }
  }
  else {
    pvVar5 = (decl->spec).segment;
    pvVar4 = sym_segment_record(sym);
    if (((pvVar4 != pvVar5) &&
        (pvVar5 = sym_segment_record(sym), (*(uint *)((int)pvVar5 + 0x1c) & 0xffffff) != 5)) &&
       ((*(uint *)((int)(decl->spec).segment + 0x1c) & 0xffffff) != 2)) {
      return 0x178;
    }
  }
  sym = (c1_symbol *)0x0;
  if (local_14 != pcVar3) {
    do {
      iVar1 = decl_function_flags_compatible(decl,local_14->flags,pcVar3->flags,(int)unused);
      if (iVar1 == 0) {
        return 0x175;
      }
      bVar7 = (byte)local_14->code;
      if (-1 < (char)bVar7) {
        if ((char)pcVar3->code < '\0') {
          return 0x28;
        }
        iVar1 = decl_warn_benign_type_redefinition(local_14->code,pcVar3->code);
        if (iVar1 != 0) {
          return -(uint)((local_14->extra).sym != (pcVar3->extra).sym) & 0x173;
        }
        return 0x173;
      }
      bVar6 = (byte)pcVar3->code;
      if (-1 < (char)bVar6) {
        return 0x28;
      }
      sym = (c1_symbol *)&sym->flags1;
      if (((bVar6 ^ bVar7) & 0x8f) != 0) {
        return 0x174;
      }
      if ((bVar7 & 0x8f) == 0x83) {
        if (((local_14->extra).sym != (pcVar3->extra).sym) &&
           ((sym != (c1_symbol *)0x1 ||
            (((local_14->extra).sym != (c1_symbol *)0x0 && ((pcVar3->extra).sym != (c1_symbol *)0x0)
             ))))) {
          return 0x171;
        }
      }
      else if (((bVar7 & 0x83) == 0x81) && ((decl->flags2c & 8) == 0)) {
        if ((char)((byte)(pcVar3->flags >> 8) ^ (byte)(local_14->flags >> 8)) < '\0') {
          if (g_ms_extensions == '\0') {
            diag_error(0x8e);
          }
          else {
            diag_warning(4,0x34);
          }
        }
        if (((local_14->extra).params != (pcVar3->extra).params) &&
           (pcVar2 = type_compare_function_prototypes
                               (unused->type,decl->type,'\x01',sym == (c1_symbol *)0x1,
                                CONCAT31((int3)((uint)(pcVar3->extra).params >> 8),
                                         (unused->kind & 0x1f) == 6)), sym == (c1_symbol *)0x1)) {
          unused->type = pcVar2;
        }
      }
      local_14 = local_14->base;
      pcVar3 = pcVar3->base;
    } while (local_14 != pcVar3);
  }
  return 0;
}

