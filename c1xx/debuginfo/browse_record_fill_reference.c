void __cdecl browse_record_fill_reference(byte *rec,byte *sym)

{
  c1_symbol *sym_00;
  byte bVar1;
  char cVar2;
  
  *rec = 0x14;
  if (((((g_browse_excluded_kinds[*sym & 0x1f] == 0) && (g_browse_skip_symbol != (c1_symbol *)sym))
       && ((sym[3] & 1) == 0)) &&
      ((bVar1 = *sym & 0x1f, bVar1 != 4 ||
       (((*(byte *)(*(int *)(sym + 0x24) + 0x3e) & 2) == 0 &&
        ((*(byte *)(*(int *)(sym + 0x24) + 0x3f) & 0x80) == 0)))))) &&
     ((g_compile_flags_c8 & 0x10000000) == 0)) {
    if (*(int *)(sym + 8) != g_name_this) {
      if (bVar1 == 0x12) {
        sym_00 = *(c1_symbol **)(**(int **)(sym + 0x14) + 8);
        bVar1 = sym_00->kind & 0x1f;
        if (((bVar1 != 0x10) && (bVar1 != 0x11)) && (bVar1 != 0x1b)) {
          cVar2 = sym_check_owner_scope((char *)rec,sym_00);
          if (cVar2 == '\0') {
            decl_position_set_symbol((c1xx_browse_record *)rec,sym_00);
            *rec = 4;
            return;
          }
        }
      }
      else {
        cVar2 = sym_check_owner_scope((char *)rec,(c1_symbol *)sym);
        if (cVar2 == '\0') {
          decl_position_set_symbol((c1xx_browse_record *)rec,(c1_symbol *)sym);
          *rec = 4;
        }
      }
    }
    return;
  }
  *rec = 0x14;
  return;
}

