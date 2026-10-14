void __cdecl browse_record_fill(c1_browse_record *rec,c1_symbol *sym)

{
  fe_line_map_row *pfVar1;
  int iVar2;
  
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar1 = &g_line_map_cached_row;
  }
  else {
    pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  iVar2 = g_token_position + (pfVar1->line - pfVar1->position);
  rec->line = iVar2;
  if (iVar2 != 0) {
switchD_10621d3d_caseD_0:
    switch(rec->kind & 0xbf) {
    case 1:
      browse_record_set_file(rec);
      return;
    case 3:
    case 0x19:
      browse_record_fill_definition(rec,sym);
      return;
    case 4:
      browse_record_fill_reference(rec,sym);
      return;
    case 0xb:
      browse_record_fill_owner(rec,sym);
      break;
    case 0x11:
      browse_record_finish_kind11(rec);
      return;
    case 0x12:
      browse_record_fill_kind12(rec,(fe_macro *)sym);
      return;
    case 0x13:
      browse_record_finish_kind13(rec,(fe_macro *)sym);
      return;
    }
    return;
  }
  switch(rec->kind & 0xbf) {
  case 0:
  case 1:
  case 10:
  case 0xe:
  case 0x11:
  case 0x16:
    goto switchD_10621d3d_caseD_0;
  case 3:
  case 0x19:
    sym->name->flags = sym->name->flags | 0x200000;
    rec->kind = '\x14';
    return;
  case 0x13:
    *(uint *)(*(int *)sym + 8) = *(uint *)(*(int *)sym + 8) | 0x200000;
  default:
    rec->kind = '\x14';
    return;
  }
}

