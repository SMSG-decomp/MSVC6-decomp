void __cdecl browse_record_fill(c1xx_browse_record *rec,int *sym)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if (g_use_instantiation_position == '\0') {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar1 = &g_line_map_cached_row;
      iVar2 = g_token_position;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
      iVar2 = g_token_position;
    }
  }
  else if (g_line_map_cached_row.position == g_region_source_position) {
    pcVar1 = &g_line_map_cached_row;
    iVar2 = g_region_source_position;
  }
  else {
    pcVar1 = pp_line_map_find_entry(&g_line_map,g_region_source_position);
    iVar2 = g_region_source_position;
  }
  iVar2 = (pcVar1->line - pcVar1->position) + iVar2;
  rec->line = iVar2;
  if (iVar2 != 0) {
switchD_10404ded_caseD_0:
    switch(rec->kind & 0xbf) {
    case 1:
      include_record_set_name(rec);
      return;
    case 3:
    case 0x19:
      browse_record_fill_definition(rec,(c1_symbol *)sym);
      return;
    case 4:
      browse_record_fill_reference(&rec->kind,(byte *)sym);
      return;
    case 0xb:
      browse_record_fill_member_reference(&rec->kind,(c1_symbol *)sym);
      break;
    case 0xc:
      browse_record_finish_base_class(rec,(c1_symbol *)sym);
      return;
    case 0xd:
      browse_record_fill_member_reference(&rec->kind,(c1_symbol *)sym);
      return;
    case 0x11:
      browse_record_finish_kind11(&rec->kind);
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
    goto switchD_10404ded_caseD_0;
  case 3:
  case 0x19:
    *(uint *)(sym[2] + 8) = *(uint *)(sym[2] + 8) | 0x200000;
    rec->kind = '\x14';
    return;
  case 0x13:
    *(uint *)(*sym + 8) = *(uint *)(*sym + 8) | 0x200000;
  default:
    rec->kind = '\x14';
    return;
  }
}

